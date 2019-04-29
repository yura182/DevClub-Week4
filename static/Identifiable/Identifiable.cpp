#include "Identifiable.h"

Identifiable::Identifiable() {
    total += 1;
    newId += 1;
    this->id = newId;
}

Identifiable::Identifiable(const Identifiable& copy) {
    total += 1;
    newId += 1;
    this->id = newId;
}

Identifiable& Identifiable::operator=(const Identifiable& copy) {
    return *this;
}

Identifiable::~Identifiable() {
    total -= 1;
}

int Identifiable::getId() const {
    return this->id;
}

int Identifiable::getTotal() {
    return total;
}

int Identifiable::total = 0;
int Identifiable::newId = 0;
