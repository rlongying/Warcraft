//
// Created by Mengjun Wang on 2019-12-21.
//

#include <stdexcept>
#include "Weapon.h"

Weapon* Weapon::makeWeapon(int id) {
    switch (id) {
        case 1: return new Sword();
        case 2: return new Bomb();
        case 3: return new Arrow();
        default: throw std::invalid_argument("invalid id of weapon");
    }
}

ostream &operator<<(ostream &os, const Weapon &weapon) {
    os << weapon.toString();
    return os;
}

string Sword::toString() const {
    return std::string("a sword");
}

string Bomb::toString() const {
    return std::string("a bomb");
}

string Arrow::toString() const {
    return std::string("an arrow");
}
