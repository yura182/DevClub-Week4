#include <cstdlib>
#include "PrimeIterator.h"

PrimeIterator::PrimeIterator(int size) {
    this->size = size;
    this->currentIndex = 0;
    this->initSize = 5;
    this->primeNumbers = (*int) calloc(this->size, sizeof(int));
    
    if ( this->primeNumbers == NULL ) {
        throw OutOfMemoryException();
    }
    
    if ( this->size < this->initSize ) {
        this->initSize = this->size;
    }
}
