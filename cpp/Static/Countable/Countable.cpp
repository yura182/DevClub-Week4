#include "Countable.h"

Countable::Countable() {
    total += 1;
}

Countable::~Countable() {
    total -= 1;
}

int Countable::getTotal() {
    return total;
}

int Countable::total = 0;

