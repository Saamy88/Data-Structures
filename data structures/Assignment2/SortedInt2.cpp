// FILE: SortedInt2.cpp
//       Implementation file for the SortedInt2 class
//       (See SortedInt2.h for documentation.)
// INVARIANT for the SortedInt2 class:
// (1) Entries of the SortedInt2 are stored in a one-dimensional,
//     run-time (dynamic) array of integers referenced by the
//     member variable data (i.e., the starting address of the
//     the array is stored in data); the capacity of the array
//     is stored in the member variable capacity.
// (2) # of entries the SortedInt2 currently contains is stored
//     in the member variable used.
// (3) Entries of SortedInt2 are stored sorted in non-decreasing
//     order from data[0] through data[used - 1].
// (4) We DON'T care what is stored in any of the array elements
//     from data[used] through data[capacity - 1].
//
// DOCUMENTATION for private member (helper) function:
//   void resize(int new_capacity)
//     Pre:  (none)
//     Post: The capacity (size of the dynamic array) of the
//           invoking SortedInt2 is changed to new_capacity. The
//           collection represented by the invoking SortedInt2
//           remains unchanged.
//     Note: For new capacity to be valid, it should not be less
//           than used (so that the existing collection can still
//           be represented) AND should be at least 1 (0 is not
//           good because we don't want to request a dynamic array
//           of size 0). Caller-supplied new_capacity is checked
//           and adjusted (where necessary) to ensure valid in two
//           stages as follows:
//           Stage 1: set new_capacity to used if it is < used
//           Stage 2: if new_capacity < 1, set it to 1
//     Xtra: With the above, resize can actually be used to shrink
//           the size of the dynamic array (to either used or 1,
//           whichever is the greater) used by a SortedInt2; for
//           such a case, one can simply call resize with any
//           invalid new_capacity (say 0). However, using resize
//           as such should be limited to situations where dynamic
//           memory usage is critical (because resizing is really
//           a time-consuming operation).
//

#include "SortedInt2.h"
#include <iostream>
#include <cassert>

using namespace std;

void SortedInt2::resize(int new_capacity)
{
	if (new_capacity < 1)
		new_capacity = DEFAULT_CAPACITY;
	capacity = new_capacity;

	int * newData = new int[(int(1.5 * new_capacity) + 1)];

	for (int i = 0; i < used; ++i)
		newData[i] = data[i];

	delete [] data;
	data = newData;
}

SortedInt2::SortedInt2(int init_capacity) : capacity(init_capacity),
		used (0)
{
	if (capacity < 1)
		capacity = DEFAULT_CAPACITY;
	data = new int[capacity];
}

SortedInt2::SortedInt2(const SortedInt2& src) : capacity(src.capacity),
		used(src.used)
{
	data = new int[capacity];
	for (int i = 0; i < used; ++i)
		data[i] = src.data[i];
}

SortedInt2::~SortedInt2()
{
	delete [] data;
}

bool SortedInt2::isEmpty() const
{
	return used == 0;
}

int SortedInt2::size() const
{
	return used;
}

int SortedInt2::valAt(int position) const
{
	assert (size() != 0);
	assert(position >= 1);
	assert(position <= size());

	return data[position - 1];
}

int SortedInt2::findMin() const
{
	assert (size() != 0);

	return data[0];
}

int SortedInt2::findMax() const
{
	assert (size() != 0);

	return data[used - 1];
}

double SortedInt2::findMed() const
{
	assert (size() != 0);

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

double SortedInt2::findAvg() const
{
	assert (size() != 0);

	double sum = 0;
	double average;

	for (int i = 0; i < used; ++i)
		sum += data[i];

	average = (sum / used);

	return average;
}

int SortedInt2::findFreq(int target) const
{
	int count = 0;
	for (int i = 0; i < used; ++i)
	{
		if (data[i] == target)
			++count;
	}
	return count;
}

SortedInt2& SortedInt2::operator=(const SortedInt2& rhs)
{
	if (this != &rhs)
	{
		int* newData = new int[rhs.capacity];
		for (int i = 0; i < rhs.used; ++i)
			newData[i] = rhs.data[i];
		delete [] data;
		data = newData;
		capacity = rhs.capacity;
		used = rhs.used;
	}
	return *this;
}

void SortedInt2::reset()
{
	used = 0;
}

void SortedInt2::insert(int newInt)
{
	int index = used;

	if (used > capacity)
		resize(used);
	while ( index > 0 && newInt < data[index - 1] )
	{
		data[index] = data[index - 1];

		--index;
	}

	data[index] = newInt;
	used++;
}

int SortedInt2::delMin()
{
	assert (size() != 0);

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

	return removed;
}

int SortedInt2::delMax()
{
	assert (size() != 0);

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

bool SortedInt2::delOne(int target)
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

int SortedInt2::delAll(int target)
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

	return removed;
}

void SortedInt2::operator+=(SortedInt2 addend)
{
	if (capacity < used + addend.used)
	{
		int new_cap = used + addend.used;
		resize(new_cap);
	}
	for (int i = 0; i < addend.used; ++i)
		insert(addend.data[i]);
}

bool operator==(const SortedInt2& lhs, const SortedInt2& rhs)
{
	if (lhs.used != rhs.used)
		return false;
	for (int i = 0; i < lhs.used; ++i)
		if (lhs.data[i] != rhs.data[i])
			return false;
	return true;
}

SortedInt2 operator+(const SortedInt2& s1, const SortedInt2& s2)
{
	SortedInt2 result;
	result.reset();

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
