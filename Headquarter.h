//
// Created by Mengjun Wang on 2019-12-21.
//

#ifndef WARCRAFT_HEADQUARTER_H
#define WARCRAFT_HEADQUARTER_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
#include "Warrior.h"
#include "Constants.h"

using namespace std;

class Headquarter {
private:
    string name;
    string warriorSequence[WARRIOR_TYPES];
    map<string, int> strengthMap;
    map<string, vector<Warrior *>> warriors;
    int totalStrength;
    int warriorId = 1; // id of warriors starts from 1
    Warrior *currentWarrior = nullptr;
    bool stopped = false;
public:
    /**
     * create a headquarter
     * @param name
     * @param seq an array of 5 element specifying the order of creating warriors
     * @param strengths an array of 5 element specifying strength of "dragon, ninja, iceman, lion, wolf" respectively
     */
    Headquarter(string name, string seq[WARRIOR_TYPES], map<string, int> strengthMap, int total)
            : name(std::move(name)), strengthMap(std::move(strengthMap)), totalStrength(total) {

        for (int i = 0; i < WARRIOR_TYPES; ++i) {
            warriorSequence[i] = seq[i];
        }
    }

    bool produce(int time);
    bool hasStopped() {return stopped;}

    void createWarrior(const string&);

    inline static double roundToTwoPoints(double val) {
        return round( val * 100.0) / 100.0;
    }

    static string timeToString(int time);

    ~Headquarter(){
        for(auto & warrior : warriors){
            for(Warrior* p : warrior.second){
                delete p;
            }
        }
    }
};


#endif //WARCRAFT_HEADQUARTER_H
