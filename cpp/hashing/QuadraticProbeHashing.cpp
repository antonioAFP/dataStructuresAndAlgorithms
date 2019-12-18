#include "QuadraticProbeHashing.h"
#include <iostream>

using namespace std;

QuadraticProbeHashing::QuadraticProbeHashing(int size)
{
  this->size = size;
  hashTable = new int[size];

  for (int i = 0; i < size; i++)
    hashTable[i] = 0;
}

void QuadraticProbeHashing::display(){
  for (int i = 0; i < size; i++)
    cout << hashTable[i] << " ";

  cout << endl;
}

int QuadraticProbeHashing::hash(int key){
  return key % size;
}

int QuadraticProbeHashing::probe(int key){
  int index = hash(key);
  int i = 0;

  while(hashTable[(index + i*i) % size] != 0)
      i++;

  return (index + i*i) % size;
}

void QuadraticProbeHashing::insert(int key){
  int index = hash(key);

  if(hashTable[index]!= 0)
    index = probe(key);

  hashTable[index] = key;
}

int QuadraticProbeHashing::search(int key){
  int index = hash(key);
  int i = 0;

  while(hashTable[(index + i*i) % size] != key)
      i++;

  return (index + i*i) % size;
}


