#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

/* Constructeur par défaut surchargé */
Dvector::Dvector() : m_double(0), m_taille(0)
{
    std::cout << "Appel du constructeur par defaut" << std::endl;
    m_double = new double[m_taille];
}

/* Initialisation d'un vecteur à partir d'un fichier se trouvant à str */
Dvector::Dvector(std::string str) : m_double(0), m_taille(0)
{
    std::cout << "Appel du constructeur faisant appel au fichier " << str << std::endl;
    /* Ouverture du fichier */
    std::ifstream file(str.c_str());
    if(file)
    {
        double tmp;
        /* Calcul de la taille du vecteur */
        while(!file.eof())
        {
            m_taille++;
            file >> tmp;
        }
        m_taille--;
        /* Fermeture puis reouverture du fichier et construcion du vecteur */
        file.clear();
        file.seekg(0,std::ios::beg);
        m_double = new double[m_taille];
        for(int i = 0; i < m_taille; i++)
        {
            file >> m_double[i];
        }
        file.close();
    }
    else
    {
        m_double = new double[m_taille]; 
    }
}
/* Initialisation d'un vecteur à partir d'une taille et d'un argument facultatif */
/* Necessite que taille >= 0 */
Dvector::Dvector(int taille, double arg) : m_double(0), m_taille(taille)
{
    std::cout << "Appel du constructeur initialisant à partir d'une taille et d'un argument " << std::endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = arg;
    }
}

/* Surcharge du constructeur de recopie */
Dvector::Dvector(Dvector const& dvector) : m_double(0), m_taille(dvector.m_taille)
{
    std::cout << "Appel du constructeur de recopie " << std::endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = dvector.m_double[i];
    }
}

/* Affichage du vecteur */
void Dvector::display(std::ostream& str) const
{
    for(int i = 0; i < m_taille; i++)
    {
        str << m_double[i] << std::endl;
    }
}

/* Renvoi la taille du vecteur */
int Dvector::size() const
{
    return m_taille;
}

/* Rempli le vecteur selon la loi uniforme sur [0,1] */
void Dvector::fillRandomly()
{
    srand(time(0));
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = rand()/(double)RAND_MAX;
    }
}

/* Destructeur */
Dvector::~Dvector()
{
    std::cout << "Destruction du vecteur" << std::endl;
    delete [] m_double;
}
