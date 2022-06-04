#pragma once
#include<iostream>
#include<vector>
/*
class Calendar {
public:
    bool checkCalendar() {
        return true;  // Упрощенная реализация, должен возвращать true, если рабочий день.
    }

};

class Coffee {
private:
    Calendar* calendar;
public:
    Coffee(Calendar* calendar) : calendar(calendar) {}

    void doCoffee() {
        std::cout << "Starting coffee" << std::endl;
    }

    bool checkDayForCoffe() {
        return calendar->checkCalendar();  //Возвращаем true, если будний день
    }
};

class TeaPot {
private:
    Calendar* calendar;
public:
    TeaPot(Calendar* calendar) : calendar(calendar) {}

    void doTea() {
        if (checkDayForTea())
            std::cout << "Starting tea" << std::endl;
    }

    bool checkDayForTea() {
        return !calendar->checkCalendar();  //Возвращаем true, если выходной
    }
};

class Alarm {
private:      // О боже! Будильник хранит указатели на все устройства дома
    Calendar* cal;
    Coffee* coffee;
    TeaPot* teaPot;
public:
    Alarm(Calendar* cal, Coffee* coffee) : cal(cal), coffee(coffee) {}

    void doAlarm() {
        if (cal->checkCalendar())
            coffee->doCoffee();
        else
            teaPot->doTea();
        std::cout << "Rise and shine, Mr. Freeman" << std::endl;
    }
};
*/
//=======================================================

class Mediator;

class SmartThing {
protected:
    Mediator* pMed;
public:
    SmartThing(Mediator* M) : pMed(M) {};

    virtual bool check() { return true; };
    virtual void doIt() {};

    void setMediator(Mediator* pM) {
        this->pMed = pM;
    }
};

class Mediator {
    std::vector<SmartThing*> things;
public:
    void AddSmartThings(SmartThing* newThing) {
        things.push_back(newThing);
    }

    bool checkDay() {
        for (auto sm : things) {
           return sm->check();
        }
    }
    void Work() {
        for (auto sm : things) {
            sm->doIt();
        }
    }
   

};

class Calendar : public SmartThing {
    int num = rand() % 7;
public:
    
    Calendar(Mediator* m) : SmartThing(m) {};

    bool check() override {
        switch (num)
        {
        case(1): {
            return true;
            break;
        }
        case(2): {
            return true;
            break;
        }
        case(3): {
            return true;
            break;
        }
        case(4): {
            return true;
            break;
        }
        case(5): {
            return true;
            break;
        }
        case(6): {
            return false;
            break;
        }
        case(7): {
            return false;
            break;
        }

        default:
            break;
        }
    }
};

class Coffee : public SmartThing {
public:

    Coffee(Mediator* m) : SmartThing(m) {};

    void doIt() override {
        if (pMed->checkDay()) {
            std::cout <<"Coffee:" << "It`s work" << std::endl;
        }
        else
        {
            std::cout << "Coffee:" << "It`s sleep" << std::endl;
        }
    }
};

class TeaPot : public SmartThing{
public:
    TeaPot(Mediator* m) : SmartThing(m) {};

    void doIt() override {
        if (pMed->checkDay()) {
            std::cout << "TeaPot:" << "It`s sleep" << std::endl;
        }
        else
        {
            std::cout << "TeaPot:" << "It`s work" << std::endl;
        }
    }
    
};

class Alarm : public SmartThing {
public:
    Alarm(Mediator* m) : SmartThing(m) {};

    void doIt() override {
        pMed->Work();
    }
};