#include<iostream>
#include"Pimpl.h"

class Player::User {
public:
    float hp;
    int speed;
    std::string name;

    User(float hp, int speed, const std::string& name) : hp(hp), speed(speed), name(name) {}
    
    ~User() {};
};

Player::Player(float &hp, int &speed, const std::string& name) : pImpl(new User(hp, speed, name)) {}

void Player::changeHp(int change) const {
    pImpl->hp += change;
}

void Player::changeSpeed(int change) const {
    pImpl->speed += change;
}

float Player::getHp() const {
    return pImpl->hp;
}

int Player::getSpeed() const {
    return pImpl->speed;
}

const std::string& Player::getName() const {
    return pImpl->name;
}