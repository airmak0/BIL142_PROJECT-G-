
#ifndef COSMICVOYAGER_SPACE_PIRATES_H
#define COSMICVOYAGER_SPACE_PIRATES_H

#include "event.h"

class space_pirates : public event{
public:
    static int get_option(const std::shared_ptr<ship>& ship);
    void execute(std::shared_ptr<ship> ship) override;
    static void fight(const std::shared_ptr<ship>& ship);
    static void bargain(const std::shared_ptr<ship>& ship, float money_amount);
};

#endif //COSMICVOYAGER_SPACE_PIRATES_H
