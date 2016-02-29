// Test de fill res :

#include <iostream>
#include "Dvector.h"
#include <assert.h>
#include <ostream>

using namespace std;

int main()
{
  Dvector vector1(3);
  Dvector vector2(3);
  vector2.fillRandomly();
  vector1.fillRandomly();
  vector1.display(cout);
  vector2.display(cout);
  return 0;
}
