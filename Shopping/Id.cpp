#include "Id.h"

class Category;
class Item;

template <class T>
Id<T>::Id() {
    id =  nextId;
    nextId += 1;
}

template <class T>
Id<T>::~Id() {}

template <class T>
int Id<T>::getId() const {
    return this->id;
}

template <class T> 
int Id<T>::nextId = 1;

template class Id<Category>;
template class Id<Item>;
