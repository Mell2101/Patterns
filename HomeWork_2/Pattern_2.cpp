#include <iostream>
#include "Abstract Factory.h"
#include "Comand.h"
#include "Decorator.h"

void exersize_1() {

    client client;
    CheesePizzaFactory CPF;

    Menu* cheesPizzaMenu = client.cPizza(CPF);
    cheesPizzaMenu->info("GreekPizza");
}

void exersize_2() {
   
    Invoker in;

    char s = '1';
    char check;
    std::cout << "Turn on - Y" << ' ' << "Turn off - N" << std::endl;
    std::cin >> check;

    while (s != 'e') {
        
        
        if (check == 'Y') {
            std::cout << "What color do you want ?" << std::endl
                << "0 - White" << std::endl
                << "1 - RED" << std::endl
                << "2 - ORANGE" << std::endl
                << "3 - YELLOW" << std::endl
                << "4 - GREEN" << std::endl
                << "5 - CYAN" << std::endl
                << "6 - BLUE" << std::endl
                << "7 - VIOLET" << std::endl
                << "8 - Disco mode" << std::endl
                << "--------------------" << std::endl;

            std::cin >> s;
            switch (s)
            {
            case'0':
                in.changeColor(Colors::WHITE);
                std::cout << "White" << std::endl << "-------------" << std::endl;
                break;
            case'1':
                in.changeColor(Colors::RED);
                std::cout << "Red" << std::endl << "-------------" << std::endl;
                break;
            case'2':
                in.changeColor(Colors::ORANGE);
                std::cout << "Orange" << std::endl << "-------------" << std::endl;
                break;
            case'3':
                in.changeColor(Colors::YELLOW);
                std::cout << "Yellow" << std::endl << "-------------" << std::endl;
                break;
            case'4':
                in.changeColor(Colors::GREEN);
                std::cout << "Green" << std::endl << "-------------" << std::endl;
                break;
            case'5':
                in.changeColor(Colors::CYAN);
                std::cout << "Cyan" << std::endl << "-------------" << std::endl;
                break;
            case'6':
                in.changeColor(Colors::BLUE);
                std::cout << "Blue" << std::endl << "-------------" << std::endl;
                break;
            case'7':
                in.changeColor(Colors::VIOLET);
                std::cout << "Violet" << std::endl << "-------------" << std::endl;
                break;
            case'8':
                in.changeColor(Colors::RED);
                in.changeColor(Colors::ORANGE);
                in.changeColor(Colors::YELLOW);
                in.changeColor(Colors::GREEN);
                in.changeColor(Colors::CYAN);
                in.changeColor(Colors::BLUE);
                in.changeColor(Colors::VIOLET);

                break;
            default:
                break;
            }
        }
        else
        {
            in.off();
            std::cout << "The Bulb turn off" << std::endl;
            break;
        }
    }
    

}

void exersize_3() {
    HouseBlend *hous = new HouseBlend;
    
    
    Decorator* SugarDecor = new AddSugar(hous, "sugar");
    Decorator* CDecor = new AddChocolate(hous, "Chocolate");

    CDecor->cost();
    SugarDecor->cost();
    
    double sum = hous->cost() + SugarDecor->cost();
    std::cout << sum << std::endl;
}

int main()
{
    
   // exersize_1();
   // exersize_2();
    exersize_3();
    return 0;
}

