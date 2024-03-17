#include "inc/event.h"
#include "inc/ship.h"
#include <memory>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
std::uniform_int_distribution<int> dist(0,1);

int main()
{
   std::vector<std::shared_ptr<event>> all_events = event::all_events_vector();
   std::vector<std::shared_ptr<event>> selected_events = event::event_shuffling(all_events);
   // random 5 events from events pool
   std::shared_ptr<ship> MyShip = ship::get_ship_choice();
   event::execute_events(selected_events,MyShip);



    return 0;
}