#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryNode;

class BinaryTree
{
public:
  BinaryTree();

  void create();
  void preOrder();
  void postOrder();
  void inOrder();
  void levelOrder();
  int height();

  BinaryNode *root;
};

#endif // BINARYTREE_H
