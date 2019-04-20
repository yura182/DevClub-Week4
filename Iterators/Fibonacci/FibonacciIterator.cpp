#include "FibonacciIterator.h"

FibonacciIterator::FibonacciIterator(int size, int firstIndex) {
    this->size = size;
    this->firstIndex = firstIndex;
    this->currentIndex = firstIndex;
    this->currentValue = fibonacci(this->currentIndex);
    this->prevValue = fibonacci(this->currentIndex-1);
}

FibonacciIterator::~FibonacciIterator() {}

FibonacciIterator::fibonacci(int number) {
    if ( number == 0 ) {
        return 0;
    } else if ( number == 1 || number == -1 ) {
        return 1;
    } else if ( number < 0 ) {
        return fibonacci(number+2) - fibonacci(number+1);
    }
    return fibonacci(number-1) + fibonacci(number-2);
}

int FibonacciIterator::value() const {
    return this->currentValue;
}

bool FibonacciIterator::start() const {
    return this->currentIndex < this->firstIndex;
}

bool FibonacciIterator::end() const {
    return this->currentIndex >= this->firstIndex + this->size;
}

void FibonacciIterator::next() {
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
        int temp = this->currentValue;
        this->currentValue += this->prevValue;
        this->prevValue = temp;
    }
}

void FibonacciIterator::prev() {
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
        int temp = this->currentValue;
        this->currentValue = this->prevValue;
        this->prevValue = temp - this->currentValue;
    }
}

void FibonacciIterator::move(int index) {
    if ( index < this->firstIndex ) {
        index = this->firstIndex;
    } else if ( index > this->firstIndex + this->size ) {
        index = this->firstIndex + this->size;
    }
    
    this->currentIndex = index;
    this->currentValue = fibonacci(this->currentIndex);
    this->prevValue = fibonacci(this->currentIndex-1);
}

void FibonacciIterator::reset() {
    this->currentIndex = this->firstIndex;
    this->currentValue = fibonacci(this->currentIndex);
    this->prevValue = fibonacci(this->currentIndex-1);
}

void FibonacciIterator::operator++() {
    this->next();
}

void FibonacciIterator::operator++(int) {
    this->next();
}

void FibonacciIterator::operator--() {
    this->prev();
}

void FibonacciIterator::operator--(int) {
    this->prev();
}

int FibonacciIterator::operator*() {
    return this->value();
}

int FibonacciIterator::operator[](int index) {
    if ( index < this->firstIndex ) {
        index = this->firstIndex;
    } else if ( index > this->firstIndex + this->size ) {
        index = this->firstIndex + this->size;
    }
    
    return fibonacci(index);
}
