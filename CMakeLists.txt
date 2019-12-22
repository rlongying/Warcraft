cmake_minimum_required(VERSION 3.15)
project(Warcraft)

set(CMAKE_CXX_STANDARD 14)

add_executable(Warcraft main.cpp Warrior.cpp Warrior.h Weapon.cpp Weapon.h Headquarter.cpp Headquarter.h Constants.h)