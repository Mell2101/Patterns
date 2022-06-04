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

class BitmapImage : public Paint {        // Растровое изображение
private:
    std::vector<Pixel*> pixels;     // это пиксели, которые хранятся в файле
    std::vector<Pixel> buffer;      // это пиксели, которые мы читаем для отображение на экране
public:

    void readFile() override {
        readBitmapFile();
    }

    void readBitmapFile() {
        for (const auto pixel : pixels) {
            buffer.push_back(*pixel);      // Имитируем чтение пикселей из файла в буфер
        }
    };

    void draw() override {
        for ( auto &pixel : buffer) {
            pixel.draw();      // Рисуем каждый пиксель из буфера
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

class VectorImage : public Paint {        // Векторное изображение
private:
    std::vector<Figure*> figures;     // это описание фигур, которые хранятся в файле
    std::vector<Figure> buffer;       // это описание фигур, которые мы читаем для отображение на экране
public:

    void readFile() override {
        readVectorFile();
    }

    void readVectorFile() {
        for (const auto figure : figures) {
            buffer.push_back(*figure);        // Имитируем чтение фигур из файла в буфер
        }
    };

    void draw() override{
        for (auto &figure : buffer) {
            figure.draw();         // Рисуем каждую фигуру из буфера
        }
    }

    void final() override{
        std::cout << "Drawing vector image complete" << std::endl;
    }
};

