#include "AriProgIterator.h"

template <class T>
AriProgIterator<T>::AriProgIterator(T first, T step, int size) {
    this->first = first;
    this->step = step;
    this->size = size;
    this->currentValue = first;
    this->currentIndex = 1;
}

template <class T>
AriProgIterator<T>::~AriProgIterator() {}

template <class T>
T AriProgIterator<T>::value() const {
    return this->currentValue;
}

template <class T>
bool AriProgIterator<T>::end() const {
    return this->currentIndex > this->size;
}

template <class T>
bool AriProgIterator<T>::start() const {
    return this->currentIndex < 1;
}

template <class T>
void AriProgIterator<T>::next() {
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

template <class T>
void AriProgIterator<T>::prev() {
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

template <class T>
void AriProgIterator<T>::move(int index) {
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

template <class T>
void AriProgIterator<T>::reset() {
    this->currentIndex = 1;
    this->currentValue = this->first;
}

template <class T>
void AriProgIterator<T>::operator++() {
    this->next();
}

template <class T>
void AriProgIterator<T>::operator++(int) {
    this->next();
}

template <class T>
void AriProgIterator<T>::operator--() {
    this->prev();
}

template <class T>
void AriProgIterator<T>::operator--(int) {
    this->prev();
}
template <class T>
T AriProgIterator<T>::operator*() const {
    return this->value();
}

template <class T>
T AriProgIterator<T>::operator[](int index) const {
    if ( index > this->size ) {
        index =  this->size;
    }
    
    if ( index <= 1 ) {
        index = this->first;
    }
    
    return this->step * (index - 1) + this->first;;
}

template class AriProgIterator<int>;
template class AriProgIterator<float>;
template class AriProgIterator<double>;
