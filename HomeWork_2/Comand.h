#pragma once
#include <iostream>
#include <vector>
enum class Colors {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    VIOLET,
    WHITE
};

class Light {
public:
    Light() :state(false), color(Colors::WHITE) {};
    void On() {
        if (!state) {
            state = true;
        }
    };

    void Off() {
        if (state) {
            state = false;
        }
    };

    void changeColor(Colors newColor) {
        color = newColor;
    }

    bool getState() const {
        return state;
    }

private:
    bool state;
    Colors color;
};

class Command {
protected:
    Light* light;
public:
    virtual void chColor() = 0;

    virtual ~Command() {};

    void setLight(Light* newLight) {
        light = newLight;
    }
};

class ChangeColor : public Command {
    Colors col;
public:
    ChangeColor(Colors color) : col(color) {};

    void chColor() override {
        light->changeColor(col);
    }
};

class Invoker {
    std::vector<Command*> donCom;
    Light lig;
    Command* com;
public:
    Invoker() : com(nullptr) {}

    virtual ~Invoker() {
        for (Command* ptr : donCom)
            delete ptr;
    }

    void on() {
        lig.On();
    }

    void off() {
        lig.Off();
    }

    void changeColor(Colors newColor) {
        com = new ChangeColor(newColor);
        com->setLight(&lig);
        com->chColor();
        donCom.push_back(com);
    }
    void show() {
        std::cout << "Show:" << donCom.size() << std::endl;
    }
    
};