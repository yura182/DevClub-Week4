#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <set>
#include <iostream>
#include "Id.h"
#include "Item.h"

class Item;

class EmptyItemList {};
class EmptyCategoryList {};

class Category : public Id<Category> {
    private:
        std::string title;
        std::set<Item*> items;
        
        static std::set<Category*> categories;
    public:
        Category(const std::string& title);
        ~Category();
        
        const std::string getTitle() const;
        const std::set<Item*>& getItems() const;
        
        void addItem(Item* item);
        void removeItem(Item* item);
        
        static const std::set<Category*>& getCategories();
};

std::ostream& operator<<(std::ostream& out, const std::set<Category*>& lst);

#endif // CATEGORY_H
