#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Date
{
private:
    int hh, mm, ss;

public:
    Date(int h = 0, int m = 0, int s = 0);
    ~Date();
    int getHH();
    int getMM();
    int getSS();
    friend bool operator==(Date const &d1, Date const &d2);
    friend ostream &operator<<(ostream flux, Date const &d);
};

#endif