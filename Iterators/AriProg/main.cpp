#include <iostream>
#include "AriProgIterator.h"

int main() {
    //AriProgIterator it(10, 2, 10);
    AriProgIterator<float> &it = new AriProgIterator<float>(1.5, 1.5, 10);
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    std::cout << it.value() << std::endl;
    it.reset();
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it.prev() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    it.move(5);
    
    std::cout << it.value() << std::endl; 
    
    for ( ; !it.end(); it++ ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    for ( ; !it.start(); it-- ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    it++;
    
    std::cout << *it << std::endl;
    
    std::cout << it[5] << std::endl; 
    
    return 0;
}
