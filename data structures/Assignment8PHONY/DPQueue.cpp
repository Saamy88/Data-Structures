// FILE: DPQueue.cpp
// IMPLEMENTS: p_queue (see DPQueue.h for documentation.)
//
// INVARIANT for the p_queue class:
//   1. The number of items in the p_queue is stored in the member
//      variable used.
//   2. The items themselves are stored in a dynamic array (partially
//      filled in general) organized to follow the usual heap storage
//      rules.
//      2.1 The member variable heap stores the starting address
//          of the array (i.e., heap is the array's name). Thus,
//          the items in the p_queue are stored in the elements
//          heap[0] through heap[used - 1].
//      2.2 The member variable capacity stores the current size of
//          the dynamic array (i.e., capacity is the maximum number
//          of items the array currently can accommodate).
//          NOTE: The size of the dynamic array (thus capacity) can
//                be resized up or down where needed or appropriate
//                by calling resize(...).
// NOTE: Private helper functions are implemented at the bottom of
// this file along with their precondition/postcondition contracts.

#include <cassert>   // provides assert function
#include <iostream>  // provides cin, cout
#include <iomanip>   // provides setw
#include <cmath>     // provides log2
#include "DPQueue.h"

using namespace std;

namespace cs3358Spring2014Assign08
{
   // EXTRA MEMBER FUNCTIONS FOR DEBUG PRINTING
   void p_queue::print_tree(const char message[], size_type i) const
   // Pre:  (none)
   // Post: If the message is non-empty, it has first been written to
   //       cout. After that, the portion of the heap with root at
   //       node i has been written to the screen. Each node's data
   //       is indented 4*d, where d is the depth of the node.
   //       NOTE: The default argument for message is the empty string,
   //             and the default argument for i is zero. For example,
   //             to print the entire tree of a p_queue p, with a
   //             message of "The tree:", you can call:
   //                p.print_tree("The tree:");
   //             This call uses the default argument i=0, which prints
   //             the whole tree.
   {
      const char NO_MESSAGE[] = "";
      size_type depth;

      if (message[0] != '\0')
         cout << message << endl;

      if (i >= used)
         cout << "(EMPTY)" << endl;
      else
      {
         depth = size_type( log( double(i+1) ) / log(2.0) + 0.1 );
         if (2*i + 2 < used)
            print_tree(NO_MESSAGE, 2*i + 2);
         cout << setw(depth*3) << "";
         cout << heap[i].data;
         cout << '(' << heap[i].priority << ')' << endl;
         if (2*i + 1 < used)
            print_tree(NO_MESSAGE, 2*i + 1);
      }
   }

   void p_queue::print_array(const char message[]) const
   // Pre:  (none)
   // Post: If the message is non-empty, it has first been written to
   //       cout. After that, the contents of the array representing
   //       the current heap has been written to cout in one line with
   //       values separated one from another with a space.
   //       NOTE: The default argument for message is the empty string.
   {
      if (message[0] != '\0')
         cout << message << endl;

      if (used == 0)
         cout << "(EMPTY)" << endl;
      else
         for (size_type i = 0; i < used; i++)
            cout << heap[i].data << ' ';
   }

   // CONSTRUCTORS AND DESTRUCTOR

   p_queue::p_queue()
   {
	  used = 0;
	  capacity = 0;
	  heap = new ItemType [capacity];
   }

   p_queue::p_queue(const p_queue& src)
   {
	  used = src.used;
	  capacity = src.capacity;
	  heap = new ItemType [capacity];

	  for( size_type i = 0; i < size(); ++i)
	  {
	 	 heap[i].data = src.heap[i].data;
	 	 heap[i].priority = src.heap[i].priority;
	  }
   }

   p_queue::~p_queue()
   {
	   cout << "Before delete" << endl;
      delete [] heap;
      cout <<" After delete" << endl;
   }

   // MODIFICATION MEMBER FUNCTIONS
   p_queue& p_queue::operator=(const p_queue& rhs)
   {
//      if (this != &rhs)
//	  {
//		 ItemType* newData = new ItemType[rhs.capacity];
//		 for (size_type i = 0; i < rhs.used; ++i)
//		 {
//			newData[i].data = rhs.heap[i].data;
//			newData[i].priority = rhs.heap->priority;
//		 }
//		 delete [] heap;
//		 heap = newData;
//		 capacity = rhs.capacity;
//		 used = rhs.used;
//	  }
//      return *this;
  	if (this != &rhs)
  	{
  		ItemType* newHeap = new ItemType[rhs.capacity];
  		for (size_type i = 0; i < rhs.used; ++i)
  			newHeap[i] = rhs.heap[i];
  		delete [] heap;
  		heap = newHeap;
  		capacity = rhs.capacity;
  		used = rhs.used;
  	}
  	return *this;
   }

