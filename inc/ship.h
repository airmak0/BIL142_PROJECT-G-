
#ifndef COSMICVOYAGER_SHIP_H
#define COSMICVOYAGER_SHIP_H

#include <memory>

#include <random>

extern std::random_device rd;
extern std::mt19937 gen;
extern std::uniform_real_distribution<float> distribution;
extern std::uniform_int_distribution<int> dist;


class ship {
public:
    ship() : health(100.0f), fuel(100.0f), money(0.0f) {};
    ship(float _health, float _fuel, float _money) : health(_health), fuel(_fuel), money(_money) {};
    virtual bool fuel_control(float fuel_amount);
    virtual int health_control();
    virtual bool escape_possibility() = 0;
    virtual int escape(float fuel_amount);
    virtual void get_damage(float damage);  // parameterized virtual
    virtual void get_damage()=0;  // non-parameterized pure-virtual
    virtual void gain_money(float amount);
    virtual int pay_money(float amount);
    virtual float calculate_points();
    virtual ~ship() = default;
    static std::shared_ptr<ship> get_ship_choice();
protected:
    float health;
    float fuel;
    float money;
};






#endif //COSMICVOYAGER_SHIP_H
