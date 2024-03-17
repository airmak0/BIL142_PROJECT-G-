
#include "abandoned_planet.h"

#include <iostream>

#include "space_pirates.h"

constexpr float GOLD_AMOUNT = 10.0f;

void abandoned_planet::execute(std::shared_ptr<ship> ship) {
    int gold_chance = dist(gen);
    if(gold_chance==1)
    {
        std::cout<<"you found 10 golds in abandoned planet."<<"\n";
        ship->gain_money(GOLD_AMOUNT);
    }
    else
    {
         //facing space pirates
         std::cout<<"There are space pirates in abandoned planet!!!\n";
         space_pirates temp;
         temp.execute(ship);
    }
}
