#pragma once

#include "Device.h"

class PC : public Device
{
private:
    std::string os;
    int ram;
    int hdd;
public:
    PC(std::string maker = std::string("N/A"), double price = 0, 
        Date creationDate = Date(), Country country = BG, std::string os = std::string("N/A"), int ram = 0, int hdd = 0);

    std::string getOs() const;
    int getRam() const;
    int getHdd() const;
    virtual double getRating() const;

    void printOwnFields() const;
    virtual void print() const;
    
    virtual std::shared_ptr<Device> clone() const;
};