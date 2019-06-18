#ifndef LOCATION_H
#define LOCATION_H

#include <set>
#include <utility>
#include "../Helpers/Debug.h"
#include "../Helpers/Exceptions.h"

class Location {
    private:
        int x;
        int y;
        
        static std::set<std::pair<int,int>> locations;
    public:
        Location(int x, int y);
        ~Location();
        
        int getX() const;
        int getY() const;
        
        void setXY(int x, int y);
        
        bool isEmptyLocation(int x, int y) const;
        
        static const std::set<std::pair<int,int>> getLocations();
};

std::ostream& operator<<(std::ostream& out, const Location& location);

#endif // LOCATION_H
