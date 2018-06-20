#include "Device.h"
#include <iostream>

Device::Device(std::string maker, double price, Date creationDate, Country country) {
    this->maker = maker;
    this->price = price;
    this->creationDate = creationDate;
    this->country = country;
}

void Device::setMaker(std::string maker) {
    this->maker = maker;
}

void Device::setPrice(double price) {
    this->price = price;
}

std::string Device::getMaker() const {
    return maker;
}

double Device::getPrice() const {
    return price;
}

void Device::printOwnFields() const {
    using namespace std;
    
    shared_ptr<DateFormatter> dateFormatter = DateFormatterFactory::getDateFormatter(country);

    cout << "\tMaker: " << maker << endl;
    cout << "\tPrice: " << price << " BGN" << endl;
    cout << "\tCountry: " << CountryToString(country) << endl;
    cout << "\tCreation date: " << dateFormatter->toString(creationDate) << endl;

}