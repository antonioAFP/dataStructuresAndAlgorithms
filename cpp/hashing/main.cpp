#include <QCoreApplication>
#include <iostream>
#include "ChainingHash.h"
#include "LinearProbingHashing.h"
#include "QuadraticProbeHashing.h"

using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  cout << endl << "ChainingHash" << endl;
  ChainingHash chaining(10);

  chaining.insert(22);
  chaining.insert(42);
  chaining.insert(12);
  chaining.insert(31);
  chaining.insert(98);
  chaining.insert(89);

  cout << "search 12: " << chaining.search(12) << endl;
  cout << "search 81: " << chaining.search(81) << endl;

  cout << endl << "LinearProbingHashing" << endl;
  LinearProbingHashing linear(10);
  linear.insert(12);
  linear.insert(25);
  linear.insert(35);
  linear.insert(26);
  linear.display();
  cout << "Key 35 found at: " << linear.search(35) << endl;
  //cout << "Key 30 found at: " << linear.search(30) << endl;

  cout << endl << "QuadraticProbeHashing" << endl;
  QuadraticProbeHashing quad(10);
  quad.insert(23);
  quad.insert(43);
  quad.insert(13);
  quad.insert(27);
  quad.display();
  cout << "Key 13 found at: " << quad.search(13) << endl;
  //cout << "Key 6 found at: " << quad.search(30) << endl;


  cout << endl;
  return a.exec();
}
