#include <iostream>
#include "Date.h"
#include "USDateFormatter.h"

using namespace std;

void test_USDateFormatter() {
    USDateFormatter df;

    Date d(10, 6, 1996);
    // cout << df.toString(d) << endl;

    if (df.toString(d) == string("06.10.1996")) {
        cout << "OK" << endl;
    }
    else {
        cout << "Fail" << endl;
    }

    d = df.fromString("06.10.1996");
    // printf("%02d.%02d.%04d\n", d.getMonth(), d.getDay(), d.getYear());
    if (d.getDay() == 10 && d.getMonth() == 6 && d.getYear() == 1996) {
        cout << "OK" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
}

int main() {
    test_USDateFormatter();

    return 0;
}