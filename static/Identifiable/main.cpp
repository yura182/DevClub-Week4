#include <iostream>
#include "Identifiable.h"

int main() {
    Identifiable *a = new Identifiable();
    Identifiable *b = new Identifiable();
    Identifiable *c = new Identifiable();
    
    std::cout << c->getId() << std::endl;
    
    delete(c);
    
    Identifiable *d = new Identifiable();
    
    std::cout << d->getId() << std::endl;
    
    delete(a);
    delete(b);
    delete(d);
    
    return 0;
}
