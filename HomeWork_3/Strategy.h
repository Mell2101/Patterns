#pragma once

#include <iostream>
#include <fstream>
#include<sstream>

enum class DivideMethod {
    ByScreenWidth,
    ByUserWidth,
    BySentence
};

class ITextWork {
public:
    virtual void Divide(DivideMethod) = 0;
};

class TextEditor : ITextWork {
private:
    size_t EditorWidth;
    std::string all_text;
public:
    TextEditor() {};
    TextEditor(const std::string& text) : all_text(text) {};
    
    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()) {
            while (std::getline(file, line))
            {
                all_text += line;
            }
        }
    }

    void PrintText() const {
        std::cout << all_text << std::endl;
    }

    void Divide(DivideMethod method) override {
        switch (method) {
        case DivideMethod::ByScreenWidth:
            DivideByScreenWidth();
            break;
        case DivideMethod::BySentence:
            DivideBySentence();
            break;
        case DivideMethod::ByUserWidth:
            DivideByUserWidth(0);
            break;
        default:
            DivideByScreenWidth();
        }
    }

    void DivideByScreenWidth() {
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
    }

    void DivideBySentence() {
        std::cout << "Divided by Sentences" << std::endl;
    }

    void DivideByUserWidth(int userWidth) {
        std::cout << "DivideByScreenWidth by screen width = " << userWidth << std::endl;
    }
};

class StrategyDivideMethod {
public:
    virtual void Metod(std::string&) = 0;

};

class  DivideByScreenWidth : public StrategyDivideMethod{
public:
    void Metod(std::string& str) override {}

    
};

class DivideBySentence : public StrategyDivideMethod {
public:
    void Metod(std::string& str) override {}
};

class DivideByUserWidth : public StrategyDivideMethod {
public:
    void Metod(std::string& str) override {}
};

class Text {
public:
    virtual ~Text() {};
    virtual void useMetod() = 0;
    virtual void setMetod(StrategyDivideMethod*) = 0;
};

class StringText : public Text {
    std::string str;
    StrategyDivideMethod* sdm;
public:
    StringText() {};
    StringText(const std::string& text) : str(text) {};

    StringText(std::ifstream& file) {
        std::string line;
        if (file.is_open()) {
            while (std::getline(file, line))
            {
                str += line;
            }
        }
    };

    void useMetod() override {
        sdm->Metod(str);
    };

    void setMetod(StrategyDivideMethod* strDM) override {
        sdm = strDM;
    }

};