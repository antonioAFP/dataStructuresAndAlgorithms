#include "BinarySearchTree.h"
#include <iostream>
#include "BinaryNode.h"
#include "Stack.h"

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

BinaryNode * BinarySearchTree::search(int key){
  BinaryNode *cursor = root;

  while(cursor){
      if(key == cursor->data)
        return cursor;
      else if (key < cursor->data)
        cursor = cursor->left;
      else
        cursor = cursor->rigth;
    }

  return nullptr;
}

BinaryNode * BinarySearchTree::insertRecursive(BinaryNode *node, int key){
  if(!node){
      BinaryNode *newNode = new BinaryNode(key);
      return newNode;
    }
  if(key < node->data)
    node->left = insertRecursive(node->left, key);
  else if(key > node->data)
    node->rigth = insertRecursive(node->rigth, key);
  else
    return node;
  //return  nullptr;
}

BinaryNode * BinarySearchTree::inPredecesor(BinaryNode *node){
  while(node && node->rigth)
    node = node->rigth;
  return node;
}

BinaryNode * BinarySearchTree::inSuccessor(BinaryNode *node){
  while(node && node->left)
    node = node->left;
  return node;
}

BinaryNode * BinarySearchTree::deleteNode(BinaryNode *node, int key){
  BinaryNode *tmp = nullptr;

  if(!node)
    return nullptr;
  if(!node->left && !node->rigth){
      if(node == root)
        root = nullptr;

      delete node;
      return nullptr;
    }

  if(key < node->data)
    node->left = deleteNode(node->left, key);
  else if(key > node->data)
    node->rigth = deleteNode(node->rigth, key);
  else{
      if(height(node->left) > height(node->rigth)){
          tmp = inPredecesor(node->left);
          node->data = tmp->data;
          node->left = deleteNode(node->left, node->data);
        }else{
          tmp = inSuccessor(node->rigth);
          node->data = tmp->data;
          node->rigth = deleteNode(node->rigth, node->data);
        }
    }

  return node;
}

void BinarySearchTree::createFromPreorder(int *preorderArr, int n){
  Stack stack;
  BinaryNode *tmp;
  BinaryNode *pointer = nullptr;
  int i = 0;

  root = new BinaryNode(preorderArr[i++]);
  pointer = root;

  while(i < n){
      if(preorderArr[i] < pointer->data){
          tmp = new BinaryNode(preorderArr[i++]);
          pointer->left = tmp;
          stack.push(pointer);
          pointer = tmp;
        }else {
          if(preorderArr[i] > pointer->data && preorderArr[i] < stack.stackTop()->data){
              tmp = new BinaryNode(preorderArr[i++]);
              pointer->rigth = tmp;
              pointer = tmp;
            }else{
              pointer = stack.pop();
            }
        }
    }
}
