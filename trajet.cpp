#include "trajet.hpp"

using namespace std;

Trajet::Trajet(string pd, string pa, int pi, Navire *nav, Date *depart, Date *arrivee)
{
    portDepart = pd;
    portArrive = pa;
    prix = pi;
    navire = nav;
    dateD = depart;
    dateA = arrivee;
    compagnie = nav->getCompagnie();
    compagnie->AjoutTrajet(this);
}

Trajet::~Trajet() {}

void Trajet::ajoutEscales(Escales *e)
{
    prix += e->getPrix();
    escales.push_back(e);
}
void Trajet::ajoutPassager(Passager *p)
{
    passagers.push_back(p);
}
string Trajet::getPortDepart()
{
    return portDepart;
}
string Trajet::getPortArrive()
{
    return portArrive;
}
Compagnie *Trajet::getCompagnie()
{
    return compagnie;
}
void Trajet::setPortDepart(string pd)
{
    portDepart = pd;
}
void Trajet::setPortArrive(string pa)
{
    portArrive = pa;
}

Date *Trajet::getDateD()
{
    return dateD;
}

Date *Trajet::getDateA()
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
        cout << (*it)->getNom() << " " << (*it)->getPrenom() << (*it)->getCategorie() << endl;
    }
}
void Trajet::Affiche()
{
    cout << "Depart: " << this->getPortDepart() << " " << *dateD << ", "
         << "Arrivee: " << this->getPortArrive() << " " << *dateA << ", Prix:" << prix << "€" << endl;
    this->afficheEscales();
    cout << "Passagers:" << endl;
    this->affichePassagers();
}

int Trajet::getPrixInitial()
{
    return prix;
}

vector<Billet *> Trajet::getBillets()
{
    return billets;
}

void Trajet::ajouterBillet(Billet *b)
{
    billets.push_back(b);
}

Capitaine *Trajet::getCapitaine()
{
    return navire->getCapitaine();
}

vector<Second *> Trajet::getSeconds()
{
    return navire->getSeconds();
}

vector<Matelot *> Trajet::getMatelots()
{
    return navire->getMatelots();
}