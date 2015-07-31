#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{  
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
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
			if( entry <= cur->data )
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
				
		if( entry <= pre->data )
			pre->left = newNode;
		else
			pre->right = newNode;
    }
}

bool bst_remove(btNode* &bst_root, int target)
{
	if(bst_root == 0) return false;
	
	else
	{
		if( target > bst_root->data) 
		{
			bst_remove(bst_root->right, target);
		}
		else if( target < bst_root->data )
		{ 
			bst_remove(bst_root->left, target);
		}
		else
		{   
			if( bst_root->left == 0 )
			{
				btNode* temp = bst_root;
				bst_root = bst_root->right;
				delete temp;
				return true;
				
			}
			else if( bst_root->left != 0 )
			{
				bst_remove_max(bst_root->left, bst_root->data);
				return true;
			}	
		}   
	}
}

void bst_remove_max(btNode* &sub_tree, int &entry )
{	
    if(sub_tree == 0) return;
	
	if( sub_tree->right == 0 )
	{
		entry = sub_tree->data;
		btNode* temp = sub_tree;
		sub_tree = sub_tree->left;
		delete temp;
	}
	else
	{
		bst_remove_max(sub_tree->right, entry);
	}
}


