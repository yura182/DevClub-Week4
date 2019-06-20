#include "Location.h"

Location::Location(int x, int y, const std::string& name) {
    if ( locations.empty() ) {
        locations = init();
        freeLocations = locations;
    }
    Point temp(x, y);
    this->point = temp;
    
    if ( !isEmptyLocation(this->point) ) {
        throw LocationIsNotEmpty();
    }
    
    freeLocations.erase(point);
    occupiedLocations.insert(std::pair<Point,char>(point, name[0]));
    
    debugPrint("Location created");
}

Location::~Location() {
    occupiedLocations.erase(this->point);
    freeLocations.insert(this->point);
    
    debugPrint("Location destroyed");
}

bool Location::isEmptyLocation(Point& point) {
    std::set<Point>::const_iterator it = freeLocations.find(point);
    
    if ( it == freeLocations.end() ) {
        return false;
    } else {
        return true;
    }
}

const Point& Location::getPoint() const {
    return this->point;
}

const std::set<Point>& Location::getLocations() {
    return locations;
}

const std::set<Point>& Location::getFreeLocations() {
    return freeLocations;
}

const std::map<Point,char>& Location::getOccupiedLocations() {
    return occupiedLocations;
}

void Location::printField() const {
    for ( int i = 1; i <= FIELD_HEIGHT; i++ ) {
        for ( int j = 1; j <= FIELD_WIDTH; j++ ) {
            std::cout << "\033[0;30;44m" << " ";
        }
        std::cout << "\033[0;30m" << "\n";
    }
    std::cout  << "\033[s";
    
    std::map<Point,char>::iterator it = occupiedLocations.begin();
    
    for ( int color = 31; it != occupiedLocations.end(); it++, color++ ) {
        std::cout << "\033[" << it->first.getY()<< "A";
        std::cout << "\033[" << it->first.getX()<< "C" << "\033[1D";
        std::cout << "\033[1;" << color<< ";44m" << it->second;
        std::cout << "\033[u";
        
        if ( color == 37 ) {
            color = 30;
        }
    }
}

std::set<Point> Location::init() {
    std::set<Point> temp;
    
    for ( int i = 1; i <= FIELD_HEIGHT; i++ ) {
        for ( int j = 1; j <= FIELD_WIDTH; j++ ) {
            temp.insert(Point(j, i));
        }
    }
    
    return temp;
}

void Location::move(char direction) {
    switch (direction) {
        case 'U':
            this->moveUp();
            break;
        case 'D':
            this->moveDown();
            break;
        case 'L':
            this->moveLeft();
            break;
        case 'R':
            this->moveRight();
            break;
        default:
            std::cout << "Wrong dirrection" << std::endl;
            break;
    }
}

void Location::moveUp() {
    int currentX = this->point.getX();
    int currentY = this->point.getY();
    
    if ( currentY == FIELD_HEIGHT ) {
        std::cout << "Unit can't move there" << std::endl;
        return;
    }
    
    Point newPoint(currentX, currentY+1);
    
    if ( !isEmptyLocation(newPoint) ) {
        std::cout << "This location is ocuppied, choose another or attack!" << std::endl;
        return;
    }
    
    changePosition(newPoint);
    
    std::cout << "Unit move to point " << this->point << std::endl;
    
}

void Location::moveDown() {
    int currentX = this->point.getX();
    int currentY = this->point.getY();
    
    if ( currentY == 1 ) {
        std::cout << "Unit can't move there" << std::endl;
        return;
    }
    
    Point newPoint(currentX, currentY-1);
    
    if ( !isEmptyLocation(newPoint) ) {
        std::cout << "This location is ocuppied, choose another or attack!" << std::endl;
        return;
    }
    
    changePosition(newPoint);
    
    std::cout << "Unit move to point " << this->point << std::endl;
}

void Location::moveLeft() {
    int currentX = this->point.getX();
    int currentY = this->point.getY();
    
    if ( currentX == 1 ) {
        std::cout << "Unit can't move there" << std::endl;
        return;
    }
    
    Point newPoint(currentX-1, currentY);
    
    if ( !isEmptyLocation(newPoint) ) {
        std::cout << "This location is ocuppied, choose another or attack!" << std::endl;
        return;
    }
    
    changePosition(newPoint);
    
    std::cout << "Unit move to point " << this->point << std::endl;
}

void Location::moveRight() {
    int currentX = this->point.getX();
    int currentY = this->point.getY();
    
    if ( currentY == FIELD_WIDTH ) {
        std::cout << "Unit can't move there" << std::endl;
        return;
    }
    
    Point newPoint(currentX+1, currentY);
    
    if ( !isEmptyLocation(newPoint) ) {
        std::cout << "This location is ocuppied, choose another or attack!" << std::endl;
        return;
    }
    
    changePosition(newPoint);
    
    std::cout << "Unit move to point " << this->point << std::endl;
}

void Location::changePosition(Point& newPoint) {
    occupiedLocations.insert(std::pair<Point,char>(newPoint, occupiedLocations.at(this->point)));
    occupiedLocations.erase(this->point);
    
    freeLocations.insert(this->point);
    freeLocations.erase(newPoint);
    
    this->point = newPoint;
}

Point Location::nearestEmptyPoint(const Point& point) {
    std::set<Point>::iterator it = freeLocations.begin();
    
    if ( it == freeLocations.end() ) {
        std::cout << "There is not space in the battlefiled" << std::endl;
        return point;
    }
    
    Point nPoint = *it;
    double minDist = point.distance(nPoint);
    double currentDist;
    
    for ( it++; it != freeLocations.end(); it++ ) {
        currentDist = point.distance(*it);
        
        if ( minDist > currentDist ) {
            minDist = currentDist;
            nPoint = *it;
        }
    }
    
    return nPoint;
}

std::set<Point> Location::locations;
std::set<Point> Location::freeLocations;
std::map<Point,char> Location::occupiedLocations;

std::ostream& operator<<(std::ostream& out, Location& location) {
    out << "location:" << location.getPoint();
    
    return out;
}
