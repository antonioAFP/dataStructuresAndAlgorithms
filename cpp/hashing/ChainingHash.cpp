#include "ChainingHash.h"
#include <iostream>
#include "SingleList.h"

using namespace std;

ChainingHash::ChainingHash(int size)
{
  this->size = size;
  hashTable = new SingleList[size];
}

int ChainingHash::hash(int key){
  return key % size;
}

void ChainingHash::insert(int key){
  int index = hash(key);

  hashTable[index].sortedInsert(key);
}

int ChainingHash::search(int key){
  int index = hash(key);
  SingleNode *node = hashTable[index].linearSearch(hashTable[index].first, key);

  if(node)
    return node->data;
  else
    return -1;

}
