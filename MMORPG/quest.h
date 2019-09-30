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
    Quest(string name, int exp, int unlock_level, int reward);

    int getReward() const;
    void setReward(int value);

private:
    string name;
    int exp;
    int unlock_level;
    int reward;
};


inline string Quest::getName() const
{
return name;
}

inline void Quest::setName(const string &value)
{
name = value;
}

inline int Quest::getExp() const
{
return exp;
}

inline void Quest::setExp(const int &value)
{
exp = value;
}

inline int Quest::getUnlock_level() const
{
return unlock_level;
}

inline void Quest::setUnlock_level(const int &value)
{
    unlock_level = value;
}

inline Quest::Quest()
{
    this->exp = 0;
    this->unlock_level = 1;
}

inline Quest::Quest(string name, int exp, int unlock_level, int reward)
{
    this->name = name;
    this->exp = exp;
    this->unlock_level = unlock_level;
    this->reward = reward;
}

inline int Quest::getReward() const
{
return reward;
}

inline void Quest::setReward(int value)
{
reward = value;
}
#endif // QUEST_H
