#include "DateFormatterFactory.h"

std::shared_ptr<DateFormatter> DateFormatterFactory::getDateFormatter(Country country)
{
    std::shared_ptr<DateFormatter> dateFormatter;

    switch (country) {
        case BG:
            dateFormatter = std::shared_ptr<DateFormatter>(new BGDateFormatter);
            break;
        case US:
            dateFormatter = std::shared_ptr<DateFormatter>(new USDateFormatter);
            break;
        default:
            dateFormatter = std::shared_ptr<DateFormatter>(new ISODateFormatter);
            break;
    }

    return dateFormatter;
};