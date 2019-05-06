#include <iostream>
#include "Id.h"
#include "Category.h"
#include "Item.h"
#include "Customer.h"

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
    
    Customer *ivan = new Customer("Ivan");
    Customer *dima = new Customer("Dima");
    
    Order *gift = new Order(iphone, ivan);
    Order *shopList = new Order(nokia, dima);
    gift->addItem(samsung);
    
    std::cout << ivan << std::endl;
    std::cout << dima << std::endl;
    
    // std::cout << Order::getAllOrders() << std::endl;
    // std::cout << Customer::getAllCustomers() << std::endl;
    
    delete gift;
    delete shopList;
    delete ivan;
    delete dima;
    delete samsung;
    delete lg;
    delete nokia;
    delete iphone;
    delete mobile;
    delete tv;
    
    return 0;
}
