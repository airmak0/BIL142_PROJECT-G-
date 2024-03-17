
#include "ship.h"
#include "normal_ship.h"
#include "quick_ship.h"
#include "strong_ship.h"

#include <iostream>

bool ship::fuel_control(float fuel_amount) {
    if(fuel>=fuel_amount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ship::escape(float fuel_amount) {
    fuel-=fuel_amount;
    if(escape_possibility())
    {
        std::cout<<"you have escaped from space pirates."<<"\n";
        return 1;
    }
    else
    {
        std::cout<<"you couldn't escape."<<"\n";
        return 0;
    }
}

int ship::health_control(){
    if(health<=0)
    {
        health=0;
        return 0;
    }
    else
        return 1;
}

void ship::get_damage(float damage) {
    health-=damage;
    health_control();
}

void ship::gain_money(float amount) {
    money+=amount;
}

int ship::pay_money(float amount) {
    if(money<amount)
        return 0;
    else {
        money -= amount;
        return 1;
    }
}

std::shared_ptr<ship> ship::get_ship_choice(){
    int ship_choice{0};
    std::cout<<"Captain which ship you want to ride with ?"<<"\n";
    std::cout<<"1 : Normal ship\n2 : Quick ship\n3 : Strong ship\n";
    std::cout<<"Enter your choice : ";
    std::cin>>ship_choice;
    while(ship_choice<1 || ship_choice>3)
    {
        std::cout<<"Please give valid choice : ";
        std::cin>>ship_choice;
    }
    if(ship_choice == 1)
        return  std::make_shared<normal_ship>(100.0f,100.0f,0.0f);
    else if(ship_choice == 2)
        return  std::make_shared<quick_ship>(100.0f,100.0f,0.0f);
    else
        return  std::make_shared<strong_ship>(100.0f,100.0f,0.0f);
}

float ship::calculate_points() {
    return (5*fuel)+(10*health)+(10*money);
}
