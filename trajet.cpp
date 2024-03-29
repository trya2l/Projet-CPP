/*Turikumwe Fabrice E.
Allan Tarcy*/
#include "trajet.hpp"

using namespace std;

Trajet::Trajet(Escales *portDep, Escales *portArr, Navire *nav, Date *dateDepart, Date *dateArrivee) : portDepart(portDep), portArrive(portArr), navire(nav), dateD(dateDepart), dateA(dateArrivee), prix(portDepart->getPrix() + portArrive->getPrix())
{
    compagnie = navire->getCompagnie();
    compagnie->AjoutTrajet(this);
}

Trajet::~Trajet()
{
    passagers.clear();
    billets.clear();
    escales.clear();
    seconds.clear();
    matelots.clear();
    delete portDepart;
    delete portArrive;
    delete navire;
    delete compagnie;
    delete capitaine;
    delete dateD;
    delete dateA;
}

void Trajet::ajoutEscales(Escales *e)
{
    prix += e->getPrix();
    escales.push_back(e);
}
void Trajet::ajoutPassager(Passager *p, Billet *b)
{
    if (passagers.size() < navire->getCapacitePassagers())
    {
        passagers.push_back(p);
        billets.push_back(b);
    }
}
Escales *Trajet::getPortDepart()
{
    return portDepart;
}
Escales *Trajet::getPortArrive()
{
    return portArrive;
}
Compagnie *Trajet::getCompagnie()
{
    return compagnie;
}
void Trajet::setPortDepart(Escales *portDep)
{
    portDepart = portDep;
}
void Trajet::setPortArrive(Escales *portArr)
{
    portArrive = portArr;
}

Date *Trajet::getDateD()const
{
    return dateD;
}

Date *Trajet::getDateA()const
{
    return dateA;
}

void Trajet::setDateD(Date *d)
{
    dateD = d;
}

void Trajet::setDateA(Date *d)
{
    dateA = d;
}

void Trajet::afficheEscales()
{
    vector<Escales *>::iterator it;
    for (it = escales.begin(); it != escales.end(); it++)
    {
        cout << (*it)->getNom() << endl;
    }
}
void Trajet::affichePassagers()
{
    vector<Passager *>::iterator it;
    for (it = passagers.begin(); it != passagers.end(); it++)
    {
        cout << (*it)->getNom() << " " << (*it)->getPrenom() << " Categorie:" << (*it)->getCategorie() << endl;
    }
    if(passagers.empty() == true){
        cout << "Pas de passager au moment..." << endl;
    }
}
void Trajet::Affiche()
{
    cout << "Depart: " << portDepart->getNom() << " - " << *dateD << ", " << "Arrivee: " << portArrive->getNom() << " - " << *dateA << ", Prix initial: " << prix << "$" << endl;
    this->afficheEscales();
    cout << "Passager:";
    this->affichePassagers();
    cout << endl;
}

int Trajet::getPrixInitial()
{
    return prix;
}

vector<Billet *> Trajet::getBillets()
{
    return billets;
}

Capitaine *Trajet::getCapitaine()
{
    return capitaine;
}

vector<Second *> Trajet::getSeconds()
{
    return seconds;
}

vector<Matelot *> Trajet::getMatelots()
{
    return matelots;
}

void Trajet::setCapitaine(Capitaine *c)
{
    if (navire->getTonnage() <= c->getTonnage())
    {
        capitaine = c;
    }
}

void Trajet::ajouterSecond(Second *s)
{
    if (seconds.size() <= navire->getMaxSeconds() && navire->getTonnage() < s->getTonnage())
    {
        seconds.push_back(s);
    }
}
void Trajet::ajouterMatelot(Matelot *m)
{
    if (matelots.size() <= navire->getMaxMatelots())
    {
        matelots.push_back(m);
    }
}
void Trajet::ajoutPersonnel(Capitaine *cap, vector<Second *> s, vector<Matelot *> m)
{
    capitaine = cap;
    for (size_t i = 0; i < s.size(); i++)
    {
        this->ajouterSecond(s[i]);
    }
    for (size_t i = 0; i < m.size(); i++)
    {
        this->ajouterMatelot(m[i]);
    }
}