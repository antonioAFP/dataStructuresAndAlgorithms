#include <QCoreApplication>
#include "BinaryTree.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  BinaryTree tree;

  tree.create();
  qDebug() << "\nPreOrder: ";
  tree.preOrder(tree.root);
  qDebug() << "\nPostOrder: ";
  tree.postOrder(tree.root);
  qDebug() << "\nInOrder: ";
  tree.inOrder(tree.root);
  qDebug() << "\nLeverOrder: ";
  tree.levelOrder(tree.root);
  qDebug() << "\nNodes: " <<  tree.count(tree.root);
  qDebug() << "\nHeight: " << tree.height(tree.root);

  return a.exec();
}
