#include <iostream>
#include "FibonacciIterator.h"

int main() {
    FibonacciIterator it(10, 0);
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it-- ) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    it.move(5);
    std::cout << *it << std::endl;
    
    it.reset();
    std::cout << *it << std::endl;
    
    std::cout << it[8] << std::endl;
    
    return 0;
}
