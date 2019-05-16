#include <iostream>
#include "Countable.h"

int main() {
    Countable *a = new Countable();
    Countable *b = new Countable();
    Countable *c = new Countable();
    Countable *d = new Countable();
    
    delete(a);
    
    std::cout << Countable::getTotal() << std::endl;
    
    delete(b);
    delete(c);
    delete(d);
    
    return 0;
}
