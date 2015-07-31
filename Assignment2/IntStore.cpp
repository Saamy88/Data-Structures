// FILE: IntStore.cpp
//       Implementation file for the IntStore class
//       (See IntStore.h for documentation.)
// INVARIANT for the IntStore class:
// (1) Distinct values of the IntStore are stored in a 1-D,
//     dynamic array whose size is store in member variable
//     capacity; member variable data references the array.
// (2) The # of occurrences associated with each distinct value
//     (stored in data) is stored in the corresponding element
//     of a parallel 1-D, dynamic array whose size is also
//     stored in member variable capacity (i.e., data and freq
//     are of the same size); member variable freq references the
//     array.
// (3) The distinct value added the earliest is stored in data[0],
//     the distinct value that is added the 2nd-earliest is stored
//     in data[1], and so on.
// (4) The # of distinct values the IntStore currently contains is
//     stored in the member variable used.
// (5) Except when the IntStore is empty (used == 0), ALL elements
//     of data from data[0] until data[used - 1] contain relevant
//     distinct-value data and ALL elements of freq from freq[0]
//     until freq[used - 1] contain relevant occurrence data;
//     the # of occurrences of data[i] is stored in freq[i] (i.e.,
//     data and freq are parallel arrays).
// (6) We DON'T care what is stored in any of the array elements
//     from data[used] through data[capacity - 1], and
//     from freq[used] through freq[capacity - 1].
//
// DOCUMENTATION for private member (helper) function:
//   void resize(int new_capacity)
//     Pre:  (none)
//           Note: Recall that one of the things a constructor
//                 has to do is to make sure that the object
//                 created BEGINS to be consistent with the
//                 class invariant. Thus, resize() should not
//                 be used within constructors unless it is at
//                 a point where the class invariant has already
//                 been made to hold true.
//     Post: The capacity (sizes of the dynamic arrays) of the
//           invoking IntStore is changed to new_capacity...
//           ...EXCEPT when new_capacity would not allow the
//           invoking IntStore to preserve current contents (i.e.,
//           value for new_capacity is invalid or too low for the
//           IntStore to represent the existing collection),...
//           ...IN WHICH CASE the capacity of the invoking IntStore
//           is set to "the minimum that is needed" (which is the
//           same as "exactly what is needed") to preserve current
//           contents...
//           ...BUT if "exactly what is needed" is 0 (i.e. existing
//           collection is empty) then the capacity should be
//           further adjusted to 1 or DEFAULT_CAPACITY (since we
//           don't want to request dynamic arrays of size 0).
//           The collection represented by the invoking IntStore
//           remains unchanged.
//           If reallocation of dynamic array is unsuccessful, an
//           error message to the effect is displayed and the
//           program unconditionally terminated.

#include "IntStore.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

void IntStore::resize(int new_capacity)
{
	if (new_capacity < used)
		new_capacity = used;
	if (new_capacity < 1)
		new_capacity = 1;

	capacity = new_capacity;

	int* newData = new int[capacity];
	int* newFreq = new int[capacity];

	for(int i = 0; i < used; ++i)
	{
		newData[i] = data[i];
		newFreq[i] = freq[i];
	}

	delete [] data;
	delete [] freq;
	data = newData;
	freq = newFreq;
}

IntStore::IntStore(int init_capacity) : capacity(init_capacity), used(0)
{
   if (capacity < 1)
      capacity = DEFAULT_CAPACITY;
	
   data = new int[capacity];
   freq = new int[capacity];
}

IntStore::IntStore(const IntStore& src) : capacity(src.capacity), used(src.used)
{
   data = new int[capacity];
   freq = new int[capacity];
	
	for(int i = 0; i < used; ++i)
	{
		data[i] = src.data[i];
		freq[i] = src.freq[i];
	}
}

IntStore::~IntStore()
{
   delete [] data;
   delete [] freq;
}

IntStore& IntStore::operator=(const IntStore& rhs)
{
   if(this != &rhs)
	{
		int* newData = new int[rhs.capacity];
		int* newFreq = new int[rhs.capacity]; 
		
		for(int i = 0; i < rhs.used; ++i)
		{
			newData[i] = rhs.data[i];
			newFreq[i] = rhs.freq[i];
		}
		
		delete [] data;
		delete [] freq; 
		data = newData; 
		freq = newFreq;
		capacity = rhs.capacity;
		used = rhs.used;
	}
   return *this;
}

bool IntStore::empty() const
{
   if(used == 0)
		return true;
	else 
		return false;
}

int IntStore::countDistinct() const
{
   return used;
}

