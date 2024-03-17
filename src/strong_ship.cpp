
#include "strong_ship.h"

bool strong_ship::escape_possibility() {  // %25
    float rand3 = distribution(gen);
    if (rand3 <= 0.25f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void strong_ship::get_damage() {
    const float space_pirates_damage = 15.0f;
    health-=space_pirates_damage;  // space pirates gives 15 damage to strong ship in fights.
    health_control();
}