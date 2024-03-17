
#ifndef COSMICVOYAGER_ABANDONED_PLANET_H
#define COSMICVOYAGER_ABANDONED_PLANET_H

#include "event.h"

class abandoned_planet : public event{
public:
    void execute(std::shared_ptr<ship> ship) override;
};




#endif //COSMICVOYAGER_ABANDONED_PLANET_H
