#include "PC.h"
#include <iostream>

PC::PC(std::string maker, double price, Date creationDate, Country country, 
    std::string os, int ram, int hdd)
    : Device(maker, price, creationDate, country) 
{
    this->os = os;
    this->ram = ram;
    this->hdd = hdd;
}

std::string PC::getOs() const {
    return os;
}

int PC::getRam() const {
    return ram;
}

int PC::getHdd() const {
    return hdd;
}

// rating = (price + RAM + HDD) / 2
double PC::getRating() const {
    double rating = (getPrice() + getRam() + getHdd()) / 2.0;
    return rating;
}

void PC::printOwnFields() const {
    using namespace std;
    cout << "\tOS: " << os << endl;
    cout << "\tRAM: " << ram << " GB"  << endl;
    cout << "\tHDD: " << hdd << " GB"  << endl;
}

void PC::print() const {
    std::cout << "PC:" << std::endl;
    Device::printOwnFields();
    printOwnFields();
}

std::unique_ptr<Device> PC::clone() const {
    return std::unique_ptr<Device>(new PC(*this));
}