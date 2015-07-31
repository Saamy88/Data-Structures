// FILE: Assign01.cpp
//       An interactive test program for the IntStore data type.

#include "IntStore.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// PROTOTYPES for functions used by this test program:

void print_menu();
// Pre:  (none)
// Post: A menu of choices for this program is written to cout.

char get_user_command();
// Pre:  (none)
// Post: The user is prompted to enter a one character command.
//       The next character is read (skipping blanks and newline
//       characters), and this character is returned.

int get_object_num(int argc);
// Pre:  (none)
// Post: The user is prompted to enter either 1, 2 or 3. The
//       prompt is repeated until a valid integer can be read
//       and the integer's value is either 1, 2 or 3. The valid
//       integer read is returned. The input buffer is cleared
//       of any extra input until and including the first
//       newline character.

int get_integer(int argc);
// Pre:  (none)
// Post: The user is prompted to enter an integer. The prompt
//       is repeated until a valid integer can be read. The
//       valid integer read is returned. The input buffer is
//       cleared of any extra input until and including the
//       first newline character.

void print_to_cout(IntStore src);
// Pre:  (none)
// Post: The content of src is displayed on cout.
/* Quiz: Why isn't src passed by const reference? */

int main(int argc, char* argv[])
{
   IntStore is1, is2, is3; // 3 IntStore's to perform tests on
   int objectNum,          // A number to indicate is1, is2 or is3
       givenValue;         // Holder for a user supplied value
   char choice;            // A command character entered by the user

   cout << "3 IntStore objects (is1 is2 is3) have been created." << endl;
   cout << "Each is now empty." << endl;
   
   do
   {
      if (argc == 1)
         print_menu();
      choice = get_user_command();
      switch (choice)
      {
      case 'm': case 'M':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            if ( ! is1.empty() )
               cout << "   Average for is1 is "
                    << is1.avg() << endl;
            else
               cout << "   is1 is empty (average undefined)" << endl;
            break;
         case 2:
            if ( ! is2.empty() )
               cout << "   Average for is2 is "
                    << is2.avg() << endl;
            else
               cout << "   is2 is empty (average undefined)" << endl;
            break;
         case 3:
            if ( ! is3.empty() )
               cout << "   Average for is3 is "
                    << is3.avg() << endl;
            else
               cout << "   is3 is empty (average undefined)" << endl;
         }
         break;
      case '+':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            cout << "   " << is1.add(is1)
                 << " distinct values of is1 added to is1 " << endl;
            break;
         case 2:
            cout << "   " << is1.add(is2)
                 << " distinct values of is2 added to is1 " << endl;
            break;
         case 3:
            cout << "   " << is1.add(is3)
                 << " distinct values of is3 added to is1 " << endl;
         }
         break;
      case 'e': case 'E':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            if ( is1.empty() )
               cout << "   is1 is empty" << endl;
            else
               cout << "   is1 is not empty" << endl;
            break;
         case 2:
            if ( is2.empty() )
               cout << "   is2 is empty" << endl;
            else
               cout << "   is2 is not empty" << endl;
            break;
         case 3:
            if ( is3.empty() )
               cout << "   is3 is empty" << endl;
            else
               cout << "   is3 is not empty" << endl;
         }
         break;
      case 's': case 'S':
         if ( similar(is1, is2) )
            cout << "   is1 is similar to is2" << endl;
         else
            cout << "   is1 is not similar to is2" << endl;
         if ( similar(is1, is3) )
            cout << "   is1 is similar to is3" << endl;
         else
            cout << "   is1 is not similar to is3" << endl;
         if ( similar(is2, is3) )
            cout << "   is2 is similar to is3" << endl;
         else
            cout << "   is2 is not similar to is3" << endl;
         break;
      case 'a': case 'A':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            cout << "   is1 has " << is1.countAll() << " items" << endl;
            break;
         case 2:
            cout << "   is2 has " << is2.countAll() << " items" << endl;
            break;
         case 3:
            cout << "   is3 has " << is3.countAll() << " items" << endl;
         }
         break;
      case 'd': case 'D':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            cout << "   is1 has " << is1.countDistinct()
                 << " distinct values" << endl;
            break;
         case 2:
            cout << "   is2 has " << is2.countDistinct()
                 << " distinct values" << endl;
            break;
         case 3:
            cout << "   is3 has " << is3.countDistinct()
                 << " distinct values" << endl;
         }
         break;
      case 't': case 'T':
         objectNum = get_object_num(argc);
         givenValue = get_integer(argc);
         switch (objectNum)
         {
         case 1:
            cout << "   is1 has " << is1.countTarget(givenValue)
                 << " copies of " << givenValue << endl;
            break;
         case 2:
            cout << "   is2 has " << is2.countTarget(givenValue)
                 << " copies of " << givenValue << endl;
            break;
         case 3:
            cout << "   is3 has " << is3.countTarget(givenValue)
                 << " copies of " << givenValue << endl;
         }
         break;
      case 'i': case 'I':
         objectNum = get_object_num(argc);
         givenValue = get_integer(argc);
         switch (objectNum)
         {
         case 1:
            if ( is1.add(givenValue) )
               cout << "   " << givenValue << " added to is1" << endl;
            else
               cout << "   " << givenValue << " not added to is1" << endl;
            break;
         case 2:
            if ( is2.add(givenValue) )
               cout << "   " << givenValue << " added to is2" << endl;
            else
               cout << "   " << givenValue << " not added to is2" << endl;
            break;
         case 3:
            if ( is3.add(givenValue) )
               cout << "   " << givenValue << " added to is3" << endl;
            else
               cout << "   " << givenValue << " not added to is3" << endl;
         }
         break;
      case 'k':
         objectNum = get_object_num(argc);
         givenValue = get_integer(argc);
         switch (objectNum)
         {
         case 1:
            if ( is1.remOne(givenValue) )
               cout << "   1 copy of " << givenValue << " removed from is1"
                    << endl;
            else
               cout << "   " << givenValue << " not found in is1" << endl;
            break;
         case 2:
            if ( is2.remOne(givenValue) )
               cout << "   1 copy of " << givenValue << " removed from is2"
                    << endl;
            else
               cout << "   " << givenValue << " not found in is2" << endl;
            break;
         case 3:
            if ( is3.remOne(givenValue) )
               cout << "   1 copy of " << givenValue << " removed from is3"
                    << endl;
            else
               cout << "   " << givenValue << " not found in is3" << endl;
         }
         break;
      case 'K':
         objectNum = get_object_num(argc);
         givenValue = get_integer(argc);
         switch (objectNum)
         {
         case 1:
            cout << "   " << is1.remAll(givenValue) << " copies of "
                 << givenValue << " removed from is1" << endl;
            break;
         case 2:
            cout << "   " << is2.remAll(givenValue) << " copies of "
                 << givenValue << " removed from is2" << endl;
            break;
         case 3:
            cout << "   " << is3.remAll(givenValue) << " copies of "
                 << givenValue << " removed from is3" << endl;
         }
         break;
      case 'p': case 'P':
         objectNum = get_object_num(argc);
         /* Quiz: Why is the following block written in such
                  a weird-looking fashion? */
         {
            IntStore tempStore;
            switch (objectNum)
            {
            case 1:
               tempStore = is1;
               if ( tempStore.empty() )
                  cout << "   is1: (empty)" << endl;
               else
               {
                  cout << "   is1: (data)";
                  print_to_cout(tempStore);
               }
               break;
            case 2:
               tempStore = is2;
               if ( tempStore.empty() )
                  cout << "   is2: (empty)" << endl;
               else
               {
                  cout << "   is2: (data)";
                  print_to_cout(tempStore);
               }
               break;
            case 3:
               tempStore = is3;
               if ( tempStore.empty() )
                  cout << "   is3: (empty)" << endl;
               else
               {
                  cout << "   is3: (data)";
                  print_to_cout(tempStore);
               }
            }
         }
         break;
      case 'r': case 'R':
         objectNum = get_object_num(argc);
         switch (objectNum)
         {
         case 1:
            is1.reset();
            cout << "   is1 has been reset and is now empty" << endl;
            break;
         case 2:
            is2.reset();
            cout << "   is2 has been reset and is now empty" << endl;
            break;
         case 3:
            is3.reset();
            cout << "   is3 has been reset and is now empty" << endl;
         }
         break;
      case 'q': case 'Q':
         cout << "Quit option selected...bye" << endl;
         break;
      default:
         cout << choice << " is not a valid option...try again"
              << endl;
      }
   }
   while (choice != 'q' && choice != 'Q');

   cin.ignore(999, '\n');
   cout << "Press Enter or Return when ready...";
   cin.get();
   return EXIT_SUCCESS;
}

