#pragma once
#include<iostream>

class Player {
private:
    class User;
    User* pImpl;
public:
    Player(float &hp, int &speed, const std::string& name);

    void changeSpeed(int change) const;

    void changeHp(int change) const;

    float getHp() const;  

    int getSpeed() const;

    const std::string& getName() const;
     
};

