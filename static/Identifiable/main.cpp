#include <iostream>
#include "Identifiable.h"

int main() {
    Identifiable *a = new Identifiable();
    Identifiable *b = new Identifiable();
    Identifiable *c = new Identifiable();
    Identifiable *d = new Identifiable(*c);
    
    std::cout << c->getId() << std::endl;
    std::cout << d->getId() << std::endl;
    std::cout << Identifiable::getTotal() << std::endl;
    
    delete(c);
    
    Identifiable *e = new Identifiable();
    
    std::cout << e->getId() << std::endl;
    std::cout << Identifiable::getTotal() << std::endl;
    
    *e = *d;
    
    std::cout << e->getId() << std::endl;
    std::cout << Identifiable::getTotal() << std::endl;
    
    delete(a);
    delete(b);
    delete(d);
    
    return 0;
}