void print_menu()
{
   cout << endl;
   cout << "The following choices are available: " << endl;
   cout << "  +  Add is1, is2 or is3 to is1" << endl;
   cout << "  a  Get # of total items in is1, is2 or is3" << endl;
   cout << "  d  Get # of distinct items in is1, is2 or is3" << endl;
   cout << "  e  Check if is1, is2 or is3 is empty" << endl;
   cout << "  i  Insert a new value into is1, is2 or is3" << endl;
   cout << "  k  Remove 1 of a given value from is1, is2 or is3" << endl;
   cout << "  K  Remove all of a given value from is1, is2 or is3" << endl;
   cout << "  m  Get average for is1, is2 or is3" << endl;
   cout << "  p  Print is1, is2 or is3 (to stdout)" << endl;
   cout << "  r  Reset is1, is2 or is3 to become empty" << endl;
   cout << "  s  Check if any pair of {is1 is2 is3} is similar" << endl;
   cout << "  t  Get # of target items in is1, is2 or is3" << endl;
   cout << "  q  Quit this test program" << endl;
}

char get_user_command()
{
   char command;

   cout << "Enter choice: ";
   cin >> command;

   cout << command << " read." << endl;
   return command;
}

int get_object_num(int argc)
{
   int result;

   cout << "Enter object # (1 = is1, 2 = is2, 3 = is3) ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter object # (1 = is1, 2 = is2, 3 = is3) ";
      cin  >> result;
   }
   if (argc < 2)
      cin.ignore(999, '\n');

   while (result != 1 && result != 2 && result != 3)
   {
      cerr << "Invalid object # (must be 1, 2 or 3)..." << endl;
      cout << "Re-enter object # (1 = is1, 2 = is2, 3 = is3) ";
      cin  >> result;
      while ( ! cin.good() )
      {
         cerr << "Invalid integer input..." << endl;
         cin.clear();
         cin.ignore(999, '\n');
         cout << "Re-enter object # (1 = is1, 2 = is2, 3 = is3) ";
         cin  >> result;
      }
      cin.ignore(999, '\n');
   }

   cout << result << " read." << endl;
   return result;
}

int get_integer(int argc)
{
   int result;

   cout << "Enter integer value ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter integer value ";
      cin  >> result;
   }
   if (argc < 2)
      cin.ignore(999, '\n');

   cout << result << " read." << endl;
   return result;
}

void print_to_cout(IntStore src)
{
   int countDist = src.countDistinct();
   for (int i = 1; i <= countDist; ++i)
      cout << setw(5) << src.valAt(i);
   cout << endl;
   cout << "        (freq)";
   for (int i = 1; i <= countDist; ++i)
      cout << setw(5) << src.freqAt(i);
   cout << endl;
}

