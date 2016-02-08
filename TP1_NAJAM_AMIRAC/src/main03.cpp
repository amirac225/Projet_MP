// Test du constructeur de recopie et du remplissage uniforme :

#include <iostream>
#include "Dvector.h"
#include <assert.h>
#include <sstream>
int main()
{
  Dvector vector01(4,7.23);
  Dvector vector02(vector01);
  assert(vector01.size() == 4) ; 
  std::stringstream str01 ;
  std::stringstream str02 ; 
  vector01.display(str01) ; 
  assert(str01.str() == "7.23\n7.23\n7.23\n7.23\n") ; 
  assert(vector02.size() == 4) ;
  vector02.display(str02) ; 
  assert(str02.str() == "7.23\n7.23\n7.23\n7.23\n") ;
  std::cout << "OK\n" ; 
  return 0;
}
