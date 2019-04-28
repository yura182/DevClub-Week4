#include "Mohican.h"

Mohican::Mohican(std::string& name) {
    this->name = name;
    this->prev = last;
    this->next = NULL;
    if ( last ) {
        last->next = this;
    }
    last = this;
    total += 1;
}

Mohican::Mohican(const Mohican& copy) {
    this->name = copy.name;
    this->prev = last;
    this->next = NULL;
    if ( last ) {
        last->next = this;
    }
    last = this;
    total += 1;
}

Mohican::~Mohican() {
    if ( this->next ) {
        this->next->prev = this->prev;
    } else {
        last = this->prev;
    }
    
    if ( this->prev ) {
        this->prev->next = this->next;
    }
    
    total -= 1;
}

Mohican& Mohican::operator=(const Mohican& copy) {
    this->name = copy.name;
    return *this;
}

const std::string& Mohican::getName() const {
    return this->name;
}

Mohican& Mohican::getLast() {
    return *last;
}

int Mohican::getTotal() {
    return total;
}

Mohican* Mohican::last = NULL;
int Mohican::total = 0;
