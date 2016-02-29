#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
#include <cstring>
#include <stdarg.h>

/** @brief Classe Dvector modelisant un vecteur réel de taille m_taille.
    @author NAJA Mohamed Reda
    @date Janvier 2016
    */

class Dvector
{
        /**
            Tableau vecteur alloué dynamiquement lors de la construction de l'objet.
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
        Dvector& operator=(Dvector const& dvector);
        Dvector& operator+=(double const& dvector);
        Dvector& operator-=(double const& dvector);
        Dvector& operator*=(double const& dvector);
        Dvector& operator/=(double const& dvector);
        Dvector& operator+=(Dvector const& dvector);
        Dvector& operator-=(Dvector const& dvector);
        double& operator()(int const& i) const;
        /** Methode qui modifie la taille du vecteur en question 
        */
        void resize(int const& taille, ...);
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
        friend std::ostream& operator<<(std::ostream &flux, Dvector const& dvector);
    	friend std::istream& operator>>(std::istream &flux, Dvector & dvector);
        friend bool operator==(Dvector const& dvector1, Dvector const& dvector2);
        /** Destructeur.
        */
        virtual ~Dvector();
};

Dvector operator+(double const& dvector1, Dvector const& dvector2);
Dvector operator+(Dvector const& dvector2, double const& dvector1);
Dvector operator-(double const& dvector1, Dvector const& dvector2);
Dvector operator-(Dvector const& dvector2, double const& dvector1);
Dvector operator*(double const& dvector1, Dvector const& dvector2);
Dvector operator*(Dvector const& dvector2, double const& dvector1);
Dvector operator/(Dvector const& dvector2, double const& dvector1);
Dvector operator+(Dvector const& dvector1, Dvector const& dvector2);
Dvector operator-(Dvector const& dvector1, Dvector const& dvector2);
Dvector operator-(Dvector const& dvector);
bool operator!=(Dvector const& dvector1, Dvector const& dvector2);
#endif // DVECTOR_H
