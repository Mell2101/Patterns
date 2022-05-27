#pragma once
#include<iostream>

// Implementor
class DrawingImplementor {
public:
    virtual void drawRectangle(double) = 0;

    virtual ~DrawingImplementor() {
    }
};

// Abstraction
class Shape {
public:
    virtual void draw() = 0; // low-level
 //   virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

//==================================================

class Pencil : public DrawingImplementor {
public:
    void drawRectangle(double d) override {

        std::cout << "1";
    }
};

class Brush : public DrawingImplementor {
public:
    void drawRectangle(double d) override {
        std::cout << "12";
    }
};

class Rectangle : public Shape {
    double d0;
    Pencil* _pen;
    Brush* _b;
public:
    Rectangle(Pencil* pen,double d) : _pen(pen) ,d0(d) {};
    Rectangle(Brush* b, double d) : _b(b), d0(d) {};
    void draw() override {
        if (_pen) {
            _pen->drawRectangle(d0);
        }
        else if(_b)
        {
            _b->drawRectangle(d0);
        }
    }
};