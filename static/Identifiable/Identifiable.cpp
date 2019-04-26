#include "Identifiable.h"

int Identifiable::newId = 1;

Identifiable::Identifiable() {
    this->id = newId;
    newId += 1;
}

Identifiable::~Identifiable() {}

int Identifiable::getId() const {
    return this->id;
}
