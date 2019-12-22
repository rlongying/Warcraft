#include <iostream>
#include "Headquarter.h"

int main() {

    string redWarriors[WARRIOR_TYPES] = {"iceman", "lion", "wolf", "ninja", "dragon"};
    string blueWarriors[WARRIOR_TYPES] = {"lion", "dragon", "ninja", "iceman", "wolf"};

    int testCase;
    cin >> testCase;

    int totalStrength;
    cin >> totalStrength;

    map<string, int> strengthMap;
    for (const auto & i : WARRIORS) {
        cin >> strengthMap[i];
    }

    Headquarter red("red", redWarriors, strengthMap, totalStrength);
    Headquarter blue("blue", blueWarriors, strengthMap, totalStrength);

    int time = 0;
    while (red.produce(time) && blue.produce(time)) {
        time++;
    }

    while (!red.hasStopped()) {
        red.produce(time++);
    }

    while (!blue.hasStopped()) {
        blue.produce(time++);
    }

    return 0;
}
