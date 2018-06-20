#pragma once

class Date 
{
private:
    int day;
    int month;
    int year;
public:
    Date(int day = 1, int month = 1, int year = 1);
    bool operator==(const Date&) const;
    bool isLeapYear();
    bool isValidDate();

    int getDay() const;
    int getMonth() const;
    int getYear() const;
};