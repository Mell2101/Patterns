#pragma once
#include <iostream>

class Pizza {
public:
    virtual void prepare(std::string);
    virtual void bake() {};
    virtual void cut() {};
    virtual void box() {};
};

class CheesePizza :public Pizza {};
class GreekPizza :public Pizza {};
class PepperoniPizza :public Pizza {};

Pizza* orderPizza(std::string type) {
    Pizza* pizza = nullptr;
    if (type == "cheese") {
        pizza = new CheesePizza;
    }
    else if (type == "greek") {
        pizza = new GreekPizza;
    }
    else if (type == "pepperoni") {
        pizza = new PepperoniPizza;
    }
    return pizza;
}
//======================================================
class PizzaFactory {
public:
    virtual Pizza* creatPizza() = 0;
    virtual ~PizzaFactory() {};
};

class CheesePizzaFactory : public PizzaFactory {
public:
    Pizza* creatPizza() override {
        return new CheesePizza;
    }
};

class GreekPizzaFactory : public PizzaFactory {
public:
    Pizza* creatPizza() override {
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory : public PizzaFactory {
public:
    Pizza* creatPizza() override {
        return new PepperoniPizza;
    }
};