
#include "quick_ship.h"

bool quick_ship::escape_possibility() {  // %75
    float rand2 = distribution(gen);
    if(rand2<=0.75f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void quick_ship::get_damage() {
    const float space_pirates_damage = 45.0f;
    health-=space_pirates_damage;  // space pirates gives 45 damage to quick ship in fights.
    health_control();
}
