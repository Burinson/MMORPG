#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;
#include <iostream>
#include <map>
#include <quest.h>
#include <vector>
#include <weapon.h>
class Character
{
public:
    Character();
    string getName() const;
    void setName(const string &value);

    string getGender() const;
    void setGender(const string &value);

    string getType() const;
    void setType(const string &value);

    string getGuild() const;
    void setGuild(const string &value);

    int getExp() const;
    void setExp(const int &value);

    map<Weapon, int> getInventory() const;
    void setInventory(const map<Weapon, int> &value);

    vector<Quest> getLog() const;
    void setLog(const vector<Quest> &value);

    int getLevel() const;
    void setLevel(const int &value);

    Character(string name, string gender, string type);

    int getMoney() const;
    void setMoney(int value);

private:
    string name;
    string gender;
    string type;
    string guild;
    int exp;
    int level;
    int money;
    map<Weapon, int> inventory;
    vector<Quest> log;
};

#endif // CHARACTER_H
