//decorator for mario game

#include <bits/stdc++.h>
using namespace std;

class Character{
    public:
    virtual string getAbilities() = 0;
};

class Mario : public Character {
public:
    string getAbilities() {
        return "Mario";
    }
};

class CharacterDecorator : public Character {
protected:
    Character* character; 
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }

};