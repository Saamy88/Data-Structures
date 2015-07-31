#include <iostream>
using namespace std;

void MergeRecur(struct Node* &headX, struct Node* &headY, struct Node* &headZ);
void DisplayList(struct Node* headPtr1, struct Node* headPtr2, struct Node* headPtr3);
void ListClear(struct Node* &headPtr1, struct Node* &headPtr2, struct Node* &headPtr3);


struct Node
{
    int data;
    Node *link;
};

int main()
{
    Node *headPtrX =0,
         *headPtrY = 0,
		 *headPtrZ = 0;      // This will be the unchanging first node

    headPtrX = new Node; // Now root points to a node struct
    headPtrX->link = 0;  // The node root points to has its next pointer
    //  set equal to a null pointer
    headPtrX->data = 1;     // By using the -> operator, you can modify the node
    //  a pointer (root in this case) points
    headPtrX->link = new Node;
    headPtrX->link->link = 0;
    headPtrX->link->data  = 2;
	
	headPtrY = new Node;
	headPtrY->link = 0;
	headPtrY->data = 3;
	
	headPtrY->link = new Node;
	headPtrY->link->link = 0;
	headPtrY->link->data = 4;
   
    cout << endl;

    //cout << "List started as: 0 1 1 3 4 5 8 8 8 8 8 " << endl;
    MergeRecur(headPtrX, headPtrY, headPtrZ);
    DisplayList(headPtrX, headPtrY, headPtrZ);
    ListClear(headPtrX, headPtrY, headPtrZ);

    cout << endl;

    return 0;
}

void MergeRecur(struct Node* &headX, struct Node* &headY, struct Node* &headZ)
{	
	if(headX == 0 && headY == 0) return;

	if(headX == 0)
	{
		headZ = headY;
		headY = 0;
		return;
	}
	else if(headY == 0)
	{
		headZ = headX;
		headX = 0;
		return;
	}

	if (headX->data < headY->data)
	{
		headZ = headX;
		headX= headX->link;
	}
	else
	{
		headZ = headY;
		headY= headY->link;
	}

	MergeRecur(headX, headY, headZ->link);

	return;
   
}


void DisplayList(struct Node* headPtr1, struct Node* headPtr2, struct Node* headPtr3)
{
    if(headPtr1 == 0)
    {
        cout << "The ListX is empty " << endl;
    }
    cout << "List X: ";
    while(headPtr1 != 0)
    {
        cout << headPtr1->data << " ";
        headPtr1 = headPtr1->link;
    }

    cout << endl;

    if(headPtr2 == 0)
    {
        cout << "The ListY is empty " << endl;
    }
    cout << "List Y: ";
    while(headPtr2 != 0)
    {
        cout << headPtr2->data << " ";
        headPtr2 = headPtr2->link;
    }
    cout << endl;
	
    if(headPtr3 == 0)
    {
        cout << "The ListZ is empty " << endl;
    }
    cout << "List Z: ";
    while(headPtr3 != 0)
    {
        cout << headPtr3->data << " ";
        headPtr2 = headPtr3->link;
    }

}

void ListClear(struct Node*& headPtr1, struct Node* &headPtr2, struct Node* &headPtr3)
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

    clog << "Dynamic memory for " << count << " nodes freed for ListX"
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

    clog << "Dynamic memory for " << count2 << " nodes freed for ListY"
         << endl;
	
    int count3 = 0;

    Node *cursor3 = headPtr3;
    while (headPtr3 != 0)
    {
        headPtr3 = headPtr3->link;
        delete cursor3;
        cursor3 = headPtr3;
        ++count3;
    }

    clog << "Dynamic memory for " << count3 << " nodes freed for ListZ"
         << endl;
}
