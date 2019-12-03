#include "BinaryTree.h"
#include "BinaryNode.h"
#include "Queue.h"
#include <iostream>
//#include "SingleNode.h"

using namespace std;

BinaryTree::BinaryTree()
{
  root = nullptr;
}

void BinaryTree::create(){
  BinaryNode *p, *t;
  int x;
  Queue queue;

  cout << "Enter root value: ";
  cin >> x;

  root = new BinaryNode(x);

  if(!root){
      cout << "Tree can not be created";
      return;
    }

  queue.enqueue(root);

  while(!queue.isEmpty()){
      p = queue.dequeue();
      cout << "Enter Left child of " << p->data << ": ";
      cin >> x;
      if(x != -1){
          t = new BinaryNode(x);
          p->left = t;
          queue.enqueue(t);
        }
      cout << "Enter Rigth child of " << p->data << ": ";
      cin >> x;
      if(x != -1){
          t = new BinaryNode(x);
          p->rigth = t;
          queue.enqueue(t);
        }
    }
}

void BinaryTree::preOrder(BinaryNode *node){
  if(node){
      cout << node->data << " ";
      preOrder(node->left);
      preOrder(node->rigth);
    }
}

void BinaryTree::inOrder(BinaryNode *node){
  if(node){
      inOrder(node->left);
      cout << node->data << " ";
      inOrder(node->rigth);
    }
}

void BinaryTree::postOrder(BinaryNode *node){
  if(node){
      postOrder(node->left);
      postOrder(node->rigth);
      cout << node->data << " ";
    }
}

void BinaryTree::levelOrder(BinaryNode *node){
  Queue queue;

  if(!node)
    return;

  cout << node->data << " ";
  queue.enqueue(node);

  while(!queue.isEmpty()){
      node = queue.dequeue();

      if(node->left){
          cout << node->left->data << " ";
          queue.enqueue(node->left);
        }
      if(node->rigth){
          cout << node->rigth->data << " ";
          queue.enqueue(node->rigth);
        }
    }
}

int BinaryTree::count(BinaryNode *node){
  if(node)
    return count(node->left) + count(node->rigth) + 1;

  return 0;
}

int BinaryTree::height(BinaryNode *node){
  int x = 0;
  int y = 0;

  if(!node)
    return 0;

  x = height(node->left);
  y = height(node->rigth);

  if(x > y)
    return x + 1;
  else
    return y + 1;
}

int BinaryTree::leafsCount(BinaryNode *node){
  int x = 0;
  int y = 0;

  if(!node)
    return 0;

  x = height(node->left);
  y = height(node->rigth);

  if(!node->left && !node->rigth)
    return x + y + 1;
  else
    return x + y;
}
