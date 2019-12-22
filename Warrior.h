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
protected:
    int id, strength;
public:
    const static string DRAGON;
    const static string NINJA;
    const static string ICEMAN;
    const static string LION;
    const static string WOLF;
    /**
     * create a warrior with specified id, and strength
     * @param id
     * @param strength
     */
    Warrior(int id, int strength) : id(id), strength(strength){}

    virtual string getType() const = 0;
    virtual void printFeatures() const {}
    friend ostream& operator << (ostream & os, const Warrior& w);

    virtual ~Warrior() {
        cout << "warrior " << id << " deleted" << endl;
    };
};

class Dragon : public Warrior {
private:
    Weapon* weapon;
    double morale;
public:
    Dragon(int id, int strength, Weapon* w, double m) : Warrior(id, strength), weapon(w), morale(m) {}
    // omitted copy constructor and assignment operator because there is no need of such operation
    string getType() const override;
    void printFeatures() const override {
        cout << "it has a " << *weapon << ", and it's morale is " << morale << endl;
    }
    ~Dragon(){
        if(weapon) delete weapon;
    }
};

class Ninja : public Warrior {
private:
    vector<Weapon *> weapons;
public:
    Ninja(int id, int strength, vector<Weapon *> weapons) : Warrior(id, strength), weapons(std::move(weapons)){}

    string getType() const override;

    void printFeatures() const override {
        cout << "it has a " << *weapons[0] << " and a " << *weapons[1] << endl;
    }

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

    string getType() const override;

    void printFeatures() const override {
        cout << "it has a " << *weapon  << endl;
    }

    ~Iceman(){
        if(weapon) delete weapon;
    }
};

class Lion : public Warrior {
private:
    int loyalty;
public:
    Lion(int id, int strength, int loyalty) : Warrior(id, strength), loyalty(loyalty) {}

    void printFeatures() const override {
        cout << "it's loyalty is " << loyalty << endl;
    }

    string getType() const override;

};

class Wolf : public Warrior {

public:
    Wolf(int id, int strength) : Warrior(id, strength) {}


    string getType() const override;

};

#endif //WARCRAFT_WARRIOR_H
