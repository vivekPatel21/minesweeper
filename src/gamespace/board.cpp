#include "board.h"

Board::Board(int size) : size(size), matrix(size, size), gen(rd()), dis(0, size - 1) {
    createCoords();
}

void Board::createCoords() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix(i, j) = coord(i, j);
        }
    }
}

void Board::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int Board::bombsToPlace(float chosenDifficulty)const {
    int numOfCoords = this->size * this->size;
    return static_cast<int>(numOfCoords * chosenDifficulty);
}

void Board::populateBoard(coord ignore, int numberToPlace) { 
    int placed = 0;
    while (placed < numberToPlace) {
        int x = dis(gen);
        int y = dis(gen);

        if (matrix(x, y).x == ignore.x && matrix(x, y).y == ignore.y) {
            continue; 
        }

        if (matrix(x, y).state != -1) {
            matrix(x, y).placeBomb();
            placed++;
        }
    }
}

void Board::setValues() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix(i, j).state == -1) {
                continue; 
            }

            int bombCount = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size && matrix(ni, nj).state == -1) {
                        bombCount++;
                    }
                }
            }
            matrix(i, j).state = bombCount; // Set the bomb count in state
        }
    }
}

int Board::BFS(coord start) {
    std::queue<coord> q;
    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));

    int startX = static_cast<int>(start.x);
    int startY = static_cast<int>(start.y);

    if (matrix(startX, startY).state == -1) {
        return -1;
    }

    q.push(start);
    visited[startX][startY] = true;
    int count = 0;

    while (!q.empty()) {
        coord current = q.front();
        q.pop();

        int x = static_cast<int>(current.x);
        int y = static_cast<int>(current.y);

        count++;

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < size && ny >= 0 && ny < size && !visited[nx][ny] && matrix(nx, ny).state != -1) {
                    visited[nx][ny] = true;
                    q.push(matrix(nx, ny));
                }
            }
        }
    }
    return count;
}