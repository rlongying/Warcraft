//
// Created by Mengjun Wang on 2019-12-21.
//

#include "Warrior.h"

const string Warrior::DRAGON = "dragon";
const string Warrior::NINJA = "ninja";
const string Warrior::ICEMAN = "iceman";
const string Warrior::LION = "lion";
const string Warrior::WOLF = "wolf";

ostream &operator<<(ostream &os, const Warrior &w) {
    os << w.getType() << " " << w.id << " born with strength " << w.strength;
    return os;
}

string Dragon::getType() const {

    return DRAGON;
}

string Ninja::getType() const {

    return NINJA;
}

string Iceman::getType() const {

    return ICEMAN;
}

string Lion::getType() const {

    return LION;
}

string Wolf::getType() const {
    return WOLF;
}