   void p_queue::push(const value_type& entry, size_type priority)
   {

		if(size() == capacity)
		{
			resize(2*capacity);
		}

		heap[used].priority = priority;
		heap[used].data = entry;

		used++;
		size_type j;

		for(size_type i = used-1; (i>0) && (heap[i].priority > parent_priority(i)); i = j)
		{
			j = parent_index(i);
			swap_with_parent(i);
		}
   }

   void p_queue::pop()
   {
		assert(size() > 0);

		if(size() == 1)
			--used;
		else
		{
			if(size() <= 2)
			{
				heap[0].data = heap[used-1].data;
				heap[0].priority = heap[used-1].priority;
				--used;
			}

			else
			{
				heap[0].data = heap[used-1].data;
				heap[0].priority = heap[used-1].priority;
				--used;
				size_type j;

				for(size_type i = 0; !(is_leaf(i)) && (heap[i].priority < big_child_priority(i)); i = j)
				{
					j = big_child_index(i);
					swap_with_parent(big_child_index(i));
				}
			}
		}
   }

   // CONSTANT MEMBER FUNCTIONS

   p_queue::size_type p_queue::size() const
   {
      return used; // dummy return value
   }

   bool p_queue::empty() const
   {
      return used == 0; // dummy return value
   }

   p_queue::value_type p_queue::front() const
   {
	  assert(size() > 0);
      return heap[0].data;//value_type(); // dummy return value
   }

   // PRIVATE HELPER FUNCTIONS
   void p_queue::resize(size_type new_capacity)
   // Pre:  (none)
   // Post: The size of the dynamic array pointed to by heap (thus
   //       the capacity of the p_queue) has been resized up or down
   //       to new_capacity, but never less than used (to prevent
   //       loss of existing data).
   //       NOTE: All existing items in the p_queue are preserved and
   //             used remains unchanged.
   {
	  if(new_capacity < used)
	     new_capacity = used;
	  if (new_capacity < 1)
	  	 new_capacity = 1;
	  capacity = new_capacity;

	  ItemType* newData = new ItemType[capacity];

	  	for (size_type i = 0; i < used; ++i)
	  		newData[i] = heap[i];

	  	delete [] heap;

	  	heap = newData;
   }

   bool p_queue::is_leaf(size_type i) const
   // Pre:  (i < used)
   // Post: If the item at heap[i] has no children, true has been
   //       returned, otherwise false has been returned.
   {
		assert(i < used);

		if(i >= used/2 || i == (used-1))
			return true;

		return false;
   }

   p_queue::size_type
   p_queue::parent_index(size_type i) const
   // Pre:  (i > 0) && (i < used)
   // Post: The index of "the parent of the item at heap[i]" has
   //       been returned.
   {
		assert(i > 0);
		assert(i < used);

		return (i-1)/2;
   }

   p_queue::size_type
   p_queue::parent_priority(size_type i) const
   // Pre:  (i > 0) && (i < used)
   // Post: The priority of "the parent of the item at heap[i]" has
   //       been returned.
   {
		assert(i > 0);
		assert(i < used);

		return heap[parent_index(i)].priority;
   }

   p_queue::size_type
   p_queue::big_child_index(size_type i) const
   // Pre:  is_leaf(i) returns false
   // Post: The index of "the bigger child of the item at heap[i]"
   //       has been returned.
   //       (The bigger child is the one whose priority is no smaller
   //       than that of the other child, if there is one.)
   {
		assert(is_leaf(i) == false);

		size_type left = 2*i +1;
		size_type right = 2*i +2;
		if(heap[left].priority > heap[right].priority)
			return left;
		else
			return right;
   }

   p_queue::size_type
   p_queue::big_child_priority(size_type i) const
   // Pre:  is_leaf(i) returns false
   // Post: The priority of "the bigger child of the item at heap[i]"
   //       has been returned.
   //       (The bigger child is the one whose priority is no smaller
   //       than that of the other child, if there is one.)
   {
		assert(is_leaf(i) == false);

		size_type left = 2*i +1;
		size_type right = 2*i +2;
		if(heap[left].priority > heap[right].priority)
			return heap[left].priority;
		else
			return heap[right].priority;
   }

   void p_queue::swap_with_parent(size_type i)
   // Pre:  (i > 0) && (i < used)
   // Post: The item at heap[i] has been swapped with its parent.
   {
		assert(i > 0);
		assert(i < used);

		value_type tempD;
		size_type tempP;

		tempD = heap[i].data;
		tempP = heap[i].priority;

		heap[i].data = heap[parent_index(i)].data;
		heap[i].priority = heap[parent_index(i)].priority;

		heap[parent_index(i)].data = tempD;
		heap[parent_index(i)].priority = tempP;
   }
}

