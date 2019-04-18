#include <iostream>
#include "GeomProgIterator.h"

int main() {
    GeomProgIterator<int> it(1, 2, 10);
    
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
    
    return 0;
}
