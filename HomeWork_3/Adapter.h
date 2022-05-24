#pragma once
#include <iostream>

class IShape {
public:
    virtual void scale(double scale_percentage) = 0;// ������������ ������
    virtual void rotate(double angle) = 0;          // ������������ ������
    virtual void flip() = 0;                        // �������� ������
};

class Figure : public IShape {
private:
    int width;
    int height;
    double angle;
    bool isFlipped;
public:
    
    Figure(int width, int height) : width(width), height(height), angle(0.0), isFlipped(false) {}

    void scale(double scale_percentage) override {
        width *= scale_percentage;
        height *= scale_percentage;
    }

    void rotate(double angle) override {
        angle += angle;
    }

    void flip() override {
        isFlipped = !isFlipped;
    }
};

class IText {
    virtual void newSize(int size) = 0;   // �������� ������ ������ ������
    virtual void rotate(double angle) = 0;   // ������������ �����
    virtual void reverse() = 0;              // �������� ����������� ������
};

class Text : public IText {
private:
    int size;
    double angle;
    bool isReversed;
    std::string text;
public:
    Text(const std::string text, int size, double angle, bool isReversed) : text(text), size(size), angle(0.0), isReversed(false) {}

    void newSize(int newSize) override {
        size = newSize;
    }

    void rotate(double newAngle) override {
        angle = newAngle;
    }

    void reverse() override {
        for (int i = 0; i < text.size() / 2; ++i) {
            char c = text[i];
            text[i] = text[text.size() - 1 - i];
            text[text.size() - 1 - i] = c;
        }
    }
};

class TextAdapter : public Figure {
    Text _text;
public:
    
    
    void scale(double scale_percentage) {
        _text.newSize(scale_percentage);
    }

    void rotate(double angle) {
        _text.rotate(angle);
    }

    void flip() {
        _text.reverse();
    }

};