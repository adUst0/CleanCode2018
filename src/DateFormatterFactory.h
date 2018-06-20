#pragma once

#include <memory>
#include "Country.h"
#include "USDateFormatter.h"
#include "BGDateFormatter.h"
#include "ISODateFormatter.h"

class DateFormatterFactory
{
public:
    static std::unique_ptr<DateFormatter> getDateFormatter(Country country);
};