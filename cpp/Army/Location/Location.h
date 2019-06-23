#ifndef LOCATION_H
#define LOCATION_H

#define FIELD_WIDTH 24
#define FIELD_HEIGHT 12

#include <set>
#include <map>
#include <iomanip>
#include "../Helpers/Debug.h"
#include "../Helpers/Exceptions.h"
#include "Point.h"

class Location {
    private:
        Point point;
        
        static std::set<Point> locations;
        static std::set<Point> freeLocations;
        static std::map<Point,char> occupiedLocations;
    public:
        Location(int x, int y, char letter);
        ~Location();
        
        bool isEmptyLocation(Point& point);
        
        const Point& getPoint() const;
        
        static const std::set<Point>& getLocations();
        static const std::set<Point>& getFreeLocations();
        static std::map<Point,char>& getOccupiedLocations();
        
        void printField() const;
        
        static std::set<Point> init();
        
        void move(char direction);
        
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        
        void changePosition(Point& newPoint);
        
        Point nearestEmptyPoint(const Point& point);
};

std::ostream& operator<<(std::ostream& out, Location& location);

#endif // LOCATION_H
