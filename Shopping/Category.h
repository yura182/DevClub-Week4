#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <map>
#include "Id.h"

class Category : public Id<Category> {
    private:
        std::string title;
        //std::map<int, Item*> items;
        
        static std::map<int, Category*> all;
    public:
        Category(const std::string& title);
        ~Category();
        
        const std::string& getTitle() const;
        
        static std::map<int, Category*>& getAll();
};

#endif // CATEGORY_H
