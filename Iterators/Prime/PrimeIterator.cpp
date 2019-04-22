#include <cstdlib>
#include <cmath>
#include "PrimeIterator.h"

PrimeIterator::PrimeIterator(int size) {
    this->size = size;
    this->currentIndex = 0;
    this->primeNumbers = (int*) calloc(this->size, sizeof(int));
    
    if ( this->primeNumbers == NULL ) {
        throw OutOfMemoryException();
    }
    
    this->primeNumbers[0] = 2;
    this->nextNumber = primeNumbers[0] + 1;
}

PrimeIterator::~PrimeIterator() {
    free(primeNumbers);
}

bool PrimeIterator::isPrime(int *numbers, int n) const {
    for ( int i = 0, limit = ceil(sqrt(n)); numbers[i] <= limit; i++ ) {
        if ( !fmod(n, numbers[i]) ) {
            return false;
        }
    }
    return true;
}

int PrimeIterator::value() const {
    if ( this->end() ) {
        return this->primeNumbers[this->size-1];
    } else if ( this->start() ) {
        return this->primeNumbers[0];
    }
    
    return this->primeNumbers[this->currentIndex];
}

bool PrimeIterator::start() const {
    return this->currentIndex < 0;
}

bool PrimeIterator::end() const {
    return this->currentIndex >= this->size;
}

void PrimeIterator::next() {
    if ( this->end() ) {
        return;
    }
    
    if ( this->start() ) {
        this->currentIndex += 1;
    }
    
    this->currentIndex += 1;
    
    if ( this->end() ) {
        return;
    } else if ( this->primeNumbers[this->currentIndex] == 0 ) {
        bool foundPrime = false;
        
        for ( ; !foundPrime; ) {
            if ( isPrime(this->primeNumbers, this->nextNumber) ) {
                this->primeNumbers[this->currentIndex] = this->nextNumber;
                this->nextNumber += 1;
                foundPrime = true;
            } else {
                this->nextNumber += 1;
            }
        }
    }
}

void PrimeIterator::prev() {
    if ( this->start() ) {
        return;
    }
    
    if ( this->end() ) {
        this->currentIndex -= 1;
    }
    
    this->currentIndex -= 1;
}

void PrimeIterator::reset() {
    this->currentIndex = 0;
}

void PrimeIterator::operator++() {
    this->next();
}

void PrimeIterator::operator++(int) {
    this->next();
}

void PrimeIterator::operator--() {
    this->prev();
}

void PrimeIterator::operator--(int) {
    this->prev();
}

int PrimeIterator::operator*() {
    return this->value();
}
