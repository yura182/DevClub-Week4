#include <iostream>
#include "Id.h"
#include "Category.h"
#include "Item.h"

// #define SEPARATOR std::cout << "--------------------" << std::endl;

int main() {
    Category *mobile = new Category("Mobile");
    Category *tv = new Category("Tv");
    
    std::cout << Category::getCategories() << std::endl;
    
    Item *iphone = new Item("Iphone", mobile);
    Item *nokia = new Item("Nokia", mobile);
    Item *lg = new Item("Lg", tv);
    Item *samsung = new Item("Samsung", tv);
        
    std::cout << Item::getAllItems() << std::endl;
    
    iphone->setCategory(tv);
    nokia->setCategory(tv);
    
    std::cout << Item::getAllItems() << std::endl;
    std::cout << tv->getItems() << std::endl;

    return 0;
}
