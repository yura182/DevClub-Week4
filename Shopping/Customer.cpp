#include "Customer.h"

Customer::Customer(const std::string& name) : name(name) {
    allCustomers.insert(this);
}

Customer::~Customer() {
    std::set<Order*>::iterator it = orders.begin();
    
    for ( ; it != orders.end(); it++ ) {
        delete *it;
    }
    
    allCustomers.erase(this);
    std::cout << "*** Customer " << this->getName() << " deleted ***\n" << std::endl;
}

const std::string& Customer::getName() const {
    return this->name;
}

const std::set<Order*>& Customer::getOrders() const {
    if ( this->orders.empty() ) {
        throw EmptyOrders();
    }
    return this->orders;
}

void Customer::addOrder(Order* order) {
    this->orders.insert(order);
}

void Customer::removeOrder(Order* order) {
    this->orders.erase(order);
}

const std::set<Customer*>& Customer::getAllCustomers() {
    if ( allCustomers.empty() ) {
        throw EmptyCustomerList();
    }
    return allCustomers;
}

std::set<Customer*> Customer::allCustomers;

std::ostream& operator<<(std::ostream& out, const std::set<Customer*>& lst) {
    std::set<Customer*>::iterator it = lst.begin();
    
    for ( ; it != lst.end(); it++ ) {
        out << (*it)->getOrders();
    }
    
    return out;
}

std::ostream& operator<<(std::ostream& out, Customer* customer) {
    out << customer->getOrders();
    return out;
}
