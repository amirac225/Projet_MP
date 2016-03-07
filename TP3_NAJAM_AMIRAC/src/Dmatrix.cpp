#include "Darray.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Dmatrix.h"
#include "Dvector.h"
#include <cassert>

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

Dvector Dmatrix::operator * (const Dvector& vector){
  assert(m == vector.size()) ; 

  Dvector vect = Dvector(m,0) ;
  for (int i = 0; i < n ; i++){
    for (int j = 0 ; j < m; j++){
      vect(i) += (*this)(i,j) * vector(j) ;
    }
  }
  return vect ; 
}


double & Dmatrix::operator() (int i , int j){
  return (*(Darray *)this)(j + i*n) ;
}

const double & Dmatrix::operator() (int i , int j) const{
  return (*(Darray *)this)(j + i*n) ;
}

Dvector Dmatrix::line (int pos) {
  assert (pos >= 0 && pos < m) ;
  Dvector line (n, 0) ;
  for (int j = 0 ; j < m ; j++){
    line(j) = (*this)(pos, j) ;
  }
  return line ;
}

Dvector Dmatrix::column (int pos){
  assert(pos >= 0 && pos < m);
  Dvector column (n, 0) ;
  for (int i = 0; i < n; i++){
    column(i) = (*this)(i,pos) ;
  }
  return column ;
}
/* TODO */
Dmatrix Dmatrix::operator * (const Dmatrix & matrix) {
  Dmatrix mat(matrix) ; 
  return mat ; 
}

/* TODO */
Dmatrix& Dmatrix::operator = (const Dmatrix& matrix){
  return *this ;
}

/* TODO */
int Dmatrix::lines() {
  return this->n ; 
}
/* TODO */ 
int Dmatrix::columns() {
  return this->m ;
}
