#include <iostream>
#include "Passport.h"

int main() {
    Date *date = new Date(11, 4, 1985);
    Date *date1 = new Date(10, 12, 1990);
    Passport *passport = new Passport("Yura", "Petrashenko", *date);
    Passport *passport1 = new Passport("Katya", "Doroshenko", *date1);
    
    std::cout << *passport << std::endl;
    std::cout << "\n" << *passport1 << std::endl;
    
    Passport::setSeries("BC", 999999);
    
    Passport *passport2 = new Passport("Sasha", "Shytiy", *date1);
    std::cout << "\n" << *passport2 << std::endl;
    
    Passport *passport3 = new Passport("Tina", "Van", *date);
    std::cout << "\n" << *passport3 << std::endl;
    
    Passport *passport4 = new Passport("Dan", "Tramp", *date, "CZ", 999999);
    std::cout << "\n" << *passport4 << std::endl;
    
    Passport *passport5 = new Passport("Zhan", "Tirnak", *date1);
    std::cout << "\n" << *passport5 << std::endl;
    
    return 0;
}
