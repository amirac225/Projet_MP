// Test que l'allocation et la desallocaiton se déroule bien :

#include <iostream>
#include "Dvector.h"

using namespace std;

int main()
{
  Dvector vecteur01(50,0);
  Dvector vector02(100,3);
  Dvector vector03(0,5);
  Dvector vector04(5);
  cout << "Premier vecteur\n";
  vecteur01.display(cout);
  cout << "Second vecteur\n"; 
  vector02.display(cout);
  cout << "Troisieme vecteur\n";
  vector03.display(cout);
  cout << "Quatrieme vecteur\n";
  vector04.display(cout);
  return 0;
}
