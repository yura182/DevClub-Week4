#include "ArrayIterator.h"

template <class T>
ArrayIterator<T>::ArrayIterator(T *array, int size) {
    this->size = size;
    this->array = array;
    this->currentIndex = 0;
}

template <class T>
ArrayIterator<T>::~ArrayIterator() {}

template <class T>
T ArrayIterator<T>::value() const {
    if ( this->end() ) {
        return this->array[this->size - 1];
    } else if ( this->start() ) {
        return this->array[0];
    }
    
    return this->array[this->currentIndex];
}

template <class T>
bool ArrayIterator<T>::start() const {
    return this->currentIndex < 0;
}

template <class T>
bool ArrayIterator<T>::end() const {
    return this->currentIndex >= size;
}

template <class T>
void ArrayIterator<T>::next() {
    if ( this->end() ) {
        return;
    } else if ( this->start() ) {
        this->currentIndex += 1;
    }
    
    this->currentIndex += 1;
}

template <class T>
void ArrayIterator<T>::prev() {
    if ( this->start() ) {
        return;
    } else if ( this->end() ) {
        this->currentIndex -= 1;
    }
    
    this->currentIndex -= 1;
}

template <class T>
void ArrayIterator<T>::move(int index) {
    if ( index < 0 ) {
        index = 0;
    } else if ( index >= this->size ) {
        index = this->size - 1;
    }
    
    this->currentIndex = index;
}

template <class T>
void ArrayIterator<T>::reset() {
    this->currentIndex = 0;
}

template <class T>
void ArrayIterator<T>::operator++() {
    this->next();
}

template <class T>
void ArrayIterator<T>::operator++(int) {
    this->next();
}

template <class T>
void ArrayIterator<T>::operator--() {
    this->prev();
}

template <class T>
void ArrayIterator<T>::operator--(int) {
    this->prev();
}

template <class T>
T ArrayIterator<T>::operator*() {
    return this->value();
}

template <class T>
T ArrayIterator<T>::operator[](int index) {
    if ( index < 0 ) {
        index = 0;
    } else if ( index >= this->size ) {
        index = this->size - 1;
    }
    
    return this->array[index];
}

template class ArrayIterator<int>;
template class ArrayIterator<float>;
template class ArrayIterator<double>;
template class ArrayIterator<char>;
