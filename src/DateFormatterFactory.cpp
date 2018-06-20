#include "DateFormatterFactory.h"

std::unique_ptr<DateFormatter> DateFormatterFactory::getDateFormatter(Country country)
{
    std::unique_ptr<DateFormatter> dateFormatter;

    switch (country) {
        case BG:
            dateFormatter = std::unique_ptr<DateFormatter>(new BGDateFormatter);
            break;
        case US:
            dateFormatter = std::unique_ptr<DateFormatter>(new USDateFormatter);
            break;
        default:
            dateFormatter = std::unique_ptr<DateFormatter>(new ISODateFormatter);
            break;
    }

    return dateFormatter;
};