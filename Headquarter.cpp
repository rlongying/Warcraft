//
// Created by Mengjun Wang on 2019-12-21.
//

#include "Headquarter.h"

void Headquarter::createWarrior(const string& warrior) {
    int strength = strengthMap[warrior]; // strength needed
    totalStrength -= strength; // strength left
    Warrior * temp;
    if (warrior == Warrior::DRAGON) {
        // create dragon
        Weapon *w = Weapon::makeWeapon(warriorId % 3);
        double morale = roundToTwoPoints(totalStrength / (double) strength);
        temp = new Dragon(warriorId, strength, w, morale);

    } else if (warrior == Warrior::ICEMAN) {
        // create iceman
        Weapon *w = Weapon::makeWeapon(warriorId % 3);

        temp = new Iceman(warriorId, strength, w);
    } else if (warrior == Warrior::LION) {
        //create lion
        temp = new Lion(warriorId, strength, totalStrength);

    } else if (warrior == Warrior::NINJA) {
        Weapon *w1 = Weapon::makeWeapon(warriorId % 3);
        Weapon *w2 = Weapon::makeWeapon((warriorId + 1) % 3);
        temp = new Ninja(warriorId, strength, {w1, w2});

    } else if (warrior == Warrior::WOLF) {
        temp = new Wolf(warriorId, strength);
    } else {
        throw invalid_argument("invalid warrior name");
    }
    warriors[warrior].push_back(temp);
    warriorId ++;
    currentWarrior = temp;
}


bool Headquarter::produce(int time) {
    int warriorIndex = time % WARRIOR_TYPES;
    string type = warriorSequence[warriorIndex];
    int strength = strengthMap[type];

    int startIndex = warriorIndex;
    warriorIndex = (warriorIndex + 1) % WARRIOR_TYPES;
    while(strength > totalStrength && startIndex != warriorIndex){
        // next type
        type = warriorSequence[warriorIndex];
        strength = strengthMap[type];
        warriorIndex = (warriorIndex + 1) % WARRIOR_TYPES;
    }

    if(totalStrength >= strength) {
        createWarrior(type);
        cout << timeToString(time) << " " << name << " " << *currentWarrior
             << ", " << warriors[currentWarrior->getType()].size()
             << " " << currentWarrior -> getType()
             << " in " << name << " headquarter" << "\n";
        currentWarrior ->printFeatures();
        return true;
    }
    else {
        // stop producing
        cout << timeToString(time) << " " << name << " headquarter stops making warriors" << endl;
        stopped = true;
        return false;
    }
}

string Headquarter::timeToString(int time) {
    string res;

    if (time < 10) {
        res = "00" + to_string(time);
    } else if (time < 100) {
        res = "0" + to_string(time);
    } else {
        res = to_string(time);
    }
    return res;
}