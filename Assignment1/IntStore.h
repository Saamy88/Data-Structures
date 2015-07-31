// FILE: IntStore.h - header file for IntStore class
//
// CONSTANT
//   static const int MAX_SIZE = ____
//     IntStore::MAX_SIZE is the highest # of distinct values
//     that can be accommodated.
//
// CONSTRUCTOR
//   IntStore()
//     Pre:  (none)
//     Post: The invoking IntStore is initialized to an empty
//           IntStore (i.e., one containing no relevant values).
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
//   int add(const IntStore& addend)
//     Pre:  (none)
//     Post: As much of the contents of "addend" as possible
//           are added to the invoking IntStore and the number
//           of distinct values (in "addend") so added is returned.
//     Note: The return value is simply a count of the distinct
//           values in addend that successfully got added to the
//           invoking IntStore, regardless of whether or not each
//           distinct value so added leads to a new distinct value
//           in the invoking IntStore, and each distinct value
//           successfully added contributes only 1 count even if it
//           involves multiple copies.
//     Note: Contents of "addend" are added in order of position
//           (i.e., those with lowest positions are added first).
//     Note: addend is allowed to be the invoking IntStore itself.
//   bool remOne(int target)
//     Pre:  (none)
//     Post: If "target" is found to occur one of more times in the
//           invoking IntStore, then the occurrence count of the
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
//   bool similar(const IntStore& is1, const IntStore& is2)
//     Pre:  (none)
//     Post: True is returned if "is1" is similar to "is2", otherwise
//           false is returned.
//     Note: 2 IntStore's are similar if they contain the same set of
//           distinct values, regardless of the order in which each
//           value appears and the # of occurrences of each value.

#ifndef INT_STORE_H
#define INT_STORE_H

class IntStore
{
public:
   static const int MAX_SIZE = 10;
   IntStore();
   bool empty() const;
   int countDistinct() const;
   int countAll() const;
   int countTarget(int target) const;
   int valAt(int pos) const;
   int freqAt(int pos) const;
   double avg() const;
   void reset();
   bool add(int item, int copies = 1);
   int add(const IntStore& addend);
   bool remOne(int target);
   int remAll(int target);
private:
   int data[MAX_SIZE];
   int freq[MAX_SIZE];
   int used;
};

bool similar(const IntStore& is1, const IntStore& is2);

#endif
