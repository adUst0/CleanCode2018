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
    
    unique_ptr<DateFormatter> dateFormatter = DateFormatterFactory::getDateFormatter(country);

    cout << "Maker: " << maker << endl;
    cout << "Price: " << price << endl;
    cout << "Creation date: " << dateFormatter->toString(creationDate) << endl;

}