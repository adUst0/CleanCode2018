#include "Printer.h"
#include <iostream>
#include <memory>

Printer::Printer(std::string maker, double price, Date creationDate, Country country, bool colored)
    : Device(maker, price, creationDate, country) 
{
    this->colored = colored;
}

bool Printer::isColored() const {
    return this->colored;
}

// If the printer is colored, rating = (price^2)/2, else rating = price/2
double Printer::getRating() const {
    double rating = 0;

    if (isColored()) {
        rating = getPrice() * getPrice() / 2;
    }
    else {
        rating = getPrice() / 2;
    }

    return rating;
}

void Printer::printOwnFields() const {
    using namespace std;
    cout << "isColored: " << boolalpha << colored << endl;
}

void Printer::print() const {
    Device::printOwnFields();
    printOwnFields();
}

std::unique_ptr<Device> Printer::clone() const {
    return std::unique_ptr<Device>(new Printer(*this));
} 