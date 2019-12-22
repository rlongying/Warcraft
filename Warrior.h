//
// Created by Mengjun Wang on 2019-12-21.
//

#ifndef WARCRAFT_WARRIOR_H
#define WARCRAFT_WARRIOR_H

#include <iostream>
#include <utility>
#include <vector>
#include "Weapon.h"
using namespace std;
class Warrior {
private:
    int id, strength;
public:
    /**
     * create a warrior with specified id, and strength
     * @param id
     * @param strength
     */
    Warrior(int id, int strength) : id(id), strength(strength){}

    virtual string toString() const = 0;

    friend ostream& operator << (ostream & os, const Warrior* w);
};

class Dragon : public Warrior {
private:
    Weapon* weapon;
    double morale;
public:
    Dragon(int id, int strength, Weapon* w, double m) : Warrior(id, strength), weapon(w), morale(m) {}
    // omitted copy constructor and assignment operator because there is no need of such operation
    string toString() const override;

    ~Dragon(){
        if(weapon) delete weapon;
    }
};

class Ninja : public Warrior {
private:
    vector<Weapon *> weapons;
public:
    Ninja(int id, int strength, vector<Weapon *> weapons) : Warrior(id, strength), weapons(std::move(weapons)){}

    string toString() const override;

    ~Ninja(){
        if(!weapons.empty()) {
            for (auto w : weapons){
                delete w;
            }
        }
    }
};

class Iceman : public Warrior {
private:
    Weapon* weapon;
public:
    Iceman(int id, int strength, Weapon* w) : Warrior(id, strength), weapon(w){}

    string toString() const override;

    ~Iceman(){
        if(weapon) delete weapon;
    }
};

class Lion : public Warrior {
private:
    int loyalty;
public:
    Lion(int id, int strength, int loyalty) : Warrior(id, strength), loyalty(loyalty) {}

    string toString() const override;

};

#endif //WARCRAFT_WARRIOR_H
