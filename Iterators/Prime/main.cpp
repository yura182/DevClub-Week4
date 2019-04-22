#include <iostream>
#include "PrimeIterator.h"

int main() {
    PrimeIterator it(20);
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it-- ) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    it++;
    it++;
    std::cout << *it << std::endl;
    
    it.reset();
    std::cout << *it << std::endl;
    
    return 0;
}
