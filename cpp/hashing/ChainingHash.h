#ifndef CHAININGHASH_H
#define CHAININGHASH_H

class SingleList;

class ChainingHash
{
public:
  ChainingHash(int size);

  int hash(int key);
  void insert(int key);
  int search(int key);

  SingleList *hashTable;
  int size;
};

#endif // CHAININGHASH_H
