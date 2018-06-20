#pragma once

#include <string>
#include "Date.h"
#include "DateFormatter.h"

class BGDateFormatter : public DateFormatter 
{
public:
    virtual Date fromString(std::string);
    virtual std::string toString(const Date&);
    virtual bool isValidDate(std::string);
};