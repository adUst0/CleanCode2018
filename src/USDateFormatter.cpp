#include <string>
#include <sstream>
#include "Date.h"
#include "USDateFormatter.h"

Date USDateFormatter::fromString(std::string dateStr) {
    std::stringstream stringStream(dateStr);
    std::string subStr;

    getline(stringStream, subStr, '.');
    int month = std::stoi(subStr);

    getline(stringStream, subStr, '.');
    int day = std::stoi(subStr);

    getline(stringStream, subStr);
    int year = std::stoi(subStr);

    return Date(day, month, year);
}

std::string USDateFormatter::toString(const Date& date) {
    char str[32];

    sprintf(str, "%02d.%02d.%04d", date.getMonth(), date.getDay(), date.getYear());

    return std::string(str);
}

bool USDateFormatter::isValidDate(std::string dateStr) {
    Date date = fromString(dateStr);
    return date.isValidDate();
}