#include "Laptop.h"
#include <iostream>

Laptop::Laptop(std::string maker, double price, Date creationDate, 
    Country country, int ram, double screenSize)
    : Device(maker, price, creationDate, country) 
{
    this->ram = ram;
    this->screenSize = screenSize;
}

int Laptop::getRam() const {
    return ram;
}

double Laptop::getScreenSize() const {
    return screenSize;
}

// rating = (price + RAM) / 2
double Laptop::getRating() const {
    double rating = (getPrice() + getRam()) / 2.0;
    return rating;
}

void Laptop::printOwnFields() const {
    using namespace std;
    cout << "\tRAM: " << ram << " GB"  << endl;
    cout << "\tScreen size: " << screenSize << " inch"  << endl;
}

void Laptop::print() const {
    std::cout << "Laptop:" << std::endl;
    Device::printOwnFields();
    printOwnFields();
}

std::shared_ptr<Device> Laptop::clone() const {
    return std::shared_ptr<Device>(new Laptop(*this));
}