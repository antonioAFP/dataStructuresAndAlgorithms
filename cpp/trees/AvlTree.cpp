#include "AvlTree.h"
#include "AvlNode.h"
#include "AvlQueue.h"
#include <iostream>

using namespace std;

void AvlTree::preOrder(AvlNode *node){
  if(node){
      cout << node->data << " ";
      preOrder(node->left);
      preOrder(node->rigth);
    }
}

void AvlTree::inOrder(AvlNode *node){
  if(node){
      inOrder(node->left);
      cout << node->data << " ";
      inOrder(node->rigth);
    }
}

void AvlTree::postOrder(AvlNode *node){
  if(node){
      postOrder(node->left);
      postOrder(node->rigth);
      cout << node->data << " ";
    }
}

void AvlTree::levelOrder(AvlNode *node){
  AvlQueue queue;

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

int AvlTree::count(AvlNode *node){
  if(node)
    return count(node->left) + count(node->rigth) + 1;

  return 0;
}

int AvlTree::height(AvlNode *node){
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

int AvlTree::leafsCount(AvlNode *node){
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

/*void AvlTree::insert(int key){
  AvlNode *cursor = root;
  AvlNode *tail = nullptr;
  AvlNode *newNode = nullptr;

  if(!root){
      root = new AvlNode(key);
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

  newNode = new AvlNode(key);

  if(key < tail->data)
    tail->left = newNode;
  else
    tail->rigth = newNode;
}*/

AvlNode * AvlTree::search(int key){
  AvlNode *cursor = root;

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

int AvlTree::nodeHeight(AvlNode *node){
  int hl, hr;
  hl = node && node->left ? node->left->height : 0;
  hr = node && node->rigth ? node->rigth->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int AvlTree::balanceFactor(AvlNode *node){
  int hl, hr;
  hl = node && node->left ? node->left->height : 0;
  hr = node && node->rigth ? node->rigth->height : 0;

  return hl - hr;
}

AvlNode * AvlTree::insert(AvlNode *node, int key){
  if(!node){
      AvlNode *newNode = new AvlNode(key);
      return newNode;
    }
  if(key < node->data)
    node->left = insert(node->left, key);
  else if(key > node->data)
    node->rigth = insert(node->rigth, key);

  node->height = nodeHeight(node);
  //if(balanceFactor(node) == 2 && balanceFactor(node->left) == 1)

  return node;
}

AvlNode * AvlTree::inPredecesor(AvlNode *node){
  while(node && node->rigth)
    node = node->rigth;
  return node;
}

AvlNode * AvlTree::inSuccessor(AvlNode *node){
  while(node && node->left)
    node = node->left;
  return node;
}

AvlNode * AvlTree::deleteNode(AvlNode *node, int key){
  AvlNode *tmp = nullptr;

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


