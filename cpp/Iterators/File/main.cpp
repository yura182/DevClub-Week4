#include <iostream>
#include "FileIterator.h"

int main() {
    FileIterator<char> it("file.in");
    
    for ( ; !it.end(); it.next() ) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;
    
    it.reset();
    
    std::cout << *it << std::endl;
    
    it++;
    it++;
    std::cout << *it << std::endl;
    
    return 0;
}
