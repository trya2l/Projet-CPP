#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP

#include <iostream>
#include <string>
#include <vector>

#include "compagnie.hpp"

using namespace std;

class Compagnie;
class Personnel
{
    int id;
    string nom, prenom;
    Compagnie *compagnie;

public:
    Personnel();
    Personnel(Compagnie *);
    Personnel(int, string, string);
    ~Personnel();
    int getId();
    string getNom();
    string getPrenom();
    string getCompagnie();
    void setId(int);
    void setNom(string);
    void setPrenom(string);
    void setCompagnie(Compagnie*);
};

class Capitaine : public Personnel
{
    int tonnageMax;
public:
    Capitaine(int);
    int getTonnage();
};

class Second : public Personnel
{
    int tonnageMax;
public:
    Second(int);
    int getTonnage();
};

class Matelot : public Personnel
{

public:
    Matelot();
};

#endif