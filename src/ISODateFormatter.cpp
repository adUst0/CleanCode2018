#include <string>
#include <sstream>
#include "Date.h"
#include "ISODateFormatter.h"

Date ISODateFormatter::fromString(std::string dateStr) {
    std::stringstream stringStream(dateStr);
    std::string subStr;

    getline(stringStream, subStr, '-');
    int year = std::stoi(subStr);

    getline(stringStream, subStr, '-');
    int month = std::stoi(subStr);

    getline(stringStream, subStr);
    int day = std::stoi(subStr);

    return Date(day, month, year);
}

std::string ISODateFormatter::toString(const Date& date) {
    char str[32];

    sprintf(str, "%04d-%02d-%02d",date.getYear(), date.getMonth(), date.getDay());

    return std::string(str);
}

bool ISODateFormatter::isValidDate(std::string dateStr) {
    Date date = fromString(dateStr);
    return date.isValidDate();
}