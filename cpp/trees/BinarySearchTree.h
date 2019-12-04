#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
public:
  BinarySearchTree();

  void create();
  void insert(int key);

};

#endif // BINARYSEARCHTREE_H
