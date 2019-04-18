#include <iostream>
#include "GeomProgIterator.h"

int main() {
    GeomProgIterator<int> it(1, 2, 15);
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it.prev() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    std::cout << it.value() << std::endl;
    std::cout << it[20] << std::endl;
    it++;
    std::cout << it.value() << std::endl;
    it.move(8);
    std::cout << it.value() << std::endl;
    it.reset();
    std::cout << it.value() << std::endl;
    
    
    return 0;
}
