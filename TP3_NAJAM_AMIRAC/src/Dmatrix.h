#ifndef DMATRIX_H
#define DMATRIX_H
#include "Darray.h"
#include "Dvector.h"
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

	/* Surcharges des opérateurs */
	/**
	  @brief multiplication d'une matrice par un vecteur 
	  @param Vector 
	  @return On récupérer le Dvector correspondant au produit de la matrice par le vecteur V
	**/
	Dvector operator * (const Dvector & Vector) ;

	/**
	   @brief Acceder au nombre de lignes de la matrice 
	   @return un entier égal au nombre de lignes de la matrice
	**/
	int lines() ;

	/**
	   @brief Acceder au nombre de colonnes de la matrice 
	   @return un entier égal au nombre de colonnes de la matrice
	**/
	int columns() ;


	/**
	   @brief redéfinition de l'operateur = pour l'affectation d'une matrice 
	   @param Matrix la matrice dans le membre à droite 
	   @return 
	**/
	Dmatrix& operator = (const Dmatrix& Matrix) ; 
	
	/**
	  @brief multiplication d'une matrice par une autre matrice 
	  @param Matrix 
	  @return On récupérer la Dmatrix correspondant au produit des deux matrices.
	**/
	
	Dmatrix operator * (const Dmatrix & Matrix) ;

	/** 
	    @brief Extraction d'une ligne de la matrice 
	    @param pos numero de la colonne
	    @return un Dvector correspondant à la ligne d'indice pos 
	**/
	Dvector line (int pos) ;
	
	/** 
	    @brief Extraction d'une colonne de la matrice 
	    @param pos numero de la colonne
	    @return un Dvector correspondant à la colonne d'indice pos 
	**/
	Dvector column (int pos) ;

	
	/**
	   @brief Accession à un coefficient de la matrice 
	   @param i indice de la ligne (entre 0 et n-1)
	   @param j indice de la ligne (entre 0 et m-1)
	   @return le coefficient (i,j) de la matrice. 
	**/
	double& operator() (int i , int j) ;

	/**
	   @brief Accession à un coefficient de la matrice avec const 
	   @param i indice de la ligne (entre 0 et n-1)
	   @param j indice de la ligne (entre 0 et m-1)
	   @return le coefficient (i,j) de la matrice. 
	**/
	const double& operator() (int i, int j) const ;


};

#endif // DMATRIX_H
