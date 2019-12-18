#ifndef LINEARPROBINGHASHING_H
#define LINEARPROBINGHASHING_H


class LinearProbingHashing
{
public:
  LinearProbingHashing(int size);
  void insert(int key);
  int hash(int key);
  int probe(int key);
  void display();
  int search(int key);

  int *hashTable;
  int size;
};

#endif // LINEARPROBINGHASHING_H
