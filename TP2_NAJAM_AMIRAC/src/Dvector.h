#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
#include <cstring>

/** @brief Classe Dvector modelisant un vecteur réel de taille m_taille.
    @author NAJA Mohamed Reda, AMIRA Chafik 
    @date Janvier 2016
    */

class Dvector
{
        /**
            Tableau vecteur alloué dynamiquement lors de la construction de l'objet.
	    Les elements du tableau sont des doubles
        */
        double* m_double;
        /**
            Taille du vecteur.
        */
        int m_taille;
	
    public:
        /** Constructeur par defaut surchargé. \n
            Initialise la taille et le pointeur à 0.
        */
        Dvector();
        /** Constructeur qui permet d'initialiser un vecteur de taille 'taille' dont les coordonnées sont toutes égales à arg.  
        */
        Dvector(int taille, double arg = 0.0);
        /** Constructeur de recopie. */
        Dvector(Dvector const& dvector);
        /** Constructeur qui construit un vecteur à partir du fichier str.
        */
        Dvector(std::string const& str);
	/**
	   Surcharge de l'operateur d'affectation
	   @param le vecteur qu'on veut affecté
	 */
        Dvector& operator=(Dvector const& dvector);
	/**
	   Surcharge de l'operateur +=
	   On ajoute le vecteur passé en paramétre avec
	   notre vecteur courant et on stocke le resultat dans le vecteur courant
	   @param le vecteur qu'on veut additioner avec notre vecteur courant
	 */
        Dvector& operator+=(double const& dvector);
	/**
	   Surcharge de l'operateur -=
	     On soustrait le vecteur passé en paramétre de
	   notre vecteur courant et on stocke le resultat dans le vecteur courant
	   @param le vecteur qu'on veut soustraire
	 */
	Dvector& operator-=(double const& dvector);
	/**
	   Surcharge de l'operateur *=
	   @param le vecteur qu'on veut multiplié avec notre vecteur courant
	 */
	Dvector& operator*=(double const& dvector);
	/**
	   Surcharge de l'operateur de division
	   @param le vecteur avec lequel on veut diviser terme à terme
	   @return le vecteur courant divisé terme à terme par le vecteur passé en paramétre
	 */
	Dvector& operator/=(double const& dvector);
	/**
	   Surcharge de l'operateur +=
	   @param le vecteur qu'on veut additionner avec notre vecteur courant
	 */
	Dvector& operator+=(Dvector const& dvector);
	/**
	   Surcharge de l'operateur -= 
	   @param le vecteur qu'on veut soustraire de notre vecteur courant
	 */
	Dvector& operator-=(Dvector const& dvector);
	/**
	   Surcharge de l'opérateur d'accession 
	   @param l'indice de la coordonnée à laquelle on veut accéder
	 */
	double& operator()(int const& i) const;
        /** Methode qui modifie la taille du vecteur en question 
        */
        void resize(int const& taille, double const& init = 0);
        /** @return La taille du vecteur.
        */
        int size() const;
        /** Methode qui construit le vecteur à partir de la loi normal sur [0,1]
        */
        void fillRandomly();
       
        /** Affiche le vecteur.
            @param str : un flux.
        */
        void display(std::ostream& str) const;
	/**
	   Surcharge du flux de sortie
	   @param flux de sortie 
	   @param vecteur qu'on veut diriger vers la sortie
	 */
        friend std::ostream& operator<<(std::ostream &flux, Dvector const& dvector);
	/**
	   Surcharge du flux d'entrée
	   @param flux d'entrée 
	   @param vecteur qu'on veut diriger vers l'entrée
	 */
	friend std::istream& operator>>(std::istream &flux, Dvector & dvector);
        friend bool operator==(Dvector const& dvector1, Dvector const& dvector2);
        /** Destructeur.
        */
        virtual ~Dvector();
};
/**
Surcharge l'operateur +
@brief On ajoute deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur somme
 */
Dvector operator+(double const& dvector1, Dvector const& dvector2);
/**
Surcharge l'operateur +
@brief On ajoute un vecteur avec un double
@param vecteur numéro 1 
@param double
@return le vecteur somme en ajoutant à chaque coordonée le double passé en paramétre
 */
Dvector operator+(Dvector const& dvector2, double const& dvector1);
/**
Surcharge l'operateur -
@brief On différence deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur différence le premier moins le dexiéme
 */
Dvector operator-(double const& dvector1, Dvector const& dvector2);
/**
Surcharge l'operateur -
@brief On enléve a un vecteur  un double
@param vecteur numéro 1 
@param double
@return le vecteur différence en soustrayant à chaque coordonée le double passé en paramétre
 */
Dvector operator-(Dvector const& dvector2, double const& dvector1);
/**
Surcharge l'operateur *
@brief On multiplie deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur produit terme 
 */
Dvector operator*(double const& dvector1, Dvector const& dvector2);
/**
Surcharge l'operateur *
@brief On multiplie un vecteur par un double
@param vecteur numéro 1 
@param double
@return le vecteur produit en multipliant  chaque coordonée par le double passé en paramétre
 */
Dvector operator*(Dvector const& dvector2, double const& dvector1);
/**
Surcharge l'operateur /
@brief On divise deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur dont les termes sont obtenus par division terme à terme du premier par le deuxiéme
 */
Dvector operator/(Dvector const& dvector2, double const& dvector1);
/**
Surcharge l'operateur +
@brief On ajoute deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur somme
 */
Dvector operator+(Dvector const& dvector1, Dvector const& dvector2);
/**
Surcharge l'operateur -
@brief On soustrait deux vecteurs terme à terme
@param vecteur numéro 1 
@param vecteur numéro 2
@return le vecteur différence le premier moins le deuxiéme 
 */
Dvector operator-(Dvector const& dvector1, Dvector const& dvector2);
/**
Surcharge l'operateur - unaire
@brief On prend l'opposé du vecteur passé en paramétre
@param vecteur numéro 1
@return le vecteur opposé
 */
Dvector operator-(Dvector const& dvector);
/**
@brief surcharge de l'operateur d'inégalité
@param vecteur 1
@param vecteur 2
@return un boolean : true si les vecteurs ne sont pas égaux et false sinon 
*/
bool operator!=(Dvector const& dvector1, Dvector const& dvector2);
#endif // DVECTOR_H
