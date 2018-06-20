#include <string>
#include "Country.h"

std::string CountryToString(Country country) {
    switch (country) {
        case BG:
            return std::string("BG");
        case US:
            return std::string("US");
        case ES:
            return std::string("ES");
        default:
            return std::string("Unknown");
    }
}