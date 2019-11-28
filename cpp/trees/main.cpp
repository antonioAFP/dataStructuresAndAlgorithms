#include <QCoreApplication>
#include "BinaryTree.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  BinaryTree tree;

  tree.create();
  tree.preOrder(tree.root);

  return a.exec();
}
