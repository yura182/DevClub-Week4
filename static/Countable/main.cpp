#include <iostream>
#include "Countable.h"

int main() {
    Countable a;
    Countable b;
    Countable c;
    //Countable d;
    
    std::cout << Countable::getTotal() << std::endl;
    
    return 0;
}
