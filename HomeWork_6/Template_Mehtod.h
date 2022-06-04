#pragma once
#include <iostream>
#include<vector>

class Paint {
public:
    void openFile(const std::string& filename) {
        std::cout << "Open file " << filename << std::endl;
    }

    virtual void readFile() = 0;
    virtual void draw() = 0;
    virtual void final() = 0;

    virtual void Image() final {
        openFile("Image");
        readFile();
        draw();
        final();
    }
};

struct Pixel  {
    int x;
    int y;
    std::string color;

    void draw() {
        std::cout << "(" << x << ", " << y << ", " << color << ") ";
    };
};

class BitmapImage : public Paint {        // ��������� �����������
private:
    std::vector<Pixel*> pixels;     // ��� �������, ������� �������� � �����
    std::vector<Pixel> buffer;      // ��� �������, ������� �� ������ ��� ����������� �� ������
public:

    void readFile() override {
        readBitmapFile();
    }

    void readBitmapFile() {
        for (const auto pixel : pixels) {
            buffer.push_back(*pixel);      // ��������� ������ �������� �� ����� � �����
        }
    };

    void draw() override {
        for ( auto &pixel : buffer) {
            pixel.draw();      // ������ ������ ������� �� ������
        }
    }

    void final() override {
        std::cout << "Drawing bitmap image complete" << std::endl;
    }
};

struct Figure {
    int x;
    int y;
    std::string figure;

    void draw() {
        std::cout << "(" << x << ", " << y << ", " << figure << ") ";
    };
};

class VectorImage : public Paint {        // ��������� �����������
private:
    std::vector<Figure*> figures;     // ��� �������� �����, ������� �������� � �����
    std::vector<Figure> buffer;       // ��� �������� �����, ������� �� ������ ��� ����������� �� ������
public:

    void readFile() override {
        readVectorFile();
    }

    void readVectorFile() {
        for (const auto figure : figures) {
            buffer.push_back(*figure);        // ��������� ������ ����� �� ����� � �����
        }
    };

    void draw() override{
        for (auto &figure : buffer) {
            figure.draw();         // ������ ������ ������ �� ������
        }
    }

    void final() override{
        std::cout << "Drawing vector image complete" << std::endl;
    }
};

