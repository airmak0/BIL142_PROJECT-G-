
#include "event.h"
#include "asteroid_belt.h"
#include "abandoned_planet.h"
#include "space_pirates.h"

#include <iostream>

constexpr int EVENTCOUNTER = 5;

std::vector<std::shared_ptr<event>> event::all_events_vector(){
    std::vector<std::shared_ptr<event>> events;

    events.emplace_back(std::make_shared<asteroid_belt>());
    events.emplace_back(std::make_shared<abandoned_planet>());
    events.emplace_back(std::make_shared<space_pirates>());
    // if ı create more events, ı can add here more.

    return events;
}

std::vector<std::shared_ptr<event>> event::event_shuffling(std::vector<std::shared_ptr<event>> all_events){
    std::vector<std::shared_ptr<event>> events;
    std::uniform_int_distribution<> distribution2(0,static_cast<int>(all_events.size()-1));
    for(int i=0; i<EVENTCOUNTER; ++i)
    {
        int random_index = distribution2(gen);
        events.emplace_back(all_events.at(random_index));
    }

    return events;
}

void event::execute_events(std::vector<std::shared_ptr<event>> events,const std::shared_ptr<ship>& ship){
    for(int i=0; i<EVENTCOUNTER; ++i)
    {
        std::cout<<"************ "<<i+1<<". event"<<" *************\n";
        events.at(i)->execute(ship);
        if(ship->health_control()){  // if health is not 0 (ship haven't sunk.)
            // game continues
        }
        else {
            std::cout << "Your ship has sunk.\n";  // ship got destroyed. (health=0)
            break;
        }
        std::cout<<"\n";
    }
    std::cout<<"Congrats your point is : "<<ship->calculate_points();
}