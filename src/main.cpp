#include <iostream>
#include <memory>
#include "DateFormatterFactory.h"
#include "Printer.h"

using namespace std;

void test_USDateFormatter() {
    std::unique_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::US);

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
    std::unique_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::BG);

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
    std::unique_ptr<DateFormatter> df = DateFormatterFactory::getDateFormatter(Country::ISO);

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
    unique_ptr<Device> printer1(new Printer("HP", 950, Date(27, 8, 2016), Country::BG, true));
    printer1->print();

    unique_ptr<Device> printer2(new Printer("Lenovo", 1000, Date(27, 8, 2016), Country::US, false));
    printer2->print();

    unique_ptr<Device> printer3(new Printer("Samsung", 1050, Date(27, 8, 2016), Country::ES, true));
    printer3->print();
}

int main() {
    test_USDateFormatter();
    test_BGDateFormatter();
    test_ISODateFormatter();
    
    test_Printer();

    return 0;
}