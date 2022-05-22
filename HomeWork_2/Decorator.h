#pragma once
#include<iostream>


class Beverage {            // Абстрактный класс
public:
   // virtual std::string getDescription() const ;
    virtual double cost() const = 0;
    virtual ~Beverage() {}
};

class HouseBlend : public Beverage {   // Молотый
public:
    double cost() const override {
        return 5.5;
    }
};

class DarkRoast : public Beverage {  // Темной обжарки
public:
    double cost() const override {
        return 6.0;
    }
};

class Decaf : public Beverage {    // Без кофеина
public:
    double cost() const override {
        return 7.3;
    }
};

class Espresso : public Beverage {  // Эспрессо
public:
    double cost() const override {
        return 3.5;
    }
};

class Decorator : public Beverage {
    Beverage* _beverage;
public:
    Decorator(Beverage* bever) : _beverage(bever) {}
    /*
   std::string getDescription() const override {
       return _beverage->getDescription();
   }
   */
   double cost() const override {
       return _beverage->cost();
   }
};

class AddSugar : public Decorator {

    std::string _add;

    double Sugar() const{
        if (_add == "sugar") {
            std::cout << "You choose additives: " << _add << "; Price:" << " 1.5" << std::endl;
            return 1.5;
        }
        else if (_add == "without sugar") {
            std::cout << "You choose additives: " << _add << std::endl;
        }
       
    }
    
public:
    AddSugar(Beverage* bever, std::string add) : Decorator(bever), _add(add) {}

    double cost() const override {
        Decorator::cost();
        return Sugar();
    }
   
};

class AddCinnamon : public Decorator{

    std::string _add;

    double Cinnamon() const {
        
        std::cout << "You choose additives: " << _add << std::endl;
        return 2.5;
        
    }

public:
    AddCinnamon(Beverage* bever, std::string add) : Decorator(bever), _add(add) {}

    double cost() const override {
        Decorator::cost();
        return Cinnamon();
    }


};

class AddChocolate : public Decorator {

    std::string _add;

    double Chocolate() const {

        std::cout << "You choose additives: " << _add << std::endl;
        return 2.5;

    }

public:
    AddChocolate(Beverage* bever, std::string add) : Decorator(bever), _add(add) {}

    double cost() const override {
        Decorator::cost();
        return Chocolate();
    }


};