#include "Category.h"

Category::Category(const std::string& title) : title(title) {
    categories.insert(this);
}

Category::~Category() {
    std::set<Item*>::iterator it = items.begin();
    
    for ( ; it != items.end(); it++ ) {
        delete *it;
    }
    
    categories.erase(this);
    std::cout << "*** Category " << this->getTitle() << " deleted ***\n" << std::endl;
}

const std::string Category::getTitle() const {
    return this->title;
}

const std::set<Item*>& Category::getItems() const{
    if ( this->items.empty() ) {
        throw EmptyItemList();
    }
    return items;
}

const std::set<Category*>& Category::getCategories() {
    if ( categories.empty() ) {
        throw EmptyCategoryList();
    }
    return categories;
}

void Category::addItem(Item* item) {
    items.insert(item);
}

void Category::removeItem(Item* item) {
    items.erase(item);
}

std::set<Category*> Category::categories;

std::ostream& operator<<(std::ostream& out, const std::set<Category*>& lst) {
    std::set<Category*>::iterator it = lst.begin();
    
    for ( ; it != lst.end(); it++ ) {
        out << "Category id: " << (*it)->getId();
        out << " | Category title: " << (*it)->getTitle() << std::endl;
    }
    
    return out;
}
