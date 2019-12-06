#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
public:
  BinarySearchTree();

  void create();
  void insert(int key);
  BinaryNode * search(int key);
  BinaryNode * insertRecursive(BinaryNode *node, int key);
  BinaryNode * inPredecesor(BinaryNode *node);
  BinaryNode * inSuccessor(BinaryNode *node);
  BinaryNode * deleteNode(BinaryNode *node, int key);
  void createFromPreorder(int *preorderArr, int n);

};

#endif // BINARYSEARCHTREE_H
