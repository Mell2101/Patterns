#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include "Singleton.h"
#include "Proxy.h"

#pragma warning(disable : 4996)

void f1() {
    Single::ChocolateBoiler* chocolateBoiler_1 = Single::ChocolateBoiler::getBoiler();
    chocolateBoiler_1->fill();
    chocolateBoiler_1->drain();
    chocolateBoiler_1->boil();
    std::cout << chocolateBoiler_1->GetResult() << std::endl;
}

void f2() {
    Single::ChocolateBoiler* chocolateBoiler_2 = Single::ChocolateBoiler::getBoiler();
    std::cout << chocolateBoiler_2->GetResult() << std::endl;
}

void exercize_1() {
    
    Single::ChocolateBoiler* chocolateBoiler_1 = Single::ChocolateBoiler::getBoiler();
    chocolateBoiler_1->fill();
    chocolateBoiler_1->drain();
    chocolateBoiler_1->boil();
    std::cout << chocolateBoiler_1->GetResult() << std::endl;

    Single::ChocolateBoiler* chocolateBoiler_2 = Single::ChocolateBoiler::getBoiler();
    std::cout << chocolateBoiler_2->GetResult() << std::endl;

    std::cout << "=======================" << std::endl;
    std::thread th1(f1);
    std::thread th2(f2);

    th1.join();
    th2.join();
}
//=====================================================
void exercize_2() {
    
    Proxy prox;
    prox.addProduct("Cooks", 12);
    prox.changePrice("Cooks", 10);
    prox.sellProduct("Cooks");
    
    prox.getAllReports();
    _sleep(5000);
    std::cout << "--------------------------------" << std::endl;
    prox.getAllReports();


   // prox.getReportLocation();
   // _sleep(5000);
   // prox.getReportLocation();
   // _sleep(10000);
   // prox.getReportCount();
    
    
   
}

int main()
{
    exercize_1();
    std::cout << "==============================" << std::endl;
    exercize_2();

    return 0;

}

