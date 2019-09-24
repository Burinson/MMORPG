#include "character.h"

Character::Character()
{
    this->exp = 0;
    this->level = 1;
    this->guild = "NaN";
}

string Character::getName() const
{
    return name;
}

void Character::setName(const string &value)
{
    name = value;
}

string Character::getGender() const
{
    return gender;
}

void Character::setGender(const string &value)
{
    gender = value;
}

string Character::getType() const
{
    return type;
}

void Character::setType(const string &value)
{
    type = value;
}

string Character::getGuild() const
{
    return guild;
}

void Character::setGuild(const string &value)
{
    guild = value;
}

size_t Character::getExp() const
{
    return exp;
}

void Character::setExp(const size_t &value)
{
    exp = value;
}

map<Weapon, int> Character::getInventory() const
{
    return inventory;
}

void Character::setInventory(const map<Weapon, int> &value)
{
    inventory = value;
}

vector<Quest> Character::getLog() const
{
    return log;
}

void Character::setLog(const vector<Quest> &value)
{
    log = value;
}

size_t Character::getLevel() const
{
    return level;
}

void Character::setLevel(const size_t &value)
{
    level = value;
}

Character::Character(string name, string gender, string type)
{
    this->name = name;
    this->gender = gender;
    this->type = type;
}
