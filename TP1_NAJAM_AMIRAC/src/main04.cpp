// Test de size et du constructeur de recopie :

#include <iostream>
#include "Dvector.h"
#include <sstream>
#include <assert.h>

int main()
{
  Dvector vector01(10,7.23);
  Dvector vector02(vector01);
  Dvector vector03;
  Dvector vector04(1,-5.32);
  std::stringstream str1;
  std::stringstream str2;
 
  assert(vector01.size() == 10);
  vector01.display(str1);
  vector02.display(str2);

  assert(str1.str() == str2.str());

  assert(vector02.size() == 10);

  assert(vector03.size() == 0);

  assert(vector04.size() == 1);

  std::cout << "OK\n";

  return 0;
}
