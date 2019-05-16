#ifndef PASSPORT_H
#define PASSPORT_H

#include <string>
#include <iostream>
#include "Date.h"

class InvalidSeries {};
class InvalidNumber {};
class SerialOutOfRange {};

class Passport {
    private:
        std::string series;
        std::string number;
        std::string name;
        std::string surname;
        Date dateOfBirth;
        
        static char firstLetter;
        static char secondLetter;
        static int nextNumber;
        
        const std::string newSeries();
        const std::string& newSeries(const std::string& series, int number);
        
        const std::string newNumber();
    public:
        Passport(const std::string& name, const std::string& surname, const Date& date);
        Passport(const std::string& name, const std::string& surname, const Date& date,
                 const std::string& series, int number=0);
        ~Passport();
        
        const std::string& getSeries() const;
        const std::string& getNumber() const;
        const std::string& getName() const;
        const std::string& getSurname() const;
        const Date& getDate() const;
        
        static void setSeries(const std::string& series, int number=1);
};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif // PASSPORT_H
