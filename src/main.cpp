#include <iostream>
#include "Printer.h"
#include "PC.h"
#include "Laptop.h"
#include "Shop.h"

using namespace std;

int main() {
    Shop fmi;

    fmi.addDevice(shared_ptr<Device>(new Printer("HP", 950, Date(27, 8, 2016), Country::BG, true)));
    fmi.addDevice(shared_ptr<Device>(new Printer("Lenovo", 1000, Date(27, 8, 2016), Country::US, false)));
    fmi.addDevice(shared_ptr<Device>(new Printer("Samsung", 1050, Date(27, 8, 2016), Country::ES, true)));
    fmi.addDevice(shared_ptr<Device>(new PC("Samsung", 1250, Date(6, 12, 2015), Country::BG, "Windows 7", 8, 500)));
    fmi.addDevice(shared_ptr<Device>(new PC("Lenovo", 1100, Date(6, 12, 2015), Country::US, "Debian", 8, 1000)));
    fmi.addDevice(shared_ptr<Device>(new Laptop("Samsung", 1600, Date(6, 12, 2017), Country::BG, 8, 14)));
    fmi.addDevice(shared_ptr<Device>(new Laptop("Lenovo", 1800, Date(6, 12, 2017), Country::UNKNOWN, 8, 14.5)));

    cout << "Current inventory: " << endl;
    fmi.print();

    return 0;
}