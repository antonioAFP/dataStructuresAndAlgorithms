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

  cout << "Enter roo value: ";
  cin >> x;

  root = new BinaryNode(x);

  if(!root){
      cout << "Tree can not be created";
      return;
    }

  queue.enqueue(root);

  while(!queue.isFull()){
      p = queue.dequeue();
      cout << "Enter Left child";
      cin >> x;
      if(x != -1){
          t = new BinaryNode(x);
          p->left = t;
          queue.enqueue(t);
        }
      cout << "Enter Rigth child";
      cin >> x;
      if(x != -1){
          t = new BinaryNode(x);
          p->rigth = t;
          queue.enqueue(t);
        }
    }


}
