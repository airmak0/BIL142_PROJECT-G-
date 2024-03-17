
#ifndef COSMICVOYAGER_STRONG_SHIP_H
#define COSMICVOYAGER_STRONG_SHIP_H

#include "ship.h"

class strong_ship : public ship{
public:
    strong_ship() : ship() {}
    strong_ship(float _health, float _fuel, float _money) : ship(_health,_fuel,_money) {}
    bool escape_possibility() override;
    void get_damage() override;
};



#endif //COSMICVOYAGER_STRONG_SHIP_H
