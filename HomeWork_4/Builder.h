#pragma once
#include <iostream>
#include <vector>

class Events {
public:
    virtual void getEvent() = 0;
    virtual ~Events() {};
};

class Hotel : public Events {
public:
    void getEvent() {
        std::cout << "Booking Hotel" << std::endl;
    }
};

class Park : public Events {
    void getEvent() {
        std::cout << "Park visiting" << std::endl;
    }
};

class Food : public Events {
public:
    virtual void getEvent() = 0;
    virtual ~Food() {};
};

class Dinner : public Food {
public:
    Dinner(const std::string& type) : _type("breakfast") {}
    void getEvent() {
        std::cout << "Food " << _type << std::endl;
    };
private:
    std::string _type;
};

class Lunch : public Food {
public:
    Lunch() : _type("lunch") {}
    void getEvent() {
        std::cout << "Food " << _type << std::endl;
    };
private:
    std::string _type;
};

class Breakfast : public Food {
public:
    Breakfast() : _type("breakfast") {}
    void getEvent() {
        std::cout << "Food " << _type << std::endl;
    };
private:
    std::string _type;
};

class Special : public Events {
public:
    virtual void getEvent() = 0;
    virtual ~Special() {};
};

class Skating :public Special {
public:
    Skating(const std::string& type) : _type("skating") {}
    void getEvent() {
        std::cout << _type << std::endl;
    };
private:
    std::string _type;
};

class Circus :public Special {
public:
    Circus(const std::string& type) : _type("circus") {}
    void getEvent() {
        std::cout << _type << std::endl;
    };
private:
    std::string _type;
};
//=========================================================
class Excursion {
public:
    std::vector<Events*> ve;
    
    void getEvent() const {
        for (const auto& excursion : ve) 
            excursion->getEvent();
        
    }

    virtual ~Excursion() {
        for (const auto& excursion : ve)
            delete excursion;
    }
};

class ExcursionBuilder {
protected:
    Excursion* _excursion = nullptr;
public:

    virtual void creatHotel() {};
    virtual void creatPark() {};
    virtual void creatDinner() {};
    virtual void creatLunch() {};
    virtual void creatBreakfast() {};
    virtual void creatSkating() {};
    virtual void creatCircus() {};

    virtual void createDayExcursion() {};
   
    Excursion* getExcurion() const {
        return _excursion;
    }

    virtual ~ExcursionBuilder() {
        delete _excursion;
    }
};

class DayOneBuilder : public ExcursionBuilder {
public:
    void createDayExcursion() override {
        _excursion = new Excursion;
    }

    void creatHotel() override {
        _excursion->ve.push_back(new Hotel);
    };
    void creatPark() override {
        _excursion->ve.push_back(new Park);
    };
    void creatDinner() override {
        _excursion->ve.push_back(new Dinner("Food"));
    };
};

class DayTwoBuilder : public ExcursionBuilder {
public:
    void createDayExcursion() override {
        _excursion = new Excursion;
    }
    void creatHotel() override {
        _excursion->ve.push_back(new Hotel);
    }
    void creatPark() override {
        _excursion->ve.push_back(new Park);
    }
    void creatBreakfast() override {
        _excursion->ve.push_back(new Breakfast);
    }
    void creatDinner() override {
        _excursion->ve.push_back(new Dinner("Dinner"));
    };
    void creatSkating() override{
        _excursion->ve.push_back(new Skating("skating"));
    }
};

class DayThreeBuilder : public ExcursionBuilder {
public:
    void createDayExcursion() override {
        _excursion = new Excursion;
    }
 
    void creatPark() override {
        _excursion->ve.push_back(new Park);
    }
    void creatBreakfast() override {
        _excursion->ve.push_back(new Breakfast);
    }
    void creatLunch() override {
        _excursion->ve.push_back(new Lunch);
    };
    void creatCircus() override {
        _excursion->ve.push_back(new Circus("Circus"));
    }
};

class Guest {
public:
    Excursion* creatExcurion(ExcursionBuilder& build) {
        build.createDayExcursion();
        build.creatHotel();
        build.creatPark();
        build.creatBreakfast();
        build.creatLunch();
        build.creatDinner();
        build.creatSkating();
        build.creatCircus();
        return build.getExcurion();

    }
};