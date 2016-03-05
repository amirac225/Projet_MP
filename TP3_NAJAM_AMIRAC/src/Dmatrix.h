#ifndef DMATRIX_H
#define DMATRIX_H
#include "Darray.h"

/** @brief Classe Dmatrix modelisant une matrice réelle de taille n * m
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

class Dmatrix : public Darray{
 private :
  int m ;
  int n ;
 public :
  /** Constructeur qui permet d'initialiser une matric de taille nb_lines * nb_col dont les coordonnées sont toutes égales à arg.  
        */
  Dmatrix(int nb_lines, int nb_col, double arg = 0.0);
        /** Constructeur de recopie. */
  Dmatrix(Dmatrix const& dvector);



        /** Destructeur.
        */
        virtual ~Dmatrix();
};

#endif // DMATRIX_H
