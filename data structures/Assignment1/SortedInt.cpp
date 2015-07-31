// FILE: SortedInt.cpp
//       Implementation file for the SortedInt class
//       (See SortedInt.h for documentation.)
// INVARIANT for the SortedInt class:
// (1) Items of the SortedInt are stored in a 1D compile-time
//     (fixed-sized) array of integers whose size is MAX_SIZE.
//     the member variable data references the array.
// (2) # of items the SortedInt currently contains is stored
//     in the member variable used.
// (3) Items of SortedInt are stored sorted in non-decreasing
//     order from data[0] through data[used - 1].
// (4) We DON'T CARE what is stored in any of the array elements
//     from data[used] and beyond (i.e. values in these elements
//     are NOT (re)set in any way).

#include <iostream>
#include "SortedInt.h"
#include <cassert>
// include any other relevant header files here
using namespace std;

SortedInt::SortedInt() : used (0)
{

}

bool SortedInt::isEmpty() const
{
	if (used == 0)
	   return true;
	else
	   return false;
}

int SortedInt::size() const
{
	return used;
}

int SortedInt::valAt(int position) const
{
	assert (size() != 0);
	assert(position >= 1);
	assert(position <= size());
	  return data[position - 1];
}

int SortedInt::findMin() const
{
	assert (used != 0);
	return data[0];
}

int SortedInt::findMax() const
{
	assert (used != 0);
	   return data[used - 1];
}

double SortedInt::findMed() const
{
	double median = used % 2;

	if(median == 0)
	{
		double lower, upper;

		lower = data[used / 2 - 1];
		upper = data[used / 2];

		median = (lower + upper) * .5;
	}
	else
	{
		median = data[used / 2];
	}

	return median;
}

double SortedInt::findAvg() const
{
	double sum = 0;
	double average;

	for (int i = 0; i < used; ++i)
		sum += data[i];

	average = (sum / used);

	return average;
}

int SortedInt::findFreq(int target) const
{
	int count = 0;
	for (int i = 0; i < used; ++i)
	{
		if (data[i] == target)
	  	++count;
	}

	return count;
}

bool SortedInt::equal(const SortedInt& other) const
{
	if ( used != other.used) return false;
	for (int i = 0; i <  used; ++i)
		if ( data[i] != other.data[i] ) return false;

	return true;
}

void SortedInt::reset()
{
	used = 0;
}

void SortedInt::insert(int newInt)
{
	assert (used < MAX_SIZE);

	int index = used;

	while ( index > 0 && newInt < data[index - 1] )
	{
		data[index] = data[index - 1];

		--index;
	}

	data[index] = newInt;
	used++;
}

int SortedInt::delMin()
{
	int lowest = data[0];
	int removed = 0;

	for(int i = 0; i < used; ++i)
	{
		if(data[i] == lowest)
		{
			removed += 1;
			for(int x = 0; x < used - 1; ++x)
			{
				data[x] = data[x + 1];
			}
			used -= 1;
			i = -1;
		}
	}

	return removed; // dummy value returned
}

int SortedInt::delMax()
{
	int highest = data[used - 1];
	int removed = 0;

	for(int i = 0; i < used; ++i)
	{
		if(data[i] == highest)
		{
			removed += 1;
		}
	}

	used -= removed;

	return removed;
}

bool SortedInt::delOne(int target)
{
	for ( int i = 0; i < used; ++i)
	{
		if (data[i] == target)
		{
			for (; i < used - 1; ++i)
	            data[i] = data[i + 1];
	    	 --used;
	         return true;
	     }
	}

	return false;
}

int SortedInt::delAll(int target)
{
	int removed = 0;

	for(int i = 0; i < used; ++i)
		if (data[i] == target)
		{
			removed += 1;
			for(int x = i; x < used - 1; ++x)
			{
				data[x] = data[x + 1];
			}
			i = -1;
			used -= 1;
		}

	return removed; // dummy value returned
}

void SortedInt::add(SortedInt addend)
{
	assert ( used + addend.used  <= MAX_SIZE);

	for (int i = 0; i < addend.used; ++i)
		insert(addend.data[i]);
}

SortedInt combine(const SortedInt& s1, const SortedInt& s2)
{
	assert (( s1.size() + s2.size() ) <= SortedInt::MAX_SIZE );
	SortedInt result;

	int i = 1,
	    j = 1,
	    c = 0;
	int s1Size = s1.size();
	int s2Size = s2.size();

	while( i <= s1Size && j <= s2Size )
	{
		if( s1.valAt(i) < s2.valAt(j) )
		{
	    	result.insert(s1.valAt(i));
	   	    ++i;
	    }
	    else
	    {
	    	result.insert(s2.valAt(j));
	    	++j;
	    }

	   	++c;
	}

	while( i <= s1Size )
	{
		result.insert(s1.valAt(i));
		++i;
		++c;
	}

	while( j <= s2Size )
	{
		result.insert(s2.valAt(j));
		++j;
		++c;
	}

	return result;
}
