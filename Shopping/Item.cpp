#include "Item.h"

Item::Item(const std::string& itemName, Category* category) : itemName(itemName), category(category) {
    allItems.insert(this);
    category->addItem(this);
}

Item::~Item() {
    allItems.erase(this);
    std::cout << "*** Item " << this->getTitle() << " deleted ***" << std::endl;
}

const std::string& Item::getTitle() const {
    return this->itemName;
}

Category* Item::getCategory() const {
    return this->category;
}


const std::set<Order*>& Item::getOrders() const {
    if ( orders.empty() ) {
        throw EmptyOrderList();
    }
    return this->orders;
}

void Item::setCategory(Category* category) {
    if ( this->category == category ) {
        return;
    }
    
    this->category->removeItem(this);
    this->category = category;
    this->category->addItem(this);
}

void Item::addOrder(Order* order) {
    this->orders.insert(order);
}

void Item::removeOrder(Order* order) {
    this->orders.erase(order);
}

std::set<Item*> Item::allItems;

const std::set<Item*>& Item::getAllItems() {
    if ( allItems.empty() ) {
        throw EmptyItemList();
    }
    return allItems;
}

std::ostream& operator<<(std::ostream& out, const std::set<Item*>& lst) {
    std::set<Item*>::iterator it = lst.begin();
    
    for ( ; it != lst.end(); it++ ) {
        out << "Item id: " << (*it)->getId();
        out << " | Item: " << (*it)->getTitle();
        out << " | Category id: " << (*it)->getCategory()->getId() << std::endl;
    }
    
    return out;
}
