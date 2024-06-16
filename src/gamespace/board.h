#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
#include "coord.h"

class Board {
public:
    Board(int size);

    void createCoords();
    void printBoard() const;

private:
    int size;
    Eigen::Matrix<coord, Eigen::Dynamic, Eigen::Dynamic> matrix;
};

#endif // BOARD_H
