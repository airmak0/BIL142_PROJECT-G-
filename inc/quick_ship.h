
#ifndef COSMICVOYAGER_QUICK_SHIP_H
#define COSMICVOYAGER_QUICK_SHIP_H

#include "ship.h"

class quick_ship : public ship{
public:
    quick_ship() : ship() {}
    quick_ship(float _health, float _fuel, float _money) : ship(_health,_fuel,_money) {}
    bool escape_possibility() override;
    void get_damage() override;
};



#endif //COSMICVOYAGER_QUICK_SHIP_H
