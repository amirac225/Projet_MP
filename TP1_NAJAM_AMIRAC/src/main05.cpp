// Test du constructeur qui construit à partir d'un fichier :

#include <iostream>
#include "Dvector.h"
#include <sstream>
#include <assert.h>


int main(int argc, char* argv[])
{
  std::stringstream str;
  Dvector vector01(argv[1]);
 
  vector01.display(str);
//  cout << str.str();
  assert(str.str()=="2.4\n2.5\n2.6\n");
  std::cout << "OK\n";
  return 0;
}
