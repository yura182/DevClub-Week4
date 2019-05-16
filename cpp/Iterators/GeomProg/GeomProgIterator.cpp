#include <cmath>
#include "GeomProgIterator.h"

template <class T>
GeomProgIterator<T>::GeomProgIterator(T first, T ratio, int size) {
    this->first = first;
    if ( ratio == 0 ) {
        throw ZeroRatio();
    }
    this->ratio = ratio;
    this->size = size;
    this->currentValue = first;
    this->currentIndex = 1;
}

template <class T>
GeomProgIterator<T>::~GeomProgIterator() {}

template <class T>
T GeomProgIterator<T>::value() const {
    return this->currentValue;
}

template <class T>
bool GeomProgIterator<T>::start() const {
    return this->currentIndex < 1;
}

template <class T>
bool GeomProgIterator<T>::end() const {
    return this->currentIndex > this->size;
}

template <class T>
void GeomProgIterator<T>::next() {
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
        this->currentValue *= this->ratio;
    }
}

template <class T>
void GeomProgIterator<T>::prev() {
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
        this->currentValue /= this->ratio;
    }
}

template <class T>
void GeomProgIterator<T>::move(int index) {
    if ( index > this->size ) {
        this->currentIndex = size;
        this->currentValue = this->first * pow(this->ratio, this->currentIndex - 1);
        return;
    }
    
    if ( index < 1 ) {
        this->currentIndex = 1;
        this->currentValue = this->first;
        return;
    }
    
    this->currentIndex = index;
    this->currentValue = this->first * pow(this->ratio, this->currentIndex - 1);
}

template <class T>
void GeomProgIterator<T>::reset() {
    this->currentIndex = 1;
    this->currentValue = this->first;
}

template <class T>
void GeomProgIterator<T>::operator++() {
    this->next();
}

template <class T>
void GeomProgIterator<T>::operator++(int) {
    this->next();
}

template <class T>
void GeomProgIterator<T>::operator--() {
    this->prev();
}

template <class T>
void GeomProgIterator<T>::operator--(int) {
    this->prev();
}

template <class T>
T GeomProgIterator<T>::operator*() const {
    return this->value();
}

template <class T>
T GeomProgIterator<T>::operator[](int index) const {
    if ( index > this->size ) {
        index = size;
    }
    
    if ( index < 1 ) {
        index = 1;
    }
    
    return this->first * pow(this->ratio, index - 1);
}

template class GeomProgIterator<int>;
template class GeomProgIterator<float>;
template class GeomProgIterator<double>;
