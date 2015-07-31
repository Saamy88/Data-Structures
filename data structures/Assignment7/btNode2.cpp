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

// write definition for bst_insert here
void bst_insert(btNode* &bst_root, int value)
{
	btNode* newNode = new btNode;
	newNode->data = value;
	newNode->left = 0;
	newNode->right = 0;

	if(bst_root == 0)
	{
		bst_root = newNode;
		return;
	}

	if(bst_root->left == 0 && bst_root->right == 0)
	{
		if(value > bst_root->data)
			bst_root->right = newNode;
		else
			bst_root->left = newNode;
		return;
	}

	btNode* root = bst_root;
	btNode* pre = 0;

	while(root != 0)
	{
		pre = root;
		if(value <= root->data)
			root = root->left;
		else
			root = root->right;
	}

	root = newNode;
	if(root->data > pre->data)
		pre->right = root;
	else
		pre->left = root;
}
// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int value)
{
    if(bst_root == 0)
    {
        return false;
    }

    if(bst_root->data > value)
    {
        return bst_remove(bst_root->left, value);
    }
    if(bst_root->data < value)
    {
        return bst_remove(bst_root->right, value);
    }
    if(bst_root->data == value)
    {
        if(bst_root->left == 0)
        {
            btNode*cur = bst_root;
            bst_root = bst_root->right;
            delete cur;
            return true;
        }
        else
        {
            bst_remove_max(bst_root->left, bst_root->data);
            return true;
        }
    }
}
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int& value)
{
    if(bst_root == 0)
        return;
    if(bst_root->right == 0)
    {
        value = bst_root->data;
        btNode* cur = bst_root;
        bst_root = bst_root->left;
        delete cur;
    }
    else
    {
        bst_remove_max(bst_root->right, value);
    }
}
