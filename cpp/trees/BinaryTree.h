#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryNode;

class BinaryTree
{
public:
  BinaryTree();

  void create();
  void preOrder(BinaryNode *node);
  void postOrder(BinaryNode *node);
  void inOrder(BinaryNode *node);
  void levelOrder(BinaryNode *node);
  int height(BinaryNode *node);

  BinaryNode *root;
};

#endif // BINARYTREE_H
