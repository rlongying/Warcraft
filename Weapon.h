//
// Created by Mengjun Wang on 2019-12-21.
//

#ifndef WARCRAFT_WEAPON_H
#define WARCRAFT_WEAPON_H

#include <iostream>

using namespace std;

class Weapon {
public:
    /**
     * create a weapon give a id
     * @param id  1-sword, 2-bomb, 3-arrow
     * @return a pointer of Weapon type (Weapon*)
     */
    static Weapon *makeWeapon(int id);

    virtual string toString() const = 0;
    virtual ~Weapon() = 0;

    friend ostream &operator<<(ostream &os, const Weapon &weapon);
};


class Sword : public Weapon {
private:
    int id = 1;
public:

    string toString() const override;
    ~Sword() override = default;
};

class Bomb : public Weapon {
private:
    int id = 2;
public:
    string toString() const override;
    ~Bomb() override = default;
};

class Arrow : public Weapon {
private:
    int id = 3;
public:
    string toString() const override;
    ~Arrow() override = default;
};

#endif //WARCRAFT_WEAPON_H
