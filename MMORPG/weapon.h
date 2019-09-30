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
    Weapon(string name, int lethality, int level, int price);

    int getLevel() const;
    void setLevel(int value);

    int getPrice() const;
    void setPrice(int value);

private:
    string name;
    int lethality;
    int level;
    int price;
};

#endif // WEAPON_H

inline string Weapon::getName() const
{
return name;
}

inline void Weapon::setName(const string &value)
{
name = value;
}

inline int Weapon::getLethality() const
{
return lethality;
}

inline void Weapon::setLethality(const int &value)
{
    lethality = value;
}

inline Weapon::Weapon()
{
    this->lethality = 1;
}

inline Weapon::Weapon(string name, int lethality, int level, int price)
{
    this->name =  name;
    this->lethality = lethality;
    this->level = level;
    this->price = price;
}

inline int Weapon::getLevel() const
{
return level;
}

inline void Weapon::setLevel(int value)
{
level = value;
}

inline int Weapon::getPrice() const
{
return price;
}

inline void Weapon::setPrice(int value)
{
price = value;
}
