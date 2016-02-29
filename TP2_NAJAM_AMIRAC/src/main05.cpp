// Test du constructeur qui construit à partir d'un fichier :

#include <iostream>
#include "Dvector.h"

using namespace std;

int main()
{
  Dvector vector01("/home/neo/Ensimag/S4/Informatique/MP/C++ Workspace/TP1_NAJAM/src/tests/tp1_test2.txt");
 
  cout << "Premier vecteur :\n";
  vector01.display(cout);

  return 0;
}
