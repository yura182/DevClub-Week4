#include "Category.h"

Category::Category(const std::string& title) : title(title) {
    categories.insert(this);
}

Category::~Category() {
    std::set<Item*>::iterator it = items.begin();
    
    for ( ; it != items.end(); it++ ) {
        (*it)->setCategory(&defaultCategory);
    }
    
    categories.erase(this);
}

const std::string Category::getTitle() const {
    return this->title;
}

std::set<Item*>& Category::getItems() {
    return items;
}

std::set<Category*>& Category::getCategories() {
    return categories;
}

void Category::addItem(Item* item) {
    items.insert(item);
}

void Category::removeItem(Item* item) {
    items.erase(item);
}

std::set<Category*> Category::categories;


Category Category::defaultCategory("Default");


std::ostream& operator<<(std::ostream& out, const std::set<Category*>& lst) {
    std::set<Category*>::iterator it = lst.begin();
    
    for ( ; it != lst.end(); it++ ) {
        out << "Category id: " << (*it)->getId();
        out << " | Category title: " << (*it)->getTitle() << std::endl;
    }
    
    return out;
}
