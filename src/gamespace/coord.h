// coord.h
#ifndef Coord
#define COORD_H

class coord {
    int x;
    int y;

public:
    coord(int x, int y) : x(x), y(y) {}

    bool checkAdj(const coord& other) const{
        return(this->x == other.x && (this->y+1 == other.y || this->y-1 == other.y)) ||
        (this->y == other.y && (this->x+1 == other.x | this->x-1 == other.x));
    }
    bool checkDiag(const coord& other) const{
        return (this->x+1 == other.x && this->y ==other.y) ||
        (this->x-1 == other.x && this->y-1 == other.y) ||
        (this->x+1 == other.x && this->y-1 == other.y) ||
        (this->x-1 == other.x && this->y+1 == other.y);
    }
    bool equals(const coord& other) const{
        return (this->x == other.x && this->y == other.y);
    }
};

#endif // COORD_H
