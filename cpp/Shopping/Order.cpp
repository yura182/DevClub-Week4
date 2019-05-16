#include "Order.h"

Order::Order(Item* item, Customer* customer) : customer(customer) {
    allOrders.insert(this);
    this->addItem(item);
    item->addOrder(this);
    customer->addOrder(this);
}

Order::~Order() {
    std::set<Item*>::iterator it = this->itemsList.begin();
    
    for ( ; it != this->itemsList.end(); it++ ) {
        (*it)->removeOrder(this);
    }
    
    allOrders.erase(this);
    
    std::cout << "*** Order with id " << this->getId() << " deleted ***" << std::endl;
}

Customer* Order::getCustomer() const {
    return this->customer;
}

const std::set<Item*>& Order::getItemsList() const {
    return this->itemsList;
}

void Order::addItem(Item* item) {
    this->itemsList.insert(item);
}

void Order::removeItem(Item* item) {
    this->itemsList.erase(item);
}

const std::set<Order*>& Order::getAllOrders() {
    if ( allOrders.empty() ) {
        throw EmptyOrderList();
    }
    return allOrders;
}

std::set<Order*> Order::allOrders;

std::ostream& operator<<(std::ostream& out, const std::set<Order*>& lst) {
    std::set<Order*>::iterator it = lst.begin();
    
    for ( ; it != lst.end(); it++ ) {
        out << "Order id: " << (*it)->getId();
        out << " | Customer: " << (*it)->getCustomer()->getName();
        out << " | Customer id: " << (*it)->getCustomer()->getId();
        out << "\n" << "---------Items----------" << "\n";
        out << (*it)->getItemsList() << std::endl;
    }
    
    return out;
}
