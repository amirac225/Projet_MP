#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

/* Les Constructeurs : */

/* Constructeur par défaut surchargé */
Dvector::Dvector() : m_double(0), m_taille(0)
{
    srand(time(0));
    cout << "Appel du constructeur par defaut" << endl;
    m_double = new double[m_taille];
}

/* Initialisation d'un vecteur à partir d'un fichier se trouvant à str */
Dvector::Dvector(string const& str) : m_double(0), m_taille(0)
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
        /* Fermeture puis reouverture du fichier et construction du vecteur */
        file.clear();
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

/* La surcharges d'opérateurs : */

/* Surcharge de l'operateur d'affectation puisqu'on a surchargé un constructeur de recopie */
// Dvector& Dvector::operator=(Dvector const& dvector)
// {
//     if(this != &dvector)
//     {
//         m_taille = dvector.m_taille;
//         delete [] m_double;
//         m_double = new double[m_taille];
//         for(int i = 0; i < m_taille; i++)
//         {
//             m_double[i] = dvector.m_double[i];
//         }
//     }
//     return *this;
// }
//Deuxième implémentation de l'operateur
//d'affectation
Dvector& Dvector::operator=(Dvector const& dvector)
{
    if(this != &dvector)
    {
        int dim = dvector.m_taille;
	m_double = new double[dim] ;
	for (int i = 0 ; i < m_taille; i++){
	memcpy(&m_double[i], &dvector.m_double[i], sizeof(double)) ;
	}
	 
    }
    
    return *this;
}
/* Operateur d'accession : */
double& Dvector::operator()(int const& i) const
{
    return m_double[i];
}

/* Operateur de comparaison : */
bool operator==(Dvector const& dvector1, Dvector const& dvector2)
{
    for(int i = 0; i < dvector1.size(); i++)
    {
        if(dvector1.m_double[i] != dvector2.m_double[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(Dvector const& dvector1, Dvector const& dvector2)
{
    return !(dvector1 == dvector2);
}

// Doivent avoir la meme taille :
Dvector& Dvector::operator+=(Dvector const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] += dvector.m_double[i];
    }
    return *this;
}


/* Operateur d'ajout : */
Dvector operator+(Dvector const& dvector1, Dvector const& dvector2)
{
    Dvector tmpvector(dvector1);
    tmpvector += dvector2;
    return tmpvector;
}

Dvector operator-(Dvector const& dvector)
{
    return Dvector(dvector.size(),0.)-dvector;
}

// doivent avoir la meme taille :
Dvector& Dvector::operator-=(Dvector const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] -= dvector.m_double[i];
    }
    return *this;
}

/* Operateur d'ajout : */
Dvector operator-(Dvector const& dvector1, Dvector const& dvector2)
{
    Dvector tmpvector(dvector1);
    tmpvector -= dvector2;
    return tmpvector;
}

Dvector& Dvector::operator+=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] += dvector;
    }
    return *this;
}

Dvector operator+(double const& dvector1, Dvector const& dvector2)
{
    Dvector dvector(dvector2);
    dvector += dvector1;
    return dvector;
}

Dvector operator+(Dvector const& dvector2, double const& dvector1)
{
    return dvector1 + dvector2;
}

Dvector& Dvector::operator-=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] -= dvector;
    }
    return *this;
}

Dvector operator-(double const& dvector1, Dvector const& dvector2)
{
    Dvector dvector(dvector2.size(),dvector1);
    dvector -= dvector2;
    return dvector;
}

Dvector operator-(Dvector const& dvector2, double const& dvector1)
{
    return -(dvector1 - dvector2);
}

Dvector& Dvector::operator*=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] *= dvector;
    }
    return *this;
}

Dvector operator*(double const& dvector1, Dvector const& dvector2)
{
    Dvector dvector(dvector2);
    dvector *= dvector1;
    return dvector;
}

Dvector operator*(Dvector const& dvector2, double const& dvector1)
{
    return dvector1 * dvector2;
}

Dvector& Dvector::operator/=(double const& dvector)
{
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] /= dvector;
    }
    return *this;
}

Dvector operator/(Dvector const& dvector2, double const& dvector1)
{
    Dvector dvector(dvector2);
    dvector /= dvector1;
    return dvector;
}

ostream& operator<<(ostream &flux, Dvector const& dvector)
{
    int size = dvector.m_taille ;
    flux << "Vecteur de coodonnees : " ; 
    for (int i = 0 ; i < size ; i++){
	flux << dvector.m_double[i]<<endl ; 
    }
    return flux;
}

istream& operator>>(istream &flux, Dvector & dvector){
    for (int i = 0 ; i < dvector.size() ; i++){
	flux >> dvector.m_double[i];
    }	
    return flux ;
}
/* Les methodes : */

/* Affichage du vecteur */
void Dvector::display(std::ostream& str) const
{
    for(int i = 0; i < m_taille; i++)
    {
        str << m_double[i] << endl;
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
    static bool init = false ;
    if (!init){
        init = true ; 
        srand(time(0)) ; 
    }
    for(int i = 0; i < m_taille; i++)
    {
        m_double[i] = rand()/(double)RAND_MAX;
    }
}

void Dvector::resize(int const& taille, ...)
{
    double *z_double(0);
    va_list ap;
    va_start(ap, taille);
    z_double = new double[taille];

    if(taille > m_taille)
    {
        memcpy(z_double,m_double,m_taille*sizeof(double));
        for(int i = m_taille; i < taille; i++)
        {
            z_double[i] = va_arg(ap,double);
        }
    }
    else
    {
        memcpy(z_double,m_double,taille*sizeof(double));
    }
    va_end(ap);
    
    delete [] m_double;
    m_double = z_double;
    m_taille = taille;
}

/* Destructeur */
Dvector::~Dvector()
{
    cout << "Destruction du vecteur" << endl;
    delete [] m_double;
}
