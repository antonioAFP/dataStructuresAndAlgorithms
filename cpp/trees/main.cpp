#include <QCoreApplication>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  BinaryTree tree;
  /*
  tree.create();
  qDebug() << "\nPreOrder: ";
  tree.preOrder(tree.root);
  qDebug() << "\nPostOrder: ";
  tree.postOrder(tree.root);
  qDebug() << "\nInOrder: ";
  tree.inOrder(tree.root);
  qDebug() << "\nLeverOrder: ";
  tree.levelOrder(tree.root);
  qDebug() << "Nodes: " <<  tree.count(tree.root);
  qDebug() << "Height: " << tree.height(tree.root);
  */

  BinarySearchTree bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);
  bst.insert(3);
  qDebug() << "BST inOrder: ";
  bst.inOrder(bst.root);

  return a.exec();
}
