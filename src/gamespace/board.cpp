// board.cpp
#include "board.h"

Board::Board(int size) : size(size), matrix(size, size) {
    createCoords();
}

void Board::createCoords() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix(i, j) = coord(i, j);
        }
    }
}


//this is more of a debug purpose
void Board::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
