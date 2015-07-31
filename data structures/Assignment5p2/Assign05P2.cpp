#include "llcpInt.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void SeedRand();
int  BoundedRandomInt(int lowerBound, int upperBound);
int  ListLengthCheck(Node* head, int whatItShouldBe);
bool match(Node* head, const int procInts[], int procSize);
void ShowArray(const int a[], int size, bool endWithNL = true);
void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues1[], int caseSize1,
                   const int caseValues2[], int caseSize2);
void CompactShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues1[], int caseSize1,
                   const int caseValues2[], int caseSize2);

int main()
{
   int testCasesToDo = 990000,
       testCasesDone = 0,
       loSize = 0,
       hiSize = 10,
       loValue = 0,
       hiValue = 9;
   int numInts1,
       numInts2,
       used1,
       used11,
       used2,
       used22,
       intCount,
       oneInt,
       i1,
       i2,
       iLenChk1,
       iLenChk2;
   int *intArr1 = 0,
       *intArr11 = 0,
       *intArr2 = 0,
       *intArr22 = 0;
   Node *head1 = 0,
        *head2 = 0;

   // SeedRand(); // disabled for reproducible result

   do
   {
      ++testCasesDone;
      numInts1 = BoundedRandomInt(loSize, hiSize);
      numInts2 = BoundedRandomInt(loSize, hiSize);
      if (numInts1) intArr1  = new int [numInts1];
      if (numInts2) intArr2  = new int [numInts2];
      if (numInts1 + numInts2)
      {
         intArr11 = new int [numInts1 + numInts2];
         intArr22 = new int [numInts1 + numInts2];
      }

      used1 = used2 = 0;
      for (intCount = 0; intCount < numInts1; ++intCount)
      {
         oneInt = BoundedRandomInt(loValue, hiValue);
         intArr1[used1++] = oneInt;
         InsertAsTail(head1, oneInt);
      }
      for (intCount = 0; intCount < numInts2; ++intCount)
      {
         oneInt = BoundedRandomInt(loValue, hiValue);
         intArr2[used2++] = oneInt;
         InsertAsTail(head2, oneInt);
      }

      used11 = used22 = 0;
      i1 = i2 = 0;
      while (i1 < used1 && i2 < used2)
      {
         while ( i1 < used1 && (intArr1[i1] & 1) )
            intArr11[used11++] = intArr1[i1++];
         while ( i2 < used2 &&  !(intArr2[i2] & 1) )
            intArr22[used22++] = intArr2[i2++];
         if (i1 < used1 && i2 < used2)
         {
            intArr11[used11++] = intArr2[i2++];
            intArr22[used22++] = intArr1[i1++];
         }
      }
      while (i1 < used1)
      {
         if (intArr1[i1] & 1)
            intArr11[used11++] = intArr1[i1++];
         else
            intArr22[used22++] = intArr1[i1++];
      }
      while (i2 < used2)
      {
         if (intArr2[i2] & 1)
            intArr11[used11++] = intArr2[i2++];
         else
            intArr22[used22++] = intArr2[i2++];
      }

      // Compactly show 1st ?? cases
      // To show every case (to ID which case when debugging), simply comment out the if
      // CAUTION: huge output file can result if showing every case)
      if (testCasesDone <= 80) // ?? = 80 chosen
         CompactShowCase(testCasesDone, testCasesToDo, intArr1, used1, intArr2, used2);

      MakeAllOddAndAllEven(head1, head2);
      // if (head1) head1 = head1->link; // for testing out error reporting
      // if (head1) head1->data = -1;    // for testing out error reporting

      iLenChk1 = ListLengthCheck(head1, used11);
      if (iLenChk1 != 0)
      {
         if (iLenChk1 == -1)
         {
            cout << "List1 node-count error ... too few" << endl;
            cout << "Test case " << testCasesDone << " for these given lists: " << endl;
            cout << "        L1: ";
            ShowArray(intArr1, used1);
            cout << "        L2: ";
            ShowArray(intArr2, used2);
            cout << "#expected: " << used11 << endl;
            cout << "#returned: " << FindListLength(head1) << endl;
         }
         else
         {
            cout << "List1 node-count error ... too many (circular list?)" << endl;
            cout << "Test case " << testCasesDone << " for these given lists: " << endl;
            cout << "        L1: ";
            ShowArray(intArr1, used1);
            cout << "        L2: ";
            ShowArray(intArr2, used2);
            cout << "#expected: " << used11 << endl;
            cout << "returned # is higher (may be infinite)" << endl;
         }
         exit(EXIT_FAILURE);
      }
      iLenChk2 = ListLengthCheck(head2, used22);
      if (iLenChk2 != 0)
      {
         if (iLenChk2 == -1)
         {
            cout << "List2 node-count error ... too few" << endl;
            cout << "Test case " << testCasesDone << " for these given lists: " << endl;
            cout << "        L1: ";
            ShowArray(intArr1, used1);
            cout << "        L2: ";
            ShowArray(intArr2, used2);
            cout << "#expected: " << used22 << endl;
            cout << "#returned: " << FindListLength(head2) << endl;
         }
         else
         {
            cout << "List2 node-count error ... too many (circular list?)" << endl;
            cout << "Test case " << testCasesDone << " for these given lists: " << endl;
            cout << "        L1: ";
            ShowArray(intArr1, used1);
            cout << "        L2: ";
            ShowArray(intArr2, used2);
            cout << "#expected: " << used22 << endl;
            cout << "returned # is higher (may be infinite)" << endl;
         }
         exit(EXIT_FAILURE);
      }

      if ( !match(head1, intArr11, used11) || !match(head2, intArr22, used22) )
      {
         cout << "Contents error ... mismatch found in value or order" << endl;
         cout << "Test case " << testCasesDone << " for these given lists: " << endl;
         cout << "initial L1: ";
         ShowArray(intArr1, used1);
         cout << "        L2: ";
         ShowArray(intArr2, used2);
         cout << "ought2b L1: ";
         ShowArray(intArr11, used11);
         cout << "        L2: ";
         ShowArray(intArr22, used22);
         cout << "outcome L1: ";
         ShowAll(cout, head1);
         cout << "        L2: ";
         ShowAll(cout, head2);
         exit(EXIT_FAILURE);
      }

      if (testCasesDone % 45000 == 0)
      {
         cout << "================================" << endl;
         clog << "testing case " << testCasesDone
              << " of " << testCasesToDo << endl;
         clog << "================================" << endl;
         // cout << "test case " << testCasesDone
         //      << " of " << testCasesToDo << endl;
         cout << "initial L1: ";
         ShowArray(intArr1, used1);
         cout << "        L2: ";
         ShowArray(intArr2, used2);
         cout << "ought2b L1: ";
         ShowArray(intArr11, used11);
         cout << "        L2: ";
         ShowArray(intArr22, used22);
         cout << "outcome L1: ";
         ShowAll(cout, head1);
         cout << "        L2: ";
         ShowAll(cout, head2);
      }

      ListClear(head1, 1);
      ListClear(head2, 1);
      delete [] intArr1;
      delete [] intArr11;
      delete [] intArr2;
      delete [] intArr22;
      intArr1 = intArr11 = intArr2 = intArr22 = 0;
   }
   while (testCasesDone < testCasesToDo);
   cout << "================================" << endl;
   cout << "test program terminated normally" << endl;
   cout << "================================" << endl;

   return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////
// Function to seed the random number generator
// PRE:  none
// POST: The random number generator has been seeded.
/////////////////////////////////////////////////////////////////////
void SeedRand()
{
   srand( (unsigned) time(NULL) );
}

/////////////////////////////////////////////////////////////////////
// Function to generate a random integer between
// lowerBound and upperBound (inclusive)
// PRE:  lowerBound is a positive integer.
//       upperBound is a positive integer.
//       upperBound is larger than lowerBound
//       The random number generator has been seeded.
// POST: A random integer between lowerBound and upperBound
//       has been returned.
/////////////////////////////////////////////////////////////////////
int BoundedRandomInt(int lowerBound, int upperBound)
{
   return ( rand() % (upperBound - lowerBound + 1) ) + lowerBound;
}

/////////////////////////////////////////////////////////////////////
// Function to check # of nodes in list against what it should be
// POST: returns
//          -1 if # of nodes is less than what it should be
//           0 if # of nodes is equal to  what it should be
//           1 if # of nodes is more than what it should be
/////////////////////////////////////////////////////////////////////
int ListLengthCheck(Node* head, int whatItShouldBe)
{
   int length = 0;
   while (head != 0)
   {
      ++length;
      if (length > whatItShouldBe) return 1;
      head = head->link;
   }
   return (length < whatItShouldBe) ? -1 : 0;
}

bool match(Node* head, const int procInts[], int procSize)
{
   int iProc = 0;
   while (head != 0)
   {
      if (iProc == procSize) return false;
      if (head->data != procInts[iProc]) return false;
      ++iProc;
      head = head->link;
   }
   return true;
}

void ShowArray(const int a[], int size, bool endWithNL)
{
   for (int i = 0; i < size; ++i)
      cout << a[i] << "  ";
   if (endWithNL)  cout << endl;
}

void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues1[], int caseSize1,
                   const int caseValues2[], int caseSize2)
{
      cout << "(test case " << whichCase
           << " of " << totalCasesToDo << ") with given lists: " << endl;
      cout << "        L1: ";
      ShowArray(caseValues1, caseSize1);
      cout << "        L2: ";
      ShowArray(caseValues2, caseSize2);
}

void CompactShowCase(int whichCase, int totalCasesToDo,
                     const int caseValues1[], int caseSize1,
                     const int caseValues2[], int caseSize2)
{
      cout << "Case " << setw(3) << whichCase << ": L1 = ";
      ShowArray(caseValues1, caseSize1, false);
      for (int i = caseSize1; i < 10; ++i) cout << "   ";
      cout << " L2 = ";
      ShowArray(caseValues2, caseSize2, false);
      cout << endl;
}