#include "AriProgIterator.h"

AriProgIterator::AriProgIterator(int first, int step, int size) {
    this->first = first;
    this->step = step;
    this->size = size;
    this->currentValue = first;
    this->currentIndex = 1;
}

AriProgIterator::~AriProgIterator() {}

int AriProgIterator::value() const {
    return this->currentValue;
}

bool AriProgIterator::end() const {
    return this->currentIndex > this->size;
}

bool AriProgIterator::start() const {
    return this->currentIndex < 1;
}

void AriProgIterator::next() {
    if ( this->end() ) {
        return;
    }
    
    if ( this->start() ) {
        this->currentIndex += 1;
    }
    
    this->currentIndex += 1;
    
    if ( this->end() ) {
        return;
    } else {
        this->currentValue += this->step;
    }
}

void AriProgIterator::prev() {
    if ( this->start() ) {
        return;
    }
    
    if ( this->end() ) {
        this->currentIndex -= 1;
    }
    
    this->currentIndex -= 1;
    
    if ( this->start() ) {
        return;
    } else {
        this->currentValue -= this->step;
    }
}

void AriProgIterator::move(int index) {
    if ( index > this->size ) {
        this->currentIndex = size;
        this->currentValue = this->first + (this->currentIndex - 1) * this->step;
        return;
    }
    
    if ( index <= 1 ) {
        this->currentIndex = 1;
        this->currentValue = this->first;
        return;
    }
    
    this->currentIndex = index;
    this->currentValue = this->first + (this->currentIndex - 1) * this->step;
}

void AriProgIterator::reset() {
    this->currentIndex = 1;
    this->currentValue = this->first;
}

void AriProgIterator::operator++() {
    this->next();
}

void AriProgIterator::operator++(int) {
    this->next();
}

void AriProgIterator::operator--() {
    this->prev();
}

void AriProgIterator::operator--(int) {
    this->prev();
}

int AriProgIterator::operator*() const {
    return this->value();
}

int AriProgIterator::operator[](int index) const {
    if ( index > this->size ) {
        index =  this->size;
    }
    
    if ( index <= 1 ) {
        index = this->first;
    }
    
    return this->step * (index - 1) + this->first;;
}
