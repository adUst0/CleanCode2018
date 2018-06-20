#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <memory>
#include "doctest.h"
#include "../src/DateFormatterFactory.h"
#include "../src/Printer.h"
#include "../src/PC.h"
#include "../src/Laptop.h"

using namespace std;

TEST_CASE("Testing the US Date Formatter class") {
    shared_ptr<DateFormatter> df = 
            DateFormatterFactory::getDateFormatter(Country::US);

    SUBCASE("Testing USDateFormatter::toString method") {
        CHECK(df->toString(Date(10, 6, 1996)) == string("06.10.1996"));
        CHECK(df->toString(Date(28, 2, 0)) == string("02.28.0000"));
        CHECK(df->toString(Date(30, 8, -25)) == string("08.30.-025"));
    }

    SUBCASE("Testing USDateFormatter::fromString method") {
        CHECK(df->fromString("06.10.1996") == Date(10, 6, 1996));
        CHECK(df->fromString("02.28.0000") == Date(28, 2, 0));
        CHECK(df->fromString("08.30.-025") == Date(30, 8, -25));
    }
}

TEST_CASE("Testing the BG Date Formatter class") {
    shared_ptr<DateFormatter> df = 
            DateFormatterFactory::getDateFormatter(Country::BG);

    SUBCASE("Testing BGDateFormatter::toString method") {
        CHECK(df->toString(Date(10, 6, 1996)) == string("10.06.1996"));
        CHECK(df->toString(Date(28, 2, 0)) == string("28.02.0000"));
        CHECK(df->toString(Date(30, 8, -25)) == string("30.08.-025"));
    }

    SUBCASE("Testing BGDateFormatter::fromString method") {
        CHECK(df->fromString("10.06.1996") == Date(10, 6, 1996));
        CHECK(df->fromString("28.02.0000") == Date(28, 2, 0));
        CHECK(df->fromString("30.08.-025") == Date(30, 8, -25));
    }
}

TEST_CASE("Testing the ISO Date Formatter class") {
    shared_ptr<DateFormatter> df = 
            DateFormatterFactory::getDateFormatter(Country::ISO);

    SUBCASE("Testing ISODateFormatter::toString method") {
        CHECK(df->toString(Date(10, 6, 1996)) == string("1996-06-10"));
        CHECK(df->toString(Date(28, 2, 0)) == string("0000-02-28"));
        CHECK(df->toString(Date(30, 8, -25)) == string("-025-08-30"));
    }

    SUBCASE("Testing ISODateFormatter::fromString method") {
        CHECK(df->fromString("1996-06-10") == Date(10, 6, 1996));
        CHECK(df->fromString("0000-02-28") == Date(28, 2, 0));
        CHECK(df->fromString("-025-08-30") == Date(30, 8, -25));
    }
}

TEST_CASE("Testing Printer class") {
    Printer printer("HP", 950, Date(27, 8, 2016), Country::BG, true);

    CHECK(printer.getMaker() == "HP");
    CHECK(printer.getPrice() == 950);
    CHECK(printer.getRating() == 451250);
    CHECK(printer.isColored() == true);
}

TEST_CASE("Testing PC class") {
    PC pc("Samsung", 1250, Date(6, 12, 2015), 
        Country::BG, "Windows 7", 8, 500);

    CHECK(pc.getMaker() == "Samsung");
    CHECK(pc.getPrice() == 1250);
    CHECK(pc.getRating() == 879);
    CHECK(pc.getOs() == "Windows 7");
    CHECK(pc.getRam() == 8);
    CHECK(pc.getHdd() == 500);
}

TEST_CASE("Testing Laptop class") {
    Laptop laptop("Samsung", 1600, Date(6, 12, 2017), Country::BG, 8, 14.7);

    CHECK(laptop.getMaker() == "Samsung");
    CHECK(laptop.getPrice() == 1600);
    CHECK(laptop.getRating() == 804);
    CHECK(laptop.getRam() == 8);
    CHECK(laptop.getScreenSize() == 14.7);
}