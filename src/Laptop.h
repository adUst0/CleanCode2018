#pragma once

#include "Device.h"

class Laptop : public Device
{
private:
    int ram;
    double screenSize;
public:
    Laptop(std::string maker = std::string("N/A"), double price = 0, Date creationDate = Date(), Country country = BG, int ram = 0, double screenSize = 0);

    int getRam() const;
    double getScreenSize() const;
    virtual double getRating() const; 

    void printOwnFields() const;
    virtual void print() const;
    
    virtual std::unique_ptr<Device> clone() const; 
};