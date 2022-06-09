#pragma once
#include <iostream>

class Monsters {
protected:
    int size;
public:
    Monsters() : size(100) {};
    virtual int getHp()  = 0;
    virtual int getAtk()  = 0;
    virtual int getDef()  = 0;

    virtual ~Monsters() {};

    virtual Monsters* clone() = 0;
};

class Monster : public Monsters {
    int hp;
    int atk;
    int def;
    std::string type;
public:
    Monster() : hp(0), atk(0), def(0), type("0") {};
    Monster(const Monster& mon) {
        hp = mon.hp;
        atk = mon.atk;
        def = mon.def;
        type = mon.type;
        size = mon.size;
    }

    Monster(int hp, int atk, int def, const std::string& type, int sizee) : hp(hp), atk(atk), def(def), type(type) {
        size = sizee;
    }


    void changeHp(int change) {
        hp += change;
    }

    void changeAtk(int change) {
        atk += change;
    }

    void changeDef(int change) {
        def += change;
    }

    int getHp() override {
        return hp;
    }

    int getAtk() override {
        return atk;
    }

    int getDef() override {
        return def;
    }

    Monsters* clone() override {
        return new Monster(*this);
    }

};


