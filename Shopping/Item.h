#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <set>
#include <iostream>
#include "Id.h"
#include "Category.h"

class Category;

class Item : public Id<Item> {
    private:
        std::string itemName;
        Category* category;
        // std::set<Order*> orders;
        
        static std::set<Item*> allItems;
    public:
        Item(const std::string& itemName, Category* category);
        ~Item();
        
        const std::string& getTitle() const;
        Category* getCategory() const;
        void setCategory(Category* category);
        
        static std::set<Item*>& getAllItems();
};

std::ostream& operator<<(std::ostream& out, const std::set<Item*>& lst);

#endif // ITEM_H
