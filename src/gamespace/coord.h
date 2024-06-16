// coord.h
#ifndef Coord
#define COORD_H

enum class CellState {
    HIDDEN,
    REVEALED,
    FLAGGED
};

struct Cell {
    bool hasMine; 
    int adjMines;
    CellState state;
};

class coord {
    int x;
    int y;
    Cell state;

public:
    coord(int x, int y) : x(x), y(y) {}

    bool checkAdj(const coord& other) const{
        return(this->x == other.x && (this->y+1 == other.y || this->y-1 == other.y)) ||
        (this->y == other.y && (this->x+1 == other.x || this->x-1 == other.x));
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

    //methods below are inter-twined with the board class.
    void setState()const{
        //TODO
    }

private:
    
    int searchBombs()const{
        //TODO
    }
};

#endif // COORD_H
