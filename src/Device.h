#pragma once

#include <string>
#include <memory>
#include "Date.h"
#include "Country.h"
#include "DateFormatterFactory.h"

class Device
{
    std::string maker;
    double price;
    Date creationDate;
    enum Country country;
public:
    Device(std::string maker = std::string("N/A"), double price = 0, Date creationDate = Date(), Country country = BG);

    void setMaker(std::string maker);
    void setPrice(double price);

    std::string getMaker() const;
    double getPrice() const;
    virtual double getRating() const = 0; 

    void printOwnFields() const;
    virtual void print() const = 0;
    virtual std::unique_ptr<Device> clone() const = 0; 
};