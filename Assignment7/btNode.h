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
int  bst_size(btNode* bst_root);
void bst_insert(btNode* &bst_root, int entry);
bool bst_remove(btNode* &bst_root, int target);
void bst_remove_max(btNode* &sub_tree, int &entry );

#endif
