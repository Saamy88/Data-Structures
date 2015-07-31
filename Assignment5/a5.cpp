#include <iostream>
using namespace std;

void Form2NoDupListsUsgGivenList(struct Node* &headPtr1, struct Node* &headPtr2);
void DisplayList(struct Node* headPtr1, struct Node* headPtr2);
void ListClear(struct Node* &headPtr1, struct Node* &headPtr2);


struct Node
{
    int data;
    Node *link;
};

int main()
{
    Node *headPtr2 =0;
    Node *headPtr = 0;      // This will be the unchanging first node
    
    headPtr = new Node; // Now root points to a node struct
    headPtr->link = 0;  // The node root points to has its next pointer
    //  set equal to a null pointer
    headPtr->data = 0;     // By using the -> operator, you can modify the node
    //  a pointer (root in this case) points
    headPtr->link = new Node;
    headPtr->link->link = 0;
    headPtr->link->data  = 0;
    
    headPtr->link->link = new Node;
     headPtr->link->link->link = 0;
     headPtr->link->link->data  = 2;
    
     headPtr->link->link->link = new Node;
     headPtr->link->link->link->link = 0;
     headPtr->link->link->link->data  = 6;
    
     headPtr->link->link->link->link = new Node;
     headPtr->link->link->link->link->link = 0;
     headPtr->link->link->link->link->data  = 6;
    /*
     headPtr->link->link->link->link->link = new Node;
     headPtr->link->link->link->link->link->link = 0;
     headPtr->link->link->link->link->link->data  = 5;
    
     headPtr->link->link->link->link->link->link = new Node;
     headPtr->link->link->link->link->link->link->link = 0;
     headPtr->link->link->link->link->link->link->data  = 2;
    
     headPtr->link->link->link->link->link->link->link = new Node;
     headPtr->link->link->link->link->link->link->link->link = 0;
     headPtr->link->link->link->link->link->link->link->data = 4;
    
     headPtr->link->link->link->link->link->link->link->link = new Node;
     headPtr->link->link->link->link->link->link->link->link->link = 0;
     headPtr->link->link->link->link->link->link->link->link->data = 1;
     */
    
    
    cout << endl;
    
    cout << "List started as: 0 0 2 6 6" << endl;
    Form2NoDupListsUsgGivenList(headPtr, headPtr2);
    DisplayList(headPtr, headPtr2);
    ListClear(headPtr, headPtr2);
    
    cout << endl;
    
    return 0;
}

void Form2NoDupListsUsgGivenList(struct Node* &headPtr1, struct Node* &headPtr2)
{
    if(headPtr1 == 0)
    {
        headPtr2 = headPtr1;
        return;
    }
    
    if(headPtr1->link == 0)
   	{
        headPtr2 = new Node;
        headPtr2->data = headPtr1->data;
        headPtr2->link = 0;
        return;
   	}

    
    Node* backupHead1 = headPtr1,
        * backupHead2 = headPtr2,
        * pre = 0,
        * cur = 0;
    bool repetition = false;
    int reps = 0;
    bool duplicate = false;
    
    while(backupHead1->link != 0)
    {
        cur = backupHead1->link;
        pre = backupHead1;
        reps = 0;
        while(cur != 0)
        {
            if(backupHead1->data == cur->data)
            {
                repetition = true;
                reps++;
                if(headPtr2 == 0 && reps == 1)
                {
                    headPtr2 = cur;
                    pre->link = cur->link;
                    cur->link = 0;
                    cur = pre->link;

                }
                
                else if (reps == 1)
                {
                    backupHead2 = new Node;
                    backupHead2->data = backupHead1->data;
                    backupHead2->link = 0;
                    
                    Node* last = headPtr2;
                    
                    while(last->link != 0)
                        last = last->link;
                    
                    last->link = backupHead2;
                    backupHead2 = 0;
                }
                
                if(reps > 1)
                {
                    pre->link = cur->link;
                    delete cur;
                    cur = pre->link;
                }
                
            }
            else
            {
                repetition = false;
            }
            
            if(!repetition)
            {
                pre = cur;
                cur = cur->link;
    
            }
            
            if(cur != 0 && reps > 1 )
            {
                pre = cur;
                cur = cur->link;
            }
        }
        
        if(!repetition)
        {
            duplicate = false;
            
            backupHead2 = new Node;
            backupHead2->data = backupHead1->data;
            backupHead2->link = 0;
            
            Node* last = headPtr2;
            while(last != 0)
            {
                if (last->data == backupHead2->data)
                {
                    duplicate = true;
                    delete backupHead2;
                    break;
                }
                last = last->link;
            }
            
            cout << "duplicate is " << duplicate << endl;
            
            if(headPtr2 == 0)
                headPtr2 = backupHead2;
            else if(!duplicate)
            {
                Node* last = headPtr2;
                    
                while(last->link != 0)
                    last = last->link;
                    
                last->link = backupHead2;
            }
            backupHead2 = 0;
            
            if(backupHead1->link->link == 0)
            {
                backupHead2 = new Node;
                backupHead2->data = pre->data;
                backupHead2->link = 0;
                
                Node* last = headPtr2;
                
                while(last->link != 0)
                    last = last->link;
                
                last->link = backupHead2;
            }
        }
        
        if(backupHead1->link != 0 && !repetition)
            backupHead1 = backupHead1->link;
    }
    
}



void DisplayList(struct Node* headPtr1, struct Node* headPtr2)
{
    if(headPtr1 == 0)
    {
        cout << "The List1 is empty " << endl;
    }
    cout << "List1: ";
    while(headPtr1 != 0)
    {
        cout << headPtr1->data << " ";
        headPtr1 = headPtr1->link;
    }
    
    cout << endl;
    
    if(headPtr2 == 0)
    {
        cout << "The List2 is empty " << endl;
    }
    cout << "List2: ";
    while(headPtr2 != 0)
    {
        cout << headPtr2->data << " ";
        headPtr2 = headPtr2->link;
    }
    cout << endl;
    
}

void ListClear(struct Node*& headPtr1, struct Node* &headPtr2)
{    
    
    int count = 0;
    
    Node *cursor = headPtr1;
    while (headPtr1 != 0)
    {      
        headPtr1 = headPtr1->link;
        delete cursor;
        cursor = headPtr1;
        ++count;
    }
    
    clog << "Dynamic memory for " << count << " nodes freed for List1"
    << endl;
    
    int count2 = 0;
    
    Node *cursor2 = headPtr2;
    while (headPtr2 != 0)
    {      
        headPtr2 = headPtr2->link;
        delete cursor2;
        cursor2 = headPtr2;
        ++count2;
    }
    
    clog << "Dynamic memory for " << count2 << " nodes freed for List2"
    << endl;
}