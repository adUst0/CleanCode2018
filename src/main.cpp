#include <iostream>
#include <memory>
#include "DateFormatterFactory.h"
#include "Printer.h"
#include "PC.h"
#include "Laptop.h"
#include "Shop.h"

using namespace std;

void test_USDateFormatter() {
    std::shared_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::US);

    Date d(10, 6, 1996);
    // cout << df.toString(d) << endl;

    if (df->toString(d) == string("06.10.1996")) {
        cout << "USDateFormatter::toString() - OK" << endl;
    }
    else {
        cout << "USDateFormatter::toString() - Fail" << endl;
    }

    d = df->fromString("06.10.1996");
    // printf("%02d.%02d.%04d\n", d.getMonth(), d.getDay(), d.getYear());
    if (d.getDay() == 10 && d.getMonth() == 6 && d.getYear() == 1996) {
        cout << "USDateFormatter::fromString() - OK" << endl;
    }
    else {
        cout << "USDateFormatter::fromString() - Fail" << endl;
    }
}

void test_BGDateFormatter() {
    std::shared_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::BG);

    Date d(10, 6, 1996);
    // cout << df.toString(d) << endl;

    if (df->toString(d) == string("10.06.1996")) {
        cout << "BGDateFormatter::toString() - OK" << endl;
    }
    else {
        cout << "BGDateFormatter::toString() - Fail" << endl;
    }

    d = df->fromString("10.06.1996");
    // printf("%02d.%02d.%04d\n", d.getDay(), d.getMonth(), d.getYear());
    if (d.getDay() == 10 && d.getMonth() == 6 && d.getYear() == 1996) {
        cout << "BGDateFormatter::fromString() - OK" << endl;
    }
    else {
        cout << "BGDateFormatter::fromString() - Fail" << endl;
    }
}

void test_ISODateFormatter() {
    std::shared_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::ISO);

    Date d(10, 6, 1996);
    // cout << df->toString(d) << endl;

    if (df->toString(d) == string("1996-06-10")) {
        cout << "ISODateFormatter::toString() - OK" << endl;
    }
    else {
        cout << "ISODateFormatter::toString() - Fail" << endl;
    }

    d = df->fromString("1996-06-10");
    // printf("%02d.%02d.%04d\n", d.getDay(), d.getMonth(), d.getYear());
    if (d.getDay() == 10 && d.getMonth() == 6 && d.getYear() == 1996) {
        cout << "ISODateFormatter::fromString() - OK" << endl;
    }
    else {
        cout << "ISODateFormatter::fromString() - Fail" << endl;
    }
}

void test_Printer() {
    shared_ptr<Device> printer1(new Printer("HP", 950, Date(27, 8, 2016), Country::BG, true));
    printer1->print();

    shared_ptr<Device> printer2(new Printer("Lenovo", 1000, Date(27, 8, 2016), Country::US, false));
    printer2->print();

    shared_ptr<Device> printer3(new Printer("Samsung", 1050, Date(27, 8, 2016), Country::ES, true));
    printer3->print();
}

void test_PC() {
    shared_ptr<Device> pc1(new PC("Samsung", 1250, Date(6, 12, 2015), Country::BG, "Windows 7", 8, 500));
    pc1->print();

    shared_ptr<Device> pc2(new PC("Lenovo", 1100, Date(6, 12, 2015), Country::US, "Debian", 8, 1000));
    pc2->print();
}

void test_Laptop() {
    shared_ptr<Device> laptop1(new Laptop("Samsung", 1600, Date(6, 12, 2017), Country::BG, 8, 14));
    laptop1->print();

    shared_ptr<Device> laptop2(new Laptop("Lenovo", 1800, Date(6, 12, 2017), Country::UNKNOWN, 8, 14.5));
    laptop2->print();
}

void test_Shop() {
    Shop fmi;
    cout << fmi.getSize() << endl;

    fmi.addDevice(shared_ptr<Device>(new Printer("HP", 950, Date(27, 8, 2016), Country::BG, true)));
    fmi.addDevice(shared_ptr<Device>(new Printer("Lenovo", 1000, Date(27, 8, 2016), Country::US, false)));
    fmi.addDevice(shared_ptr<Device>(new Printer("Samsung", 1050, Date(27, 8, 2016), Country::ES, true)));
    fmi.addDevice(shared_ptr<Device>(new PC("Samsung", 1250, Date(6, 12, 2015), Country::BG, "Windows 7", 8, 500)));
    fmi.addDevice(shared_ptr<Device>(new PC("Lenovo", 1100, Date(6, 12, 2015), Country::US, "Debian", 8, 1000)));
    fmi.addDevice(shared_ptr<Device>(new Laptop("Samsung", 1600, Date(6, 12, 2017), Country::BG, 8, 14)));
    fmi.addDevice(shared_ptr<Device>(new Laptop("Lenovo", 1800, Date(6, 12, 2017), Country::UNKNOWN, 8, 14.5)));

    cout << fmi.getSize() << endl;
    fmi.print();
}

int main() {
    test_USDateFormatter();
    test_BGDateFormatter();
    test_ISODateFormatter();
    
    test_Printer();
    test_PC();
    test_Laptop();

    test_Shop();

    return 0;
}