// Test que l'allocation et la desallocaiton se déroule bien :

#include <iostream>
#include "Dvector.h"
#include <assert.h>
#include <sstream>
int main()
{
  Dvector vecteur01(5,0);
  Dvector vector02(100,3);
  Dvector vector03(0,5);
  Dvector vector04(5);
  // std::cout << "Premier vecteur\n";
  // vecteur01.display(std::cout);
  // std::cout << "Second vecteur\n"; 
  // vector02.display(std::cout);
  // std::cout << "Troisieme vecteur\n";
  // vector03.display(std::cout);
  // std::cout << "Quatrieme vecteur\n";
  // vector04.display(std::cout);
  assert(vecteur01.size() == 5) ; 
  assert(vector02.size() == 100) ; 
  assert(vector03.size() == 0) ; 
  assert(vector04.size() == 5) ; 
  std::stringstream str01 ; 
  std::stringstream str03 ;
  vecteur01.display(str01) ; 
  assert(str01.str() == "0\n0\n0\n0\n0\n") ; 
  vector03.display(str03) ; 
  assert(str03.str() == "") ; 
  std::cout << "OK\n" ; 
  return 0;
}
