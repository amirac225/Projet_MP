#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

/* Constructeur par défaut surchargé */
Dvector::Dvector() : m_double(0), m_taille(0)
{
    cout << "Appel du constructeur par defaut" << endl;
    m_double = new double[m_taille];
}

/* Initialisation d'un vecteur à partir d'un fichier se trouvant à str */
Dvector::Dvector(string str) : m_double(0), m_taille(0)
{
    cout << "Appel du constructeur faisant appel au fichier " << str << endl;
    /* Ouverture du fichier */
    ifstream file(str.c_str());
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
//        file.close();
//        file.open(str.c_str());
        file.seekg(0,ios::beg);
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
    cout << "Appel du constructeur initialisant à partir d'une taille et d'un argument " << endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = arg;
    }
}

/* Surcharge du constructeur de recopie */
Dvector::Dvector(Dvector const& dvector) : m_double(0), m_taille(dvector.m_taille)
{
    cout << "Appel du constructeur de recopie " << endl;
    m_double = new double[m_taille];
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = dvector.m_double[i];
    }
}

/* Surcharge de l'operateur d'affectation puisqu'on a surchargé un constructeur de recopie */
/*Dvector& Dvector::operator=(Dvector const& dvector)
{
    if(this != &dvector)
    {
        m_taille = dvector.m_taille;
        delete [] m_double;
        m_double = new double[m_taille];
        for(int i = 0; i < m_taille; i++)
        {
            m_double[i] = dvector.m_double[i];
        }
    }
    return *this;
}*/

/* Affichage du vecteur */
void Dvector::display(std::ostream& str) const
{
    for(int i = 0; i < m_taille; i++)
    {
        str /*<< fixed << setprecision(2) */<< m_double[i] << endl;
    }
}

/* Renvoi la taille du vecteur */
int Dvector::size() const
{
    return m_taille;
}

/* Rempli le vecteur selon la loi uniforme sur [0,1] */
int Dvector::fillRandomly()
{
    srand(time(0));
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = rand()/(double)RAND_MAX;
    }
    return 0;
}

/* Destructeur */
Dvector::~Dvector()
{
    cout << "Destruction du vecteur" << endl;
    delete [] m_double;
}
