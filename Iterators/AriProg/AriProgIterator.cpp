#include "AriProgIterator.h"

AriProgIterator::AriProgIterator(int first, int step, int limit) {
    this->first = first;
    this->step = step;
    this->limit = limit;
    this->currentValue = first;
    this->currentIndex = 0;
}

AriProgIterator::~AriProgIterator() {}

int AriProgIterator::value() const {
    return this->currentValue;
}

bool AriProgIterator::end() const {
    return this->currentValue > this->limit;
}

bool AriProgIterator::begin() const {
    return this->currentValue < this->first;
}

void AriProgIterator::next() {
    if ( this->end() ) {
        return;
    }
    this->currentIndex += 1;
    this->currentValue += this->step;
}

void AriProgIterator::prev() {
    if ( this->begin() ) {
        return;
    }
    this->currentIndex -= 1;
    this->currentValue -= this->step;
}

void AriProgIterator::move(int index) {
    int temp = this->currentIndex;
    
    this->currentIndex = index - 1;
    this->currentValue = this->currentIndex * this->step + this->first;
    
    if ( this->begin() || this->end() ) {
        this->currentIndex = temp;
        this->currentValue = this->currentIndex * this->step + this->first;
        return;
    }
}

void AriProgIterator::reset() {
    this->currentIndex = 0;
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
    int result = this->step * index + this->first;
    
    if ( result > this->limit || result < this->first ) {
        return;
    }
    
    return result;
}
