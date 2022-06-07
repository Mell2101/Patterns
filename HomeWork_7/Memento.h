#pragma once
#include<iostream>
#include<fstream>


class Player {
private:
    float hp;
    int speed;
    std::string name;
public:
    Player(float hp, int speed, const std::string& name) : hp(hp), speed(speed), name(name) {}

    void changeSpeed(int change) {
        speed += change;
    }

    void changeHp(int change) {
        hp += change;
    }

    float getHp() const {
        return hp;
    }

    int getSpeed() const {
        return speed;
    }

    const std::string& getName() const {
        return name;
    }

    Memento createMemento() {
        Memento m(hp, speed, name);
        m.serialize();
        return m;
    }

    void reinstate(Memento& m) {
        m.deserialize();
        name = m.getName();
        speed = m.getSpeed();
        hp = m.getHp();
    }
};


class Memento {
private:
    int hp;
    int speed;
    std::string name;
public:
    Memento() : hp(100), speed(0), name("name") {};
    Memento(float h, int s, std::string n) : hp(h), speed(s), name(n) {};
    Memento(const Memento& _m) : hp(_m.hp), speed(_m.speed), name(_m.name) {};

    float getHp() {
        return hp;
    }

    int getSpeed() {
        return speed;
    }

    std::string getName() {
        return name;
    }

    void serialize() {
        std::ofstream out(name, speed, std::ios::binary);
        out.write(name.c_str(), name.size());
        out.write(reinterpret_cast<char*>(speed), sizeof(speed));
    }

    void deserialize() {
        std::ifstream in(name, speed, std::ios::binary);
        name.resize(1024);
        in.read(name.data(), name.size());
        name.resize(in.gcount());
        in.read(reinterpret_cast<char*>(speed), sizeof(speed));
    }



};
