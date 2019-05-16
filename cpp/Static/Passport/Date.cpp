#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) {
    this->validate(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {}

void Date::validate(int day, int month, int year) {
    bool leap = false;
    
    if ( year < 0 ) {
        throw InvalidDate("Invalid year");
    }
    
    if ( year % 4 == 0 ) {
        leap = true;
    } else if ( year % 100 == 0 ) {
        leap = false;
    } else if ( year % 400 == 0 ) {
        leap = true;
    }
    
    if ( month < 1 || month > 12 ) {
        throw InvalidDate("Invalid month");
    }
    
    if ( day < 1 || day > 31 ) {
        throw InvalidDate("Invalid day");
    }
    
    if ( month == 2 ) {
        if ( leap ) {
            if ( day > 29 ) {
                throw InvalidDate("Invalid day for leap year");
            }
        } else if ( day > 28 ) {
            throw InvalidDate("Invalid day for Fabruary");
        }
    }
    
    if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 ) {
            throw InvalidDate("Invalid day");
        }
    }
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}
