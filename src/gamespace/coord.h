// coord.h
#ifndef COORD_H
#define COORD_H

#include <iostream>

class coord {
public:
    double x, y;

    coord() : x(0), y(0) {}
    coord(double x, double y) : x(x), y(y) {}

    coord operator+(const coord& other) const {
        return coord(x + other.x, y + other.y);
    }

    coord operator-(const coord& other) const {
        return coord(x - other.x, y - other.y);
    }

    coord operator*(double scalar) const {
        return coord(x * scalar, y * scalar);
    }

    coord operator/(double scalar) const {
        return coord(x / scalar, y / scalar);
    }

    friend std::ostream& operator<<(std::ostream& os, const coord& c) {
        os << "(" << c.x << ", " << c.y << ")";
        return os;
    }
};

#endif // COORD_H