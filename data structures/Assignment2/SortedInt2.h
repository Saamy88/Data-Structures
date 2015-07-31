// FILE: SortedInt2.h - header file for SortedInt2 class
//
// CONSTANT
//   static const int DEFAULT_CAPACITY = ____
//     SortedInt2::DEFAULT_CAPACITY is the default highest # of
//     entries that a SortedInt2 initially can accommodate; at
//     any later time during use, a SortedInt2 will adapt as needed
//     to accommodate more entries.
//
// CONSTRUCTOR
//   SortedInt2(int init_capacity = DEFAULT_CAPACITY)
//     Pre:  (none)
//     Post: The invoking SortedInt2 is initialized to an empty
//           SortedInt2 (i.e., one that contains no entries).
//           The highest # of entries that the SortedInt2 initially
//           can accommodate is init_capacity; at any later time,
//           the SortedInt2 will adapt as needed to accommodate more
//           entries.
//     Note: If init_capacity is not provided by client, or if the
//           value provided for it by client is invalid (i.e., less
//           than 1), it is set to DEFAULT_CAPACITY.
//
// CONSTANT MEMBER FUNCTIONS (ACCESSORS)
//   bool isEmpty() const
//     Pre:  (none)
//     Post: True is returned if the invoking SortedInt is empty
//           (i.e., # of items is 0), otherwise false is returned.
//   int size() const
//     Pre:  (none)
//     Post: The # of entries in the invoking SortedInt2 is returned.
//   int valAt(int position) const
//     Pre:  The invoking SortedInt is not empty and
//           position >= 1 and position <= size()
//     Post: The value of the entry with the given position in the
//           invoking SortedInt is returned.
//     Note: For a non-empty SortedInt, the entry with the lowest
//           value is at position 1 and the entry with the highest
//           value is at a position given by size().
//   int findMin() const
//     Pre:  The invoking SortedInt2 is not empty.
//     Post: The lowest value in the invoking SortedInt2 is returned.
//   int findMax() const
//     Pre:  The invoking SortedInt2 is not empty.
//     Post: The highest value in the invoking SortedInt2 is returned.
//   double findMed() const
//     Pre:  The invoking SortedInt is not empty.
//     Post: The median of the invoking SortedInt is returned.
//     Note: For a SortedInt that has an odd # of items, the median
//           is given by the value of the item in the middle; for a
//           SortedInt that has an even # of items, the median is
//           given by the average of the values of the two items
//           appearing in the middle. Below are two examples:
//           (1) median of {1 2 3 4 5} is 3.0
//           (2) median of {1 2 3 4 5 6} is (3 + 4)*0.5 = 3.5
//   double findAvg() const
//     Pre:  The invoking SortedInt2 is not empty.
//     Post: The average of the invoking SortedInt2 is returned.
//   int findFreq(int target) const
//     Pre:  (none)
//     Post: The # of times in which target occurs in the invoking
//           SortedInt2 is returned.
//
// MODIFICATION MEMBER FUNCTIONS (MUTATORS)
//   void reset()
//     Pre:  (none)
//     Post: The invoking SortedInt2 is set to empty.
//   void insert(int newInt)
//     Pre:  (none)
//     Post: A new entry with value newInt is added to the invoking
//           SortedInt2.
//   int delMin()
//     Pre:  The invoking SortedInt is not empty.
//     Post: All occurrences of the lowest value of the SortedInt
//           are removed and the # of occurrences so removed is
//           returned.
//   int delMax()
//     Pre:  The invoking SortedInt is not empty.
//     Post: All occurrences of the highest value of the invoking
//           SortedInt are removed and the # of occurrences so
//           removed is returned.
//   bool delOne(int target)
//     Pre:  (none)
//     Post: If target is found to occur one of more times in the
//           invoking SortedInt2, then the first occurrence of target
//           is removed from the invoking SortedInt2 and true is
//           returned, otherwise the invoking SortedInt2 is unchanged
//           and false is returned.
//   int delAll(int target)
//     Pre:  (none)
//     Post: If target is found to occur in the invoking SortedInt,
//           then all occurrences of target are removed from the
//           invoking SortedInt and the # of occurrences so removed
//           is returned, otherwise the invoking SortedInt is
//           unchanged and 0 is returned.
//   void operator+=(SortedInt2 addend)
//     Pre:  (none)
//     Post: All entries in addend are added to the invoking SortedInt2.
//     NOTE: addend is allowed to be the invoking object itself.
//     QUIZ: Can you see why addend is not passed by const reference?
//
// FRIEND FUNCTION
//   friend bool operator==(const SortedInt2& lhs, const SortedInt2& rhs)
//     Pre:  (none)
//     Post: True is returned if the lhs is equal (identical) to
//           rhs, otherwise false is returned.
//     Note: Two SortedInt2's are equal (identical) if they both
//           contain the same # of entries AND the values of every
//           pair of corresponding entries are equal.
//
// NON-MEMBER FUNCTION
//   SortedInt2 operator+(const SortedInt2& s1, const SortedInt2& s2)
//     Pre:  (none)
//     Post: A SortedInt2 containing copies of all the entries in s1
//           and s2 is returned.
//
// VALUE SEMANTICS
//   Assignment and the copy constructor may be used with SortedInt2
//   objects.

#ifndef SORTED_INT2_H
#define SORTED_INT2_H

class SortedInt2
{
public:
   static const int DEFAULT_CAPACITY = 1;
   SortedInt2(int init_capacity = DEFAULT_CAPACITY);
   SortedInt2(const SortedInt2& src);
   ~SortedInt2();
   bool isEmpty() const;
   int size() const;
   int valAt(int position) const;
   int findMin() const;
   int findMax() const;
   double findMed() const;
   double findAvg() const;
   int findFreq(int target) const;
   SortedInt2& operator=(const SortedInt2& rhs);
   void reset();
   void insert(int newInt);
   int delMin();
   int delMax();
   bool delOne(int target);
   int delAll(int target);
   void operator+=(SortedInt2 addend);
   friend bool operator==(const SortedInt2& lhs, const SortedInt2& rhs);

private:
   int * data;
   int capacity;
   int used;
   void resize(int new_capacity);
};

SortedInt2 operator+(const SortedInt2& s1, const SortedInt2& s2);

#endif
