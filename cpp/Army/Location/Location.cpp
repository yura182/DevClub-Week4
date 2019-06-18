#include "Location.h"

Location::Location(int x, int y) {
    if ( isEmptyLocation(x, y) ) {
        this->x = x;
        this->y = y;
    } else {
        throw LocationIsNotEmpty();
    }
    
    locations.insert(std::make_pair(x, y));
    
    debugPrint("Location created");
}

Location::~Location() {
    debugPrint("Location destroyed");
}

int Location::getX() const {
    return this->x;
}

int Location::getY() const {
    return this->y;
}

void Location::setXY(int x, int y) {
    if ( isEmptyLocation(x, y) ) {
        locations.erase(std::make_pair(this->x, this->y));
        
        this->x = x;
        this->y = y;
        
        locations.insert(std::make_pair(x, y));
    } else {
        std::cout << "Location is not empty" << std::endl;
    }
}

bool Location::isEmptyLocation(int x, int y) const {
    std::set<std::pair<int,int>>::iterator it;
    it = locations.find(std::make_pair(x, y));
    
    if ( it == locations.end() ) {
        return true;
    } else {
        return false;
    }
}

const std::set<std::pair<int,int>> Location::getLocations() {
    return locations;
}

std::set<std::pair<int,int>> Location::locations;

std::ostream& operator<<(std::ostream& out, const Location& location) {
    out << "location:(" << location.getX() << "," << location.getY();
    out << ")";
    
    return out;
}
