
#include "normal_ship.h"

bool normal_ship::escape_possibility(){  // %50
    float rand1 = distribution(gen);
    if(rand1<=0.5f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void normal_ship::get_damage() {
    const float space_pirates_damage = 30.0f;
    health-=space_pirates_damage; // space pirates gives 30 damage to normal ship in fights.
    health_control();
}