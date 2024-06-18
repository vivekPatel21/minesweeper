#include <iostream>
#include <GLFW/glfw3.h>
#include <random>
#include "gamespace/board.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Function prototypes
void drawBoard(const Board& board, int size);

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Board Visualization", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize board
    int boardSize = 10; // You can change this to any size
    Board board(boardSize);

    // Define a coordinate to ignore and populate the board with bombs
    coord ignore(2, 2);
    int numBombs = board.bombsToPlace(0.2f); // 20% of the board cells will be bombs
    board.populateBoard(ignore, numBombs);
    board.setValues();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Set the clear color to white
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the board
        drawBoard(board, boardSize);

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}

void drawBoard(const Board& board, int size) {
    float cellWidth = 2.0f / size; // Normalize the cell width to OpenGL's coordinate system
    float cellHeight = 2.0f / size; // Normalize the cell height to OpenGL's coordinate system

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            coord c = board.matrix(i, j);

            // Set color based on the state
            if (c.state == -1) {
                glColor3f(1.0f, 0.0f, 0.0f); // Red for bombs
            } else {
                glColor3f(0.0f, 0.0f, 0.0f); // Black for empty cells
            }

            // Draw the cell as a filled rectangle
            float x = -1.0f + j * cellWidth;
            float y = 1.0f - i * cellHeight;
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + cellWidth, y);
            glVertex2f(x + cellWidth, y - cellHeight);
            glVertex2f(x, y - cellHeight);
            glEnd();
        }
    }
}
