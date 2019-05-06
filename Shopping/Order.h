#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <set>
#include "Id.h"
#include "Item.h"
#include "Customer.h"

class Item;
class Customer;

class Order : public Id<Order> {
    private:
        Customer* customer;
        std::set<Item*> itemsList;
        
        static std::set<Order*> allOrders;
    public:
        Order(Item* item, Customer* customer);
        ~Order();
        
        Customer* getCustomer() const;
        const std::set<Item*>& getItemsList() const;
        
        void addItem(Item* item);
        void removeItem(Item* item);
        
        static const std::set<Order*>& getAllOrders();
};

std::ostream& operator<<(std::ostream& out, const std::set<Order*>& lst);

#endif // ORDER_H
