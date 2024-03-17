
#ifndef COSMICVOYAGER_ASTEROID_BELT_H
#define COSMICVOYAGER_ASTEROID_BELT_H


#include <memory>

#include "event.h"


class asteroid_belt : public event{
public:
    void execute(std::shared_ptr<ship> ship) override;
};




#endif //COSMICVOYAGER_ASTEROID_BELT_H
