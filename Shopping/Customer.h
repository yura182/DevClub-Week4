#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <set>
#include "Id.h"
#include "Order.h"

class Order;

class EmptyOrders {};
class EmptyCustomerList {};

class Customer : public Id<Customer> {
    private:
        std::string name;
        std::set<Order*> orders;
        
        static std::set<Customer*> allCustomers;
    public:
        Customer(const std::string& name);
        ~Customer();
        
        const std::string& getName() const;
        const std::set<Order*>& getOrders() const;
        
        void addOrder(Order* order);
        void removeOrder(Order* order);
        
        static const std::set<Customer*>& getAllCustomers();
};

std::ostream& operator<<(std::ostream& out, const std::set<Customer*>& lst);
std::ostream& operator<<(std::ostream& out, Customer* customer);

#endif // CUSTOMER_H
