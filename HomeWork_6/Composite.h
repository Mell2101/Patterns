#pragma once
#include<iostream>
#include<vector>

class Food {
public:
    virtual int getPrice() = 0;
    virtual std::string getName() = 0;

    virtual ~Food() {};
};

class Pancake : public Food {
private:
    std::string name;
    float price;
public:
    Pancake(const std::string& name, float price) : name(name), price(price) {}
    int getPrice() {
        return price;
    };
    std::string getName() {
        return name;
    };
};

class Icecream : public Food {
private:
    std::string name;
    float price;
public:
    Icecream(const std::string& name, float price) : name(name), price(price) {}
    int getPrice() {
        return price;
    };
    std::string getName() {
        return name;
    };
};

class Beverage : public Food {
private:
    std::string name;
    float price;
public:
    Beverage(const std::string& name, float price) : name(name), price(price) {}
    int getPrice() {
        return price;
    };
    std::string getName() {
        return name;
    };
};

class CompositeFood : public Food {
    std::vector<Food*> comboFood;
public:
    int getPrice() override {
        int price = 0;
        for (auto food : comboFood) {
            price += food->getPrice();
        }
        return price;
    }

    std::string getName() override {
        std::string name;
        for (auto food : comboFood) {
            name = food->getPrice();
        }
        return name;
    }

    void chooseFood(Food* food) {
        comboFood.push_back(food);
    }

    virtual ~CompositeFood() {
        for (auto food : comboFood) {
            delete food;
        }
    }
};

CompositeFood* ComboBreakfast(){
    CompositeFood* breakfast = new CompositeFood;

    breakfast->chooseFood(new Pancake("Pancake", 12));
    breakfast->chooseFood(new Pancake("Pancake", 12));
    breakfast->chooseFood(new Pancake("Pancake", 12));
    breakfast->chooseFood(new Icecream("Icecream", 8));
    breakfast->chooseFood(new Beverage("Coffee", 5));

    return breakfast;
}

CompositeFood* ComboLunch() {
    CompositeFood* lunch = new CompositeFood;

    lunch->chooseFood(new Pancake("Pancake", 12));
    lunch->chooseFood(new Pancake("Pancake", 12));
    lunch->chooseFood(new Pancake("Pancake", 12));
    lunch->chooseFood(new Beverage("Juice",2));  

    return lunch;
}






