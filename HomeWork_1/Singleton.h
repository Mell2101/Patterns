#pragma once
#include <iostream>
#include <mutex>

std::mutex m1;

namespace Single {
    class ChocolateBoiler {
    private:
        bool _empty;
        bool _boiled;
        ChocolateBoiler() {
            _empty = true;
            _boiled = false;
        }
        static ChocolateBoiler* _chocolateBoiler;
    public:
        static ChocolateBoiler* getBoiler();
        const bool& GetResult() const;

        ChocolateBoiler(ChocolateBoiler& other) = delete;
        void operator=(ChocolateBoiler&) = delete;

        bool isEmpty() const {
            return _empty;
        }

        bool isBoiled() const {
            return _boiled;
        }

        void fill() {
            if (isEmpty()) {
                _empty = false;
                _boiled = false;
            }
        }

        void drain() {
            if (!isEmpty() && isBoiled()) {
                _empty = true;
            }
        }

        void boil() {
            if (!isEmpty() && !isBoiled()) {
                _boiled = true;
            }
        }
    };

    ChocolateBoiler* ChocolateBoiler::_chocolateBoiler = nullptr;

    ChocolateBoiler* ChocolateBoiler::getBoiler() {
        m1.lock();
        if (_chocolateBoiler == nullptr) {
            _chocolateBoiler = new ChocolateBoiler();
        }
        m1.unlock();
        return _chocolateBoiler;
    }

    const bool& ChocolateBoiler::GetResult() const {
       
        return _boiled;
    }
    
}