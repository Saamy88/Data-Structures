// FILE: IntStore.cpp
//       Implementation file for the IntStore class
//       (See IntStore.h for documentation.)
// INVARIANT for the IntStore class:
// (1) Distinct values of the IntStore are stored in a 1-D,
//     compile-time array whose size is IntStore::MAX_SIZE;
//     the member variable data references the array.
// (2) The # of occurrences associated with each distinct value
//     (stored in data) is stored in the corresponding element
//     of a parallel 1-D, compile-time array whose size is also
//     IntStore::MAX_SIZE; the member variable freq references
//     the array.
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
//     from data[used] through data[IntStore::MAX_SIZE - 1], and
//     from freq[used] through freq[IntStore::MAX_SIZE - 1].

#include <iostream>
#include "IntStore.h"
// include any other relevant header files here
using namespace std;

IntStore::IntStore() : used(0)
{

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
   copies = 1;
   bool repetition = false;

   if (used == MAX_SIZE)
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
			   data[used] = item;
			   freq[used] = copies;
			   used++;
		   }
	   }

	   return true;
   }
}

int IntStore::add(const IntStore& addend)
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
			
			if( used < MAX_SIZE )
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
	bool flag = false;;
	for(int i = 0; i < used; i++)
	{
		if(target==data[i])
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
		if(target==data[i])
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

bool similar(const IntStore& is1, const IntStore& is2)
{
	IntStore temp1 = is1;
	IntStore temp2 = is2;
	int index = temp1.countDistinct();
	int similarities = 0;
	int test[10],
	    test2[10];

	if(!(temp1.countDistinct() == temp2.countDistinct()))
		return false;

	for(int i = 0; i < index; i++)
	{
		test[i] = temp1.valAt(i + 1);
		test2[i] = temp2.valAt(i + 1);
	}

	for(int i = 0; i < index; i++)
	{
		for(int j = 0; j < index; j++)
		{
			if(test[i] == test2[j])
				similarities++;
		}
	}

	if (index == similarities)
		return true;
	else
		return false;

}
