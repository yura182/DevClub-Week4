#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include "../Helpers/Debug.h"

class Point {
    private:
        int x;
        int y;
    public:
        Point(int x=0, int y=0);
        ~Point();

        int getX() const;
        int getY() const;

        void setX(int value);
        void setY(int value);

        double distance(const Point& other) const;
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
        bool operator<(const Point& other) const;
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif // POINT_H
