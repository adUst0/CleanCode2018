#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;

    if (!isValidDate()) {
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }
}

bool Date::operator==(const Date& other) const {
    return this->day == other.day && 
        this->month == other.month && 
        this->year == other.year;
}

bool Date::isLeapYear() {
    if (year % 4 != 0) {
        return false;
    }
    else {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        else {
            return true;
        }
    }
}

bool Date::isValidDate() {
    int maxDays = 28;

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            maxDays = 31; 
            break;
        case 4: case 6: case 9: case 11: 
            maxDays = 30; 
            break;
        case 2: 
            if (isLeapYear()) {
                maxDays = 29; 
            }
            break;
        default: 
            return false; 
            break;
    }

    return (day > 0 && day <= maxDays);
}

int Date::getDay() const {
    return day;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}