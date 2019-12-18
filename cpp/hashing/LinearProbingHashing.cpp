#include "LinearProbingHashing.h"
#include <iostream>

using namespace std;

LinearProbingHashing::LinearProbingHashing(int size)
{
  this->size = size;
  hashTable = new int[size];

  for (int i = 0; i < size; i++)
    hashTable[i] = 0;
}

void LinearProbingHashing::display(){
  for (int i = 0; i < size; i++)
    cout << hashTable[i] << " ";

  cout << endl;
}

int LinearProbingHashing::hash(int key){
  return key % size;
}

int LinearProbingHashing::probe(int key){
  int index = hash(key);
  int i = 0;

  while(hashTable[(index + i) % size] != 0)
      i++;

  return (index + i) % size;
}

void LinearProbingHashing::insert(int key){
  int index = hash(key);

  if(hashTable[index]!= 0)
    index = probe(key);

  hashTable[index] = key;
}

int LinearProbingHashing::search(int key){
  int index = hash(key);
  int i = 0;

  while(hashTable[(index + i) % size] != key)
      i++;

  return (index + i) % size;
}


