// Test de size :

#include <iostream>
#include "Dvector.h"

using namespace std;

int main()
{
  Dvector vector01(10,7.23);
  Dvector vector02(vector01);
  Dvector vector03;
  Dvector vector04(1,-5.32);
 
  cout << "Taille du premier vecteur :\n";
  cout << vector01.size() << endl;

  cout << "Taille du second vecteur :\n"; 
  cout << vector02.size() << endl;

  cout << "Taille du troisieme vecteur :\n";
  cout << vector03.size() << endl;

  cout << "Taille du quatrieme vecteur :\n"; 
  cout << vector04.size() << endl;

  return 0;
}
