#ifndef QUEST_H
#define QUEST_H
#include <iostream>
using namespace std;
class Quest {
public:
    string getName() const;
    void setName(const string &value);

    size_t getExp() const;
    void setExp(const size_t &value);

    size_t getUnlock_level() const;
    void setUnlock_level(const size_t &value);

    Quest();
    Quest(string name, size_t exp, size_t unlock_level);

private:
    string name;
    size_t exp;
    size_t unlock_level;
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

size_t Quest::getExp() const
{
return exp;
}

void Quest::setExp(const size_t &value)
{
exp = value;
}

size_t Quest::getUnlock_level() const
{
return unlock_level;
}

void Quest::setUnlock_level(const size_t &value)
{
    unlock_level = value;
}

Quest::Quest()
{
    this->exp = 0;
    this->unlock_level = 1;
}

Quest::Quest(string name, size_t exp, size_t unlock_level)
{
    this->name = name;
    this->exp = exp;
    this->unlock_level = unlock_level;
}
