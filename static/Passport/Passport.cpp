#include "Passport.h"

Passport::Passport(const std::string name, const std::string surname, const Date& date) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = date;
    this->series = newSeries();
    this->number = newNumber();
}

Passport::Passport(const std::string name, const std::string surname, const Date& date,
                   const std::string series, int number) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = date;
    this->series = newSeries(series);
    this->number = newNumber(number);
}

Passport::~Passport() {}


