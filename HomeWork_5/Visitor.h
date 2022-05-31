#pragma once
#include<iostream>
#include<vector>

class Menu {};

class Ingredient {
public:
    std::string name;
    int healthRating;
    float Calories;
    float Protein;
    float Carbs;
    float Fats;
};

class MenuItem : public Menu, public Ingredient {
private:
    std::string name;
    std::string description;
    float price;
    std::vector<Ingredient*> ingredients;
public:
    MenuItem(const std::string& name, const std::string& description, float price) : name(name),
        description(description),
        price(price) {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getDescription() const {
        return description;
    }

    float getPrice() const {
        return price;
    }
};
//===================================================

class Visitor {
public:
    
    virtual void GetState(MenuItem* mi) = 0;
    virtual void GetState(Ingredient* i) = 0;
};

class Client : public Visitor {
public:
    void GetState(Menu* m) {};
    void GetState(MenuItem* mi) {
        mi->getName();
        mi->getDescription();
        mi->getPrice();
        mi->Calories;
    };
    void GetState(Ingredient* i) {
        i->Calories;
        i->Fats;
        i->Protein;
        i->name;
        i->Carbs;
    }
};
