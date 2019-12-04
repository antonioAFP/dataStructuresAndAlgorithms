#include "BinarySearchTree.h"
#include <iostream>
#include "BinaryNode.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : BinaryTree ()
{

}

void BinarySearchTree::create(){
  cout << "Method not available for BST";
}

void BinarySearchTree::insert(int key){
  BinaryNode *cursor = root;
  BinaryNode *tail = nullptr;
  BinaryNode *newNode = nullptr;

  if(!root){
      root = new BinaryNode(key);
      return;
    }

  while(cursor){
      tail = cursor;
      if(key < cursor->data)
        cursor = cursor->left;
      else if(key > cursor->data)
        cursor = cursor->rigth;
      else{
          cout << key << " is already present on the tree";
          return;
        }
    }

  newNode = new BinaryNode(key);

  if(key < tail->data)
    tail->left = newNode;
  else
    tail->rigth = newNode;

}
