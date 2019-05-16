#include "FactorialIterator.h"

FactorialIterator::FactorialIterator(int size) {
    this->size = size;
    this->currentValue = 1;
    this->currentIndex = 1;
}

FactorialIterator::~FactorialIterator() {}

int FactorialIterator::factorial(int number) {
    if ( number <= 1 ) {
        if ( number < 0 ) {
            return -1;
        }
        return 1;
    }
    return number * factorial(number-1);
}

int FactorialIterator::value() const {
    return this->currentValue;
}

bool FactorialIterator::start() const {
    return this->currentIndex < 1;
}

bool FactorialIterator::end() const {
    return this->currentIndex > this->size;
}

void FactorialIterator::next() {
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
        this->currentValue *= (this->currentIndex - 1);
    }
}

void FactorialIterator::prev() {
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
        this->currentValue /= this->currentIndex;
    }
}

void FactorialIterator::move(int index) {
    if ( index < 1 ) {
        index = 1;
        this->currentValue = 1;
        return;
    } else if ( index > this->size ) {
        index = this->size;
    }
    
    this->currentIndex = index;
    this->currentValue = factorial(index - 1);
}

void FactorialIterator::reset() {
    this->currentIndex = 1;
    this->currentValue = 1;
}

void FactorialIterator::operator++() {
    this->next();
}

void FactorialIterator::operator++(int) {
    this->next();
}

void FactorialIterator::operator--() {
    this->prev();
}

void FactorialIterator::operator--(int) {
    this->prev();
}

int FactorialIterator::operator*() {
    return this->value();
}

int FactorialIterator::operator[](int index) {
    if ( index > this->size ) {
        index = this->size;
    }
    
    if ( index < 1 ) {
        index = 1;
    }
    
    return factorial(index-1);
}
