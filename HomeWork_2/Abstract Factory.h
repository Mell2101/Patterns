#pragma once
#include <iostream>
#include <vector>
#include <string>

class Pizza {
public:
    virtual void prepare(std::string) {};
    virtual void bake() {};
    virtual void cut() {};
    virtual void box() {};
};

class CheesePizza : public Pizza {};
class GreekPizza : public Pizza {};
class PepperoniPizza : public Pizza {};

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

class UniversalPizza : public Pizza {
    void prepare(std::string p) override {
        std::cout << "Prepare: " << p << std::endl;
    }

    void bake() override {
        std::cout << "Pizza is bake" << std::endl;
    }

    void cut() override {
        std::cout << "Pizza is cut" << std::endl;
    }

    void box() override {
        std::cout << "Pizza in the box!" << std::endl;
    }
};

class PizzaFactory {
public:
    virtual Pizza* creatPizza() = 0;
    virtual ~PizzaFactory() {};
};

class CheesePizzaFactory : public PizzaFactory {
public:
    Pizza* creatPizza() override {
        return new UniversalPizza();
    }
};



class Menu {
public:
    std::vector<Pizza*> pzz;

    void info(std::string p) const {
        for (const auto& pizza : pzz) pizza->prepare(p);
        for (const auto& pizza : pzz) pizza->bake();
        for (const auto& pizza : pzz) pizza->cut();
        for (const auto& pizza : pzz) pizza->box();
    }

    virtual ~Menu() {
        for (const auto& pizza : pzz) delete pizza;
    }

};

class client {
public:
    Menu* cPizza( PizzaFactory& factory) {
        Menu* m = new Menu;
        m->pzz.push_back(factory.creatPizza());
        return m;
    }
};