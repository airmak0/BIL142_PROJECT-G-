
#include "asteroid_belt.h"

#include <iostream>

constexpr float ASTEROID_DAMAGE = 10.0f;

void asteroid_belt::execute(std::shared_ptr<ship> ship) {
    if(ship->escape_possibility())
    {
        std::cout<<"your ship has escaped from asteroid belt."<<"\n";
    }
    else
    {
        std::cout<<"your ship got hit by an asteroid."<<"\n";
        ship->get_damage(ASTEROID_DAMAGE);
    }
}