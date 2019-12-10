#ifndef AVLTREE_H
#define AVLTREE_H

class AvlNode;

class AvlTree
{
public:
  AvlTree();

  //binary tree methods
  void preOrder(AvlNode *node);
  void postOrder(AvlNode *node);
  void inOrder(AvlNode *node);
  void levelOrder(AvlNode *node);
  int count(AvlNode *node);
  int height(AvlNode *node);
  int leafsCount(AvlNode *node);

  //binary search tree methods
  AvlNode * search(int key);
  AvlNode * insert(AvlNode *node, int key);
  AvlNode * inPredecesor(AvlNode *node);
  AvlNode * inSuccessor(AvlNode *node);
  AvlNode * deleteNode(AvlNode *node, int key);

  //avl mothods
  int nodeHeight(AvlNode *node);
  int balanceFactor(AvlNode *node);

  AvlNode *root;
};

#endif // AVLTREE_H
