#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <set>
#include <iostream>
#include "Id.h"
#include "Item.h"

class Item;

class Category : public Id<Category> {
    private:
        std::string title;
        std::set<Item*> items;
        
        static std::set<Category*> categories;
        static Category defaultCategory; 
    public:
        Category(const std::string& title);
        ~Category();
        
        const std::string getTitle() const;
        std::set<Item*>& getItems();
        
        void addItem(Item* item);
        void removeItem(Item* item);
        
        static std::set<Category*>& getCategories();
};

std::ostream& operator<<(std::ostream& out, const std::set<Category*>& lst);

#endif // CATEGORY_H
