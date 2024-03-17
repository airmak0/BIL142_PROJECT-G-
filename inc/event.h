
#ifndef COSMICVOYAGER_EVENT_H
#define COSMICVOYAGER_EVENT_H

#include <memory>

#include "ship.h"

#include <vector>

class event {
public:
    event() = default;
    virtual void execute(std::shared_ptr<ship> ship) = 0;
    static std::vector<std::shared_ptr<event>> all_events_vector();
    static std::vector<std::shared_ptr<event>> event_shuffling(std::vector<std::shared_ptr<event>> all_events);
    static void execute_events(std::vector<std::shared_ptr<event>> events,const std::shared_ptr<ship>& ship);
    virtual ~event() = default;
};




#endif //COSMICVOYAGER_EVENT_H
