#pragma once

#include "Device.h"

class Printer : public Device
{
private:
    bool colored;
public:
    Printer(std::string maker = std::string("N/A"), double price = 0, 
    	Date creationDate = Date(), Country country = BG, bool colored = false);

    bool isColored() const;
    virtual double getRating() const; 

    void printOwnFields() const;
    virtual void print() const;
    virtual std::unique_ptr<Device> clone() const; 
};