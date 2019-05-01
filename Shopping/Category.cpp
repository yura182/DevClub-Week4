#include "Category.h"

Category::Category(const std::string& title) : title(title) {
    all.insert(std::pair<int, Category*>(this->getId(), this));
}

Category::~Category() {
    all.erase(this->getId());
}

const std::string& Category::getTitle() const {
    return this->title;
}

std::map<int, Category*>& Category::getAll() {
    return all;
}

std::map<int, Category*> Category::all;
