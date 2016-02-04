// Test du constructeur de recopie et du remplissage uniforme :

#include <iostream>
#include "Dvector.h"

using namespace std;

int main()
{
  Dvector vector01(10,7.23);
  Dvector vector02(vector01);
 
  cout << "Premier vecteur :\n";
  vector01.display(cout);

  cout << "Second vecteur :\n"; 
  vector02.display(cout);

  cout << "Modification du premier vecteur :\n";
  vector01.fillRandomly();
  vector01.display(cout);

  cout << "Verification du second vecteur :\n";
  vector02.display(cout);
  return 0;
}
