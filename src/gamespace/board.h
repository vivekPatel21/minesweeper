#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "coord.h"

class Board {
public:
    Board(int size);

private:
    int size;
    std::vector<coord> coordinates;

    void createCoords();
};

#endif // BOARD_H
