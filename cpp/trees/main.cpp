#include <QCoreApplication>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "AvlTree.h"
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
  bst.insert(20);
  bst.insert(8);
  bst.insert(30);
  qDebug() << "BST inOrder: ";
  bst.inOrder(bst.root);
  qDebug() << "Deleting: 20";
  bst.deleteNode(bst.root, 20);
  qDebug() << "BST inOrder: ";
  bst.inOrder(bst.root);
  BinaryNode *tmp = bst.search(20);
  if(tmp)
    qDebug() << "\nElement: " << tmp->data << " found";
  else
    qDebug() << "\nElement NOT found";

  BinarySearchTree bstRecursive;
  bstRecursive.root = bstRecursive.insertRecursive(bstRecursive.root, 10); //only the first insertion
  bstRecursive.insertRecursive(bstRecursive.root, 5);
  bstRecursive.insertRecursive(bstRecursive.root, 15);
  bstRecursive.insertRecursive(bstRecursive.root, 3);
  bstRecursive.insertRecursive(bstRecursive.root, 10);
  qDebug() << "bstRecursive inOrder: ";
  bstRecursive.inOrder(bstRecursive.root);

  /*BinarySearchTree bstCreate;
  int preOrderArr[6] = {0,1,2,3,4,5};
  bstCreate.createFromPreorder(preOrderArr, 6);
  qDebug() << "BST createFromPreorder: ";
  bstCreate.inOrder(bst.root);
  */

  AvlTree avl;
  avl.root = avl.insert(avl.root, 10);
  avl.insert(avl.root, 20);
  avl.insert(avl.root, 25);
  avl.insert(avl.root, 28);
  avl.insert(avl.root, 27);
  avl.insert(avl.root, 5);


  return a.exec();
}
