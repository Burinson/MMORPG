#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
using namespace std;
class Weapon {
public:
    string getName() const;
    void setName(const string &value);

    size_t getLethality() const;
    void setLethality(const size_t &value);

    Weapon();
    Weapon(string name, size_t lethality);

private:
    string name;
    size_t lethality;
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

size_t Weapon::getLethality() const
{
return lethality;
}

void Weapon::setLethality(const size_t &value)
{
    lethality = value;
}

Weapon::Weapon()
{
    this->lethality = 1;
}

Weapon::Weapon(string name, size_t lethality)
{
    this->name =  name;
    this->lethality = lethality;
}
