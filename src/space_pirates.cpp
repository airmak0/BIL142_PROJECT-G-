
#include "space_pirates.h"

#include <iostream>

constexpr float FUEL_AMOUNT = 33.0f;  // fuel decrement in escape option

int space_pirates::get_option(const std::shared_ptr<ship>& ship) {
    if(ship->fuel_control(FUEL_AMOUNT))  // if there is enough fuel
    {
        std::cout<<"captain you have 3 options : "<<"\n";
        std::cout<<"enter 1 for fight back, enter 2 for bargain, enter 3 for runaway : ";
        int option{0};
        std::cin>>option;
        while(option<1 || option>3)
        {
            std::cout<<"Please enter valid choose : ";
            std::cin>>option;
        }
        return option;
    }
    else   // if there isn't enough fuel for escape captain can't choose escape option
    {
        std::cout<<"captain you have 2 options : "<<"\n";
        std::cout<<"enter 1 for fight back, enter 2 for bargain (not enough fuel for runaway) : ";
        int option{0};
        std::cin>>option;
        while(option<1 || option>2)
        {
            std::cout<<"Please enter valid choose : ";
            std::cin>>option;
        }
        return option;
    }
}

void space_pirates::fight(const std::shared_ptr<ship>& ship) {
    int win_chance = dist(gen);
    if(win_chance)
        std::cout<<"you won the fight."<<"\n";
    else
    {
        std::cout<<"you lost the fight."<<"\n";
        ship->get_damage();   // default damage from space pirates
    }
}

void space_pirates::bargain(const std::shared_ptr<ship>& ship, float money_amount) {
    if(!ship->pay_money(money_amount)){
        std::cout<<"you don't have enough money now you will have to fight!"<<"\n";
        fight(ship);
    }
    else{
        ship->pay_money(money_amount);
        std::cout<<"pirates have taken "<<money_amount<<" gold from you\n";
    }
}

void space_pirates::execute(std::shared_ptr<ship> ship) {  // intentional recursive call
    std::cout<<"you have faced space pirates !! \n";
    int option = get_option(ship);
    if(option == 1)    // fight option
    {
        fight(ship);
    }
    else if(option == 2)  // bargain option
    {
        float toll_chance = distribution(gen);
        float money_amount = 10.0f;  // %34 chance
        if(toll_chance > 0.34 && toll_chance <= 0.67)
        {
            money_amount = 20.0f;   // %33 chance
        }
        else if(toll_chance > 0.67)
        {
            money_amount = 30.0f;  // %33 chance
        }
        bargain(ship, money_amount);
    }
    else // runaway option
    {
        if(ship->escape(FUEL_AMOUNT)){
            // escaped
        }
        else {
            // If the ship fails to escape, face with space pirates again,
            // as an intentional gameplay mechanic. This recursive call is limited due to fuel decrement (max 3).
            space_pirates temp;
            temp.execute(ship);
        }
    }
}