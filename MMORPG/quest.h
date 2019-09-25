#ifndef QUEST_H
#define QUEST_H
#include <iostream>
using namespace std;
class Quest {
public:
    string getName() const;
    void setName(const string &value);

    int getExp() const;
    void setExp(const int &value);

    int getUnlock_level() const;
    void setUnlock_level(const int &value);

    Quest();
    Quest(string name, int exp, int unlock_level);

private:
    string name;
    int exp;
    int unlock_level;
};

#endif // QUEST_H

string Quest::getName() const
{
return name;
}

void Quest::setName(const string &value)
{
name = value;
}

int Quest::getExp() const
{
return exp;
}

void Quest::setExp(const int &value)
{
exp = value;
}

int Quest::getUnlock_level() const
{
return unlock_level;
}

void Quest::setUnlock_level(const int &value)
{
    unlock_level = value;
}

Quest::Quest()
{
    this->exp = 0;
    this->unlock_level = 1;
}

Quest::Quest(string name, int exp, int unlock_level)
{
    this->name = name;
    this->exp = exp;
    this->unlock_level = unlock_level;
}
