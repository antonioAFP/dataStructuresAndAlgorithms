#ifndef QUADRATICPROBEHASHING_H
#define QUADRATICPROBEHASHING_H


class QuadraticProbeHashing
{
public:
  QuadraticProbeHashing(int size);
  void insert(int key);
  int hash(int key);
  int probe(int key);
  void display();
  int search(int key);

  int *hashTable;
  int size;
};

#endif // QUADRATICPROBEHASHING_H
