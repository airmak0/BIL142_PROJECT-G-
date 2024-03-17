
#ifndef COSMICVOYAGER_NORMAL_SHIP_H
#define COSMICVOYAGER_NORMAL_SHIP_H

#include "ship.h"

class normal_ship : public ship{
public:
    normal_ship() : ship() {}
    normal_ship(float _health, float _fuel, float _money) : ship(_health,_fuel,_money) {}
    bool escape_possibility() override;
    void get_damage() override;
};


#endif //COSMICVOYAGER_NORMAL_SHIP_H
