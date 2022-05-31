#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
class ICitizen {
public:
    virtual void listen(int, std::string) = 0;
};

class Doctor : public ICitizen {
private:
    int hearingPower = 100;
public:
    void listen(int voicePower, std::string) override {
    }
};

class Blacksmith : public ICitizen {
private:
    int hearingPower = 30;
public:
    void listen(int voicePower, std::string) override {
    }
};

class Child : public ICitizen {
private:
    int hearingPower = 50;
public:
    void listen(int voicePower, std::string) override {
    }
};

class Herald {
private:
    int voicePower;
    std::string announcement;
    std::vector<ICitizen*> citizens;

public:
    Herald() : citizens(citizens) {
        citizens = { new Doctor, new Child, new Blacksmith };
    }

    int getVoicePower();
    std::string getAnnouncement();
    void setVoicePower(int);
    void setAnnouncement(std::string);

    void changeAnnouncment() {

        for (const auto citizen : citizens) {
            citizen->listen(voicePower, announcement);
        }
    }
};
*/
//===================================================================
class IObserver {
public:
    virtual void listen(int, std::string) = 0;
};

class Isubject {
public:
    virtual void registerObserver(IObserver* io) = 0;
    virtual void RemoveObserver(IObserver* io) = 0;
    virtual void notifyObserver() = 0;
};

class People : public Isubject {
private:
    int voicePower;
    std::string announcement;
    std::vector<IObserver*> observer;
public:

    void registerObserver(IObserver* io) override {
        observer.push_back(io);
    };
    void RemoveObserver(IObserver* io) override {
        auto it = std::find(observer.begin(), observer.end(), io);
        observer.erase(it);
    };
    void notifyObserver() override {
        for (auto& o : observer ) {
            o->listen(voicePower, announcement);
        }
    };

    int getVoicePower() {
        return voicePower;
    };
    std::string getAnnouncement() {
        return announcement;
    };
    void setVoicePower(int i) {
        voicePower = i;
    };
    void setAnnouncement(std::string s) {
        announcement = s;
    };

};

class Child : public IObserver{
private:
    int hearingPower = 50;
public:
    void listen(int voicePower, std::string) override {
        if (voicePower = hearingPower) {
            std::cout << "I heard the news" << std::endl;
        }
    }
};

class Doctor : public IObserver {
private:
    int hearingPower = 100;
public:
    void listen(int voicePower, std::string) override {
        if (voicePower = hearingPower) {
            std::cout << "I heard the news" << std::endl;
        }
    }
};

class Blacksmith : public IObserver {
private:
    int hearingPower = 30;
public:
    void listen(int voicePower, std::string) override {
        if (voicePower = hearingPower) {
            std::cout << "I heard the news" << std::endl;
        }
    }
};