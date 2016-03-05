#include "Darray.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Dmatrix.h"

/* Les Constructeurs : */

/* Initialisation d'un vecteur à partir d'une taille et d'un argument facultatif */
/* Necessite que taille >= 0 */
Dmatrix::Dmatrix(int nb_lines, int nb_col , double arg) : Darray(nb_lines*nb_col, arg)
{    
}

/* Surcharge du constructeur de recopie */
Dmatrix::Dmatrix(Dmatrix const& dmatrix) : Darray(dmatrix)
{
  
}


/* Destructeur */
Dmatrix::~Dmatrix()
{
    std::cout << "Destruction de la matrice" << std::endl;
    delete [] m_double;
}
