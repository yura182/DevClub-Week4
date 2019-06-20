#include "Point.h"

Point::Point (int x, int y) {
    this->x = x;
    this->y = y;
}

Point::~Point() {}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int value) {
    this->x = value;
}

void Point::setY(int value) {
    this->y = value;
}

double Point::distance(const Point& other) const {
    return hypot(other.x - this->x, other.y - this->y);
}

bool Point::operator==(const Point& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

bool Point::operator<(const Point& other) const {
    return this->x < other.x || (this->x == other.x && this->y < other.y);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.getX() << "," << point.getY() << ")";
    return out;
}
