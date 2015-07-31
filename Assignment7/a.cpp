#include <iostream>
using namespace std;

struct btNode
{
   int data;
   btNode* left;
   btNode* right;
};

void inorder_print(btNode* root, ostream& out) 
// pre:  (none) 
// post: values (if any) stored on tree rooted at 
//       root have been inserted (each followed by 
//       a space character) in inorder fashion 
//       into out 
{ 
   if (root != 0) // if empty tree, simply return  
   { 
      inorder_print(root->left, out); 
      out << root->data << ' '; 
      inorder_print(root->right, out); 
   } 
}

void bst_insert(btNode* &bst_root, int entry)
{   
	if( bst_root == 0 )
	{
		
		bst_root = new btNode;
		bst_root->data = entry;
		bst_root->left = 0;
		bst_root->right = 0;
		return;
	}
	else
	{
		btNode* cur = bst_root, 
		      * pre = 0;
			  
	    btNode* newNode = new btNode;
		newNode->data = entry;
		newNode->left = 0;
		newNode->right = 0;
		
		while(cur != 0)
		{
			if(cur->data <= entry)
			{
				pre = cur;
				cur = cur->left;
			}
			else
			{
				pre = cur;
				cur = cur->right;
			}
		}
				
		if(pre->data <= entry)
			pre->left = newNode;
		else
			pre->right = newNode;
    }
}


int main()
{
	btNode *root = 0;
	
	bst_insert(root, 9);
	bst_insert(root, 12);
	bst_insert(root, 4);
	bst_insert(root, 11);
	bst_insert(root, 40);
	inorder_print(root, cout);
	cout << endl;
	
	return 0;
}