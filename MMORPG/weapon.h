#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
using namespace std;
class Weapon {
public:
    string getName() const;
    void setName(const string &value);

    int getLethality() const;
    void setLethality(const int &value);

    Weapon();
    Weapon(string name, int lethality);

private:
    string name;
    int lethality;
};

#endif // WEAPON_H

string Weapon::getName() const
{
return name;
}

void Weapon::setName(const string &value)
{
name = value;
}

int Weapon::getLethality() const
{
return lethality;
}

void Weapon::setLethality(const int &value)
{
    lethality = value;
}

Weapon::Weapon()
{
    this->lethality = 1;
}

Weapon::Weapon(string name, int lethality)
{
    this->name =  name;
    this->lethality = lethality;
}
