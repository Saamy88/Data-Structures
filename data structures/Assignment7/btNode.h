#ifndef BT_NODE_H
#define BT_NODE_H

struct btNode
{
   int data;
   btNode* left;
   btNode* right;
};

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray);
void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex);
void tree_clear(btNode*& root);
int bst_size(btNode* bst_root);

// write prototype for bst_insert here
void bst_insert(btNode* &bst_root, int value);
// write prototype for bst_remove here
bool bst_remove(btNode* &bst_root, int value);
// write prototype for bst_remove_max here
void bst_remove_max(btNode* &bst_root, int& value);
#endif