int IntStore::countAll() const
{
	int count = 0;

	for(int i = 0; i < used; i++)
		count = count + freq[i];

	return count;
}

int IntStore::countTarget(int target) const
{
	if(IntStore::empty())
	        return 0;

	for(int i = 0; i < used; ++i)
		if(target == data[i])
			return freq[i];

	return 0;

}

int IntStore::valAt(int pos) const
{
	if(IntStore::empty())
		return 0;
	else
		return data[pos - 1];
}

int IntStore::freqAt(int pos) const
{
	if(IntStore::empty())
		return 0;
	else
		return freq[pos - 1];
}

double IntStore::avg() const
{
	if(IntStore::empty())
		return 0;

	double sum = 0.0;
    double average = 0.0;

    for(int i = 0; i < used; i++)
    	sum = sum + (data[i] * freq[i]);

    average = sum / IntStore::countAll();

    return average;
}

void IntStore::reset()
{
   used = 0;
}

bool IntStore::add(int item, int copies)
{
   if(copies < 0)
	  return false;

   copies = 1;
   bool repetition = false;

   if (used == capacity)
   {
	   for(int i = 0; i < used; i++)
	   {
		   if(item == data[i])
		   {
			   repetition = true;
		       freq[i] = freq[i] + copies;
               return true;
         }
      }

	   if(repetition == false)
	   {
		   resize( int(1.5*capacity) + 1 );
	       data[used] = item;
	       freq[used] = copies;
	       used++;
	       return true;
	   }
	   return false;
    }
   else
   {
	   if(used == 0)
	   {
		   data[used] = item;
		   freq[used] = copies;
         used++;
       }
       else
       {
    	   for(int i = 0; i < used; i++)
    	   {
    		   if(item == data[i])
    		   {
    			   repetition = true;
    			   freq[i] = freq[i] + copies;
               break;
            }
         }
			
		   if(repetition == false)
		   {
			   resize( int(1.5*capacity) + 1 );
		       data[used] = item;
		       freq[used] = copies;
		       used++;
		       return true;
		   }
       }
    }

   return true;
}

int IntStore::operator+=(const IntStore& addend)
{
	bool repetition = false;
	int addition = 0;

	for(int i = 0; i < addend.used; i++)
	{	
		repetition = false;
	    int num = 0;

	    for(int j = 0; j < used; j++)
	    {
	    	if(addend.data[i] == data[j])
	    	{
				addition++;
	            num = freq[j] + addend.freq[i];
	            freq[j] = num;
	            repetition = true;
	            break;
	      }
	    }

	    if( repetition == false )
	    {
			resize( int(1.5*capacity) + 1 );
			
	    	if( used < capacity )
	    	{
	    		data[used] = addend.data[i];
	    		freq[used] = addend.freq[i];
	            used++;
	            addition++;
	        }
	    }
	}

	return addition;
}

bool IntStore::remOne(int target)
{
	bool flag = false;

	for(int i = 0; i < used; i++)
	{
		if(target == data[i])
	    {
			if(freq[i] > 1)
	        {
				freq[i] = freq[i] - 1;
	            return true;

	        }
			else if(i == used - 1 )
	        {
				used--;
	            return true;
	        }
	        else if(freq[i] == 1)
	        {
	        	used--;
	        	for(int y = i; y < used; y++)
	            {
	        		data[y] = data[y + 1];
	                freq[y] = freq[y + 1];
	            }
	        	flag = true;
	        }
	    }

	}

	if (flag == false)
		return false;
	else
		return true;
}

int IntStore::remAll(int target)
{
	int removed = 0;

	for(int i = 0; i < used; i++)
	{
		if(target == data[i])
		{
			removed = freq[i];
			used--;
			for(int y = i; y < used; y++)
			{
				data[y] = data[y + 1];
	            freq[y] = freq[y + 1];
	        }
	    }
	}

	return removed;
}

bool operator==(const IntStore& is1, const IntStore& is2)
{
	IntStore temp1 = is1;
    IntStore temp2 = is2;
	int index = temp1.countDistinct();
	int similarities = 0;
	int test1[temp1.countDistinct()],
		test2[temp2.countDistinct()];

	if(!(temp1.countDistinct() == temp2.countDistinct()))
	        return false;

    for(int i = 0; i < index; i++)
	{
    	test1[i] = temp1.valAt(i + 1);
	    test2[i] = temp2.valAt(i + 1);
	}

    for(int i = 0; i < index; i++)
	{
    	for(int j = 0; j < index; j++)
	    {
    		if(test1[i] == test2[j])
    			similarities++;
	    }
	}

	if (index == similarities)
		return true;
	else
		return false;
}
