#include <iostream>
#include <memory>
#include "Date.h"
#include "DateFormatter.h"
#include "USDateFormatter.h"
#include "BGDateFormatter.h"
#include "ISODateFormatter.h"

using namespace std;

void test_USDateFormatter() {
    std::unique_ptr<DateFormatter> df(new USDateFormatter());

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
    std::unique_ptr<DateFormatter> df(new BGDateFormatter());

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
    std::unique_ptr<DateFormatter> df(new ISODateFormatter());

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

int main() {
    test_USDateFormatter();
    test_BGDateFormatter();
    test_ISODateFormatter();

    return 0;
}