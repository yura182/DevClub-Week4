#include <iostream>
#include <iomanip>
#include <sstream>
#include "Passport.h"

Passport::Passport(const std::string& name, const std::string& surname, const Date& date) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = date;
    this->series = newSeries();
    this->number = newNumber();
}

Passport::Passport(const std::string& name, const std::string& surname, const Date& date,
                   const std::string& series, int number) {
    this->name = name;
    this->surname = surname;
    this->dateOfBirth = date;
    this->series = newSeries(series, number);
    this->number = newNumber();
}

Passport::~Passport() {}

const std::string& Passport::getSeries() const {
    return this->series;
}

const std::string& Passport::getNumber() const {
    return this->number;
}

const std::string& Passport::getName() const {
    return this->name;
}

const std::string& Passport::getSurname() const {
    return this->surname;
}

const Date& Passport::getDate() const {
    return this->dateOfBirth;
}

char Passport::firstLetter = 'A';
char Passport::secondLetter = 'A';
int Passport::nextNumber = 1;

const std::string Passport::newSeries() {
    std::string series;
    
    series.push_back(firstLetter);
    series.push_back(secondLetter);
    
    return series;
}

const std::string Passport::newNumber() {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(6) << nextNumber;
    
    nextNumber += 1;
    
    if ( nextNumber > 999999 ) {
        nextNumber = 1;
        secondLetter += 1;
        if ( secondLetter > 'Z' ) {
            secondLetter = 'A';
            firstLetter += 1;
            if ( firstLetter > 'Z' ) {
                throw SerialOutOfRange();
            }
        }
    }
    
    return out.str();
}

const std::string& Passport::newSeries(const std::string& series, int number) {
    if ( series[0] < firstLetter ) {
        throw InvalidSeries();
    } else if ( series[0] == firstLetter ) {
        if ( series[1] < secondLetter ) {
            throw InvalidSeries();
        }
    }
    
    firstLetter = series[0];
    secondLetter = series[1];
    
    if ( number > 999999 ) {
        throw InvalidNumber();
    }
    
    nextNumber = number;
    
    return series;
}

void Passport::setSeries(const std::string& series, int number) {
    if ( series[0] < firstLetter ) {
        throw InvalidSeries();
    } else if ( series[1] < secondLetter ) {
        throw InvalidSeries();
    }
    
    firstLetter = series[0];
    secondLetter = series[1];
    
    if ( number > 999999 ) {
        throw InvalidNumber();
    }
    
    nextNumber = number;
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << "Serial number: " << passport.getSeries() << passport.getNumber() << "\n";
    out << "Name: " << passport.getName() << "\nSurname: " << passport.getSurname() << "\n";
    out << "Date of Birth: " << passport.getDate() << std::endl;
    
    return out;
}
