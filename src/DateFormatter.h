#pragma once

#include <string>
#include "Date.h"

class DateFormatter
{
public:
    virtual Date fromString(std::string) = 0;
    virtual std::string toString(const Date&) = 0;
    virtual bool isValidDate(std::string) = 0;
};