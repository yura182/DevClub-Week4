#include <iostream>
#include "Mohican.h"

int main() {
    Mohican *hakan = new Mohican("Hakan");
    Mohican *wapi = new Mohican("Wapi");
    Mohican *kwahu = new Mohican("Kwahu");
    Mohican *nuna = new Mohican("Nuna");
    Mohican *hakan1 = new Mohican(*hakan);
    
    std::cout << Mohican::getLast().getName() << std::endl;
    std::cout << Mohican::getTotal() << "\n";
    std::cout << std::endl;
    
    delete(hakan1);
    
    std::cout << Mohican::getLast().getName() << std::endl;
    std::cout << Mohican::getTotal() << "\n";
    std::cout << std::endl;
    
    delete(nuna);
    
    std::cout << Mohican::getLast().getName() << std::endl;
    std::cout << Mohican::getTotal() << "\n";
    std::cout << std::endl;
    
    delete(kwahu);
    std::cout << Mohican::getLast().getName() << std::endl;
    std::cout << Mohican::getTotal() << "\n";
    std::cout << std::endl;
    
    delete(wapi);
    std::cout << Mohican::getLast().getName() << std::endl;
    std::cout << Mohican::getTotal() << "\n";
    std::cout << std::endl;
    
    delete(hakan);
    std::cout << Mohican::getTotal() << std::endl;
    
    return 0;
}
