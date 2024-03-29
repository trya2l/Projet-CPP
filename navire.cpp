/*Turikumwe Fabrice E.
Allan Tarcy*/
#include "navire.hpp"

using namespace std;

Navire::Navire(int i, string n, int t, int ms, int mm, int cm, int cp) : id(i), nom(n), tonnage(t), maxSeconds(ms), maxMatelots(mm), capaciteMarchandise(cm), capacitePassagers(cp)
{
}
Navire::Navire(int i, string n, int t, int ms, int mm, int cm, Compagnie *c, int cp) : id(i), nom(n), compagnie(c), tonnage(t), maxSeconds(ms), maxMatelots(mm), capaciteMarchandise(cm), capacitePassagers(cp)
{
    compagnie->AjoutNavire(this);
}

Navire::~Navire()
{
    //trajets.clear();
    for (size_t i = 0; i < trajets.size(); i++)
    {
        delete trajets[i];
    }
    delete compagnie;
}

int Navire::getId()
{
    return id;
}
string Navire::getNom()const
{
    return nom;
}
int Navire::getTonnage()
{
    return tonnage;
}
int Navire::getCapaciteMarchandise()
{
    return capaciteMarchandise;
}

int Navire::getCapacitePassagers()
{
    return capacitePassagers;
}

int Navire::getMaxSeconds()
{
    return maxSeconds;
}
int Navire::getMaxMatelots()
{
    return maxMatelots;
}

void Navire::setId(int i)
{
    id = i;
}
void Navire::setNom(string n)
{
    nom = n;
}
void Navire::setTonnage(int t)
{
    tonnage = t;
}
void Navire::setCapaciteMarchandise(int c)
{
    capaciteMarchandise = c;
}
Compagnie *Navire::getCompagnie()
{
    return compagnie;
}
void Navire::setMaxSeconds(int ms)
{
    maxSeconds = ms;
}
void Navire::setMaxMatelots(int mm)
{
    maxMatelots = mm;
}
void Navire::setCompagnie(Compagnie *c)
{
    compagnie = c;
}

NavireFret::NavireFret(int i, string n, int t, int ms, int mm, int cm) : Navire(i, n, t, ms, mm, cm)
{
}

NavireFret::NavireFret(int i, string n, int t, int ms, int mm, int cm, Compagnie *c) : Navire(i, n, t, ms, mm, cm, c)
{
}

NavirePassager::NavirePassager(int i, string n, int t, int ms, int mm, int cm, int cp) : Navire(i, n, t, ms, mm, cm, cp)
{
}

NavirePassager::NavirePassager(int i, string n, int t, int ms, int mm, int cm, Compagnie *c, int cp) : Navire(i, n, t, ms, mm, cm, c, cp)
{
}