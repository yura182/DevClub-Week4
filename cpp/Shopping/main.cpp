#include <iostream>
#include "Id.h"
#include "Category.h"
#include "Item.h"
#include "Customer.h"

int main() {
    Category *mobile = new Category("Mobile");
    Category *tv = new Category("TV");
    
    std::cout << Category::getCategories() << std::endl;
    
    Item *iphone = new Item("Iphone", mobile);
    Item *nokia = new Item("Nokia", mobile);
    Item *lg = new Item("Lg", tv);
    Item *samsung = new Item("Samsung", tv);
    
    std::cout << mobile->getItems() << std::endl;
    delete mobile;
    std::cout << Item::getAllItems() << std::endl;
    
    Customer *ivan = new Customer("Ivan");
    Customer *dima = new Customer("Dima");
    
    Order *gift = new Order(lg, ivan);
    Order *shopList = new Order(samsung, dima);
    gift->addItem(samsung);
    
    std::cout << ivan << std::endl;
    std::cout << dima << std::endl;

    delete ivan;
    delete dima;
    delete tv;
    
    return 0;
}
