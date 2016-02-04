// Test de la question 1

#include <iostream>
#include "Dvector.h"

using namespace std;

int main()
{
  cout << "Premiere écriture \n";
  Dvector x; x = Dvector(3,1.);
  x.display(cout);
  cout << "Deuxieme écriture :\n";
  Dvector y = Dvector(3,1.);
  y.display(cout);
  cout << "Troisieme écriture :\n";
  Dvector z(Dvector(3,1.));
  return 0;
}