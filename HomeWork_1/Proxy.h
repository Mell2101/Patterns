#pragma once
#include <iostream>
#include <map>
#include<vector>
#include<ctime>
#include<algorithm>

#pragma warning(disable : 4996)


class ISellSystem {
public:
    virtual void changePrice(std::string, float) = 0;
    virtual void sellProduct(std::string) = 0;
    virtual void addProduct(std::string, size_t) = 0;
};


class Automaton : ISellSystem {
private:
    std::string location;
    double recieved_money;
    double spent_money;
    std::map <std::string, float> goods_price;
    std::map <std::string, size_t> goods_count;

public:
    Automaton(const std::string& location, double recievedMoney) : location(location), recieved_money(recievedMoney) {
        spent_money = 0.0;
    }

    void changePrice(std::string name, float newPrice) override {
        goods_price[name] = newPrice;
    }

    void sellProduct(std::string name) {
        if (goods_count[name] > 0) {
            recieved_money += goods_price[name];
        }
        else {
            std::cerr << "Not enough goods" << std::endl;
        }
    }

    void addProduct(std::string name, size_t count) {
        goods_count[name] += count;
    }

    double allMoneyReport() const {
        return recieved_money - spent_money;
    }

    const std::string& getLocationReport() const {
        return location;
    }

    std::map <std::string, size_t> goodsCountReport() {
        return goods_count;
    };

    std::map <std::string, float> goodsPriceReport() {
        return goods_price;
    };

};

class Proxy : public ISellSystem {
    int _time_1 = 0, 
        _time_2 = 0;
    Automaton* automat;

    bool CheckTimeReport(int time_1, int time_2) const {
        if (abs(time_2 - time_1) >= 5) {
            return true;
        }
        else
        {
            return false;
        }
    };

    void LogTime() {
      
        std::vector<int> time_2;

        std::time_t now_1 = std::time(nullptr);
        struct tm* u_1 = std::localtime(&now_1);

        time_2.push_back(u_1->tm_sec);

        _time_2 = time_2[0];
    }

public:

    Proxy() : automat(new Automaton("New York", 1)) {
        std::time_t now = std::time(nullptr);
        struct tm* u = std::localtime(&now);

        std::vector<int> time_1;

        time_1.push_back(u->tm_sec);

        _time_1 = time_1[0];
    }

    void changePrice(std::string name, float price) {
        automat->changePrice(name, price);
    };

    void sellProduct(std::string name) {
        automat->sellProduct(name);
    }

    void addProduct(std::string name, size_t num) {
        automat->addProduct(name, num);
    }


    void getReportMoney()  {
        this->LogTime();
        double sumMoney = 0;
        if (this->CheckTimeReport(_time_1, _time_2 )) {
            std::cout << "Money now: " << automat->allMoneyReport() << std::endl;
            sumMoney = automat->allMoneyReport();
        }
        else
        {
            std::cout << "Money now: " << sumMoney << std::endl;
        }
    }

    void getReportLocation(){
        this->LogTime();
        std::string Loc = "I`am here ";

        if (this->CheckTimeReport(_time_1, _time_2)) {
            std::cout << "Location: " << automat->getLocationReport() << std::endl;
            Loc = automat->getLocationReport();
        }
        else
        {
            std::cout << "Location: " << Loc << std::endl;
        }
    }

    void getReportCount(){
        this->LogTime();
        auto m = automat->goodsCountReport();
        
        if (this->CheckTimeReport(_time_1, _time_2)) {
            
            for ( const auto& item : m) {
                std::cout << "Product: " << item.first << ", Amount: " << item.second << std::endl;
            }
            
        }
        else
        {
            for (const auto& item : m) {
                std::cout << "Product: " << item.first << ", Amount : " << item.second << std::endl;
            }
        }
    }

    void getPriceCount()  {
        this->LogTime();
        auto m = automat->goodsPriceReport();
        if (this->CheckTimeReport(_time_1, _time_2)) {
            
            
            for (const auto& item : m) {
                std::cout << "Product: " << item.first << ", Price: " << item.second << std::endl;
            }
              
        }
        else
        {
            for (const auto& item : m) {
                std::cout << "Product: " << item.first << ", Price: " << item.second << std::endl;
            }
        }
    }

    void getAllReports()  {
     
         getReportMoney();
         getReportLocation();
         getReportCount();
         getPriceCount();
    }

    
};


    
