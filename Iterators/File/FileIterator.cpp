#include "FileIterator.h"

template <class T>
FileIterator<T>::FileIterator(std::string fileName) {
    this->in.open(fileName);
    this->in >> this->data;
    endOfFile = false;
}

template <class T>
FileIterator<T>::~FileIterator() {
    in.close();
}

template <class T>
T FileIterator<T>::value() const {
    return this->data;
}

template <class T>
bool FileIterator<T>::end() const {
    return this->endOfFile;
}

template <class T>
void FileIterator<T>::next() {
    if ( this->in >> this->data ) {
        return;
    }
    this->endOfFile = true;
}

template <class T>
void FileIterator<T>::reset() {
    in.clear();
    in.seekg(0, in.beg);
    this->in >> this->data;
}

template <class T>
void FileIterator<T>::operator++() {
    this->next();
}

template <class T>
void FileIterator<T>::operator++(int) {
    this->next();
}

template <class T>
T FileIterator<T>::operator*() {
    return this->data;
}

template class FileIterator<int>;
template class FileIterator<float>;
template class FileIterator<double>;
template class FileIterator<char>;

