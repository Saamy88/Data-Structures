// FILE: IntStore.h - header file for IntStore class
//
// CONSTANT
//   static const int DEFAULT_CAPACITY = ____
//     IntStore::DEFAULT_CAPACITY is the initial capacity of an
//     IntStore that is created by the default constructor (i.e.,
//     IntStore::DEFAULT_CAPACITY is the highest # of distinct
//     values "an IntStore created by the default constructor"
//     can accommodate).
//
// CONSTRUCTOR
//   IntStore(int init_capacity = DEFAULT_CAPACITY)
//     Pre:  (none)
//     Post: The invoking IntStore is initialized to an empty
//           IntStore (i.e., one containing no relevant values);
//           the initial capacity is given by init_capacity if
//           init_capacity is >= 1, otherwise it is given by
//           IntStore:DEFAULT_CAPACITY.
//     Note: When the IntStore is put to use after construction,
//           its capacity will be resized as necessary.
//
// CONSTANT MEMBER FUNCTIONS (ACCESSORS)
//   bool empty() const
//     Pre:  (none)
//     Post: True is returned if the invoking IntStore is empty,
//           otherwise false is returned.
//     Note: An empty IntStore is one that contains no relevant
//           values.
//   int countDistinct() const
//     Pre:  (none)
//     Post: The # of distinct values in the invoking IntStore is
//           returned.
//   int countAll() const
//     Pre:  (none)
//     Post: The # of items (duplicates, if any, are included in
//           the count) in the invoking IntStore is returned.
//   int countTarget(int target) const
//     Pre:  (none)
//     Post: The # of "target"-matching items in the invoking
//           IntStore is returned.
//     Note: 0 is returned if the invoking IntStore is empty or
//           if the invoking IntStore is not empty but does not
//           contain a distinct value that matches target,
//           otherwise the # of occurrences of the distinct value
//           that matches target is returned.
//   int valAt(int pos) const
//     Pre:  The invoking IntStore is not empty (i.e., empty()
//           returns false), pos >= 1 and pos <= countDistinct().
//     Post: The distinct value at position pos in the invoking
//           IntStore is returned.
//     Note: For a non-empty IntStore, the position of a distinct
//           value is determined by when the FIRST item having that
//           value is added to the IntStore (the earlier that
//           first item is added, the lower is the position).
//           Position begins with 1 (not 0); thus, the earliest
//           distinct value added to the IntStore will be at
//           position 1 (unless that distinct value ceases to be
//           relevant due to subsequent removals), the 2nd-earliest
//           distinct value added to the IntStore will be at
//           position 2 (unless ...), and so on.
//   int freqAt(int pos) const
//     Pre:  The invoking IntStore is not empty (i.e., empty()
//           returns false), pos >= 1 and pos <= countDistinct().
//     Post: The # of items (occurrences) having the distinct value
//           at position pos in the invoking IntStore is returned.
//     Note: See Note under valAt(...) above.
//   double avg() const
//     Pre:  The invoking IntStore is not empty (i.e., empty()
//           returns false)
//     Post: The average of the items in the invoking IntStore is
//           returned.
//     Note: Duplicates, if any, are included in the computation.
//
// MODIFICATION MEMBER FUNCTIONS (MUTATORS)
//   void reset()
//     Pre:  (none)
//     Post: The invoking IntStore is reset to become an empty
//           IntStore.
//   bool add(int item, int copies = 1)
//     Pre:  copies > 0
//     Post: True is returned if "copies" of "item" has/have been
//           successfully added to the invoking IntStore,
//           otherwise false is returned.
//     Note: If "copies" is not specified, it defaults to 1.
//   int operator+=(const IntStore& addend)
//     Pre:  (none)
//     Post: The contents of "addend" are added to the invoking
//           IntStore and the # of distinct values (in "addend")
//           so added is returned.
//     Note: The return value is simply a count of the distinct
//           values in addend that got added to the invoking
//           IntStore, regardless of whether or not each distinct
//           value so added leads to a new distinct value in the
//           invoking IntStore, and each distinct value added
//           contributes only 1 count even if it involves multiple
//           copies.
//     Note: Contents of "addend" are added in order of position
//           (i.e., those with lowest positions are added first).
//     Note: addend is allowed to be the invoking IntStore itself.
//   bool remOne(int target)
//     Pre:  (none)
//     Post: If "target" is found to occur one of more times in the
//           invoking IntStore, then the occurrence of the
//           "target"-matching value in the invoking IntStore is
//           decremented and true is returned, otherwise the
//           invoking IntStore is unchanged and false is returned.
//   int remAll(int target)
//     Pre:  (none)
//     Post: If target is found to occur in the invoking IntStore,
//           then all occurrences of the "target"-matching value
//           are removed from the invoking IntStore and the # of
//           occurrences so removed is returned, otherwise the
//           invoking IntStore is unchanged and 0 is returned.
//
// NON-MEMBER FUNCTIONS
//   bool operator==(const IntStore& is1, const IntStore& is2)
//     Pre:  (none)
//     Post: True is returned if "is1" is similar to "is2", otherwise
//           false is returned.
//     Note: 2 IntStore's are similar if they contain the same set of
//           distinct values, regardless of the order in which each
//           value appears and the # of occurrences of each value.
//
// VALUE SEMANTICS
//   Assignment and the copy constructor may be used with IntStore
//   objects.

#ifndef INT_STORE_H
#define INT_STORE_H

class IntStore
{
public:
   static const int DEFAULT_CAPACITY = 1;
   IntStore(int init_capacity = DEFAULT_CAPACITY);
   IntStore(const IntStore& src);
   ~IntStore();
   IntStore& operator=(const IntStore& rhs);
   bool empty() const;
   int countDistinct() const;
   int countAll() const;
   int countTarget(int target) const;
   int valAt(int pos) const;
   int freqAt(int pos) const;
   double avg() const;
   void reset();
   bool add(int item, int copies = 1);
   int operator+=(const IntStore& addend);
   bool remOne(int target);
   int remAll(int target);
private:
   int* data;
   int* freq;
   int capacity;
   int used;
   void resize(int new_capacity);
};

bool operator==(const IntStore& is1, const IntStore& is2);

#endif
