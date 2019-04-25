#include <iostream>
#include "ArrayIterator.h"

int main() {
    int array[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    ArrayIterator<int> it(array, 10);
    
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
    
    it.move(5);
    std::cout << *it << std::endl;
    
    it.reset();
    std::cout << *it << std::endl;
    
    std::cout << it[8] << std::endl;
    
    return 0;
}
