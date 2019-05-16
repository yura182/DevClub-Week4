#include <iostream>
#include "FactorialIterator.h"

int main() {
    FactorialIterator it(9);
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it.prev() ) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    it++;
    it++;
    it++;
    it--;
    std::cout << it.value() << std::endl;
    
    it.move(5);
    std::cout << it.value() << std::endl;
    
    it.reset();
    std::cout << it.value() << std::endl;
    
    std::cout << it[6] << std::endl;
    
    return 0;
}
