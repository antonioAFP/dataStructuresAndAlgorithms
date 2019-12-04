#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryNode;

class BinaryTree
{
public:
  BinaryTree();


  void preOrder(BinaryNode *node);
  void postOrder(BinaryNode *node);
  void inOrder(BinaryNode *node);
  void levelOrder(BinaryNode *node);
  int count(BinaryNode *node);
  int height(BinaryNode *node);
  int leafsCount(BinaryNode *node);
  void create();

  BinaryNode *root;
};

#endif // BINARYTREE_H
