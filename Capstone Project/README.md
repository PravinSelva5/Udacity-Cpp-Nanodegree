# Snake Game Capstone Project

This project is an implementation of the classic Snake Game for the Udacity C++ Nanodegree program. The game has been implemented using C++ and the SDL2 library.

## Project Structure

- `src/main.cpp`: The main function and game loop.
- `src/game.cpp` and `src/game.h`: Game class that handles the game logic.
- `src/controller.cpp` and `src/controller.h`: Controller class that handles user input.
- `src/renderer.cpp` and `src/renderer.h`: Renderer class that handles rendering the game objects.
- `src/snake.cpp` and `src/snake.h`: Snake class that handles the snake object and its behavior.
- `src/highscore.cpp` and `src/highscore.h`: HighScore class that handles the loading, saving, and updating of high scores.
- `src/menu.cpp` and `src/menu.h`: Menu class that handles the main menu and interaction with the user.

## Rubric Points

### README (All Rubric Points REQUIRED)

- The README is included with the project and has instructions for building/running the project.
- The README describes the project.
- The README indicates which rubric points are addressed.

### Compiling and Testing (All Rubric Points REQUIRED)

- The project code compiles and runs without errors.

### Loops, Functions, I/O

- A variety of control structures are used in the project, including `if`, `while`, and `for` loops.
- The project code is clearly organized into functions.
- The project reads data from a file (`highscores.txt`) and processes the data (in `highscore.cpp`).
- The project accepts input from a user as part of the necessary operation of the program (`controller.cpp` and `menu.cpp`).

### Object Oriented Programming

- The project code is organized into classes with class attributes and class methods.
- Classes use appropriate access specifiers for class members.
- Class constructors utilize member initialization lists (in `game.cpp`, `snake.cpp`, and `highscore.cpp`).
- Classes abstract implementation details from their interfaces (in `game.h`, `controller.h`, `renderer.h`, `snake.h`, `highscore.h`, and `menu.h`).
- Classes encapsulate behavior (in `game.cpp`, `controller.cpp`, `renderer.cpp`, `snake.cpp`, `highscore.cpp`, and `menu.cpp`).

### Memory Management

- The project makes use of references in function declarations (in `controller.h` and `renderer.h`).
- The project uses destructors appropriately (in `renderer.cpp`).
- The project uses the Rule of 5 in the Snake class (in `snake.cpp` and `snake.h`).
- The project uses move semantics to move data, instead of copying it, where possible (in `snake.cpp`).
- The project uses smart pointers instead of raw pointers (in `renderer.cpp` and `renderer.h` with `shared_ptr`).

### Concurrency

- Not applicable for this project.

## Dependencies

- cmake >= 3.7
- make >= 4.1
- SDL2 >= 2.0
- SDL2_image >= 2.0
- SDL2_ttf >= 2.0

## Build Instructions

1. Clone the repository:


1. Clone the repository:`git clone https://github.com/PravinSelva5/Udacity-Cpp-Nanodegree.git`
`cd "Udacity-Cpp-Nanodegree/Capstone Project"`
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run the game: `./SnakeGame`


## How to Play

- Use the arrow keys to control the snake.
- Eat the food (yellow square) to increase the snake's length.
- Avoid collisions with the snake's own body and the walls.
- The game ends when the snake collides with its body or the walls.
- Press 'q' to quit the game at any time.
- Press 'p' to pause and resume the game.

## High Scores

The high scores are saved in a file called `highscores.txt`. The game will automatically update the high scores when a new high score is achieved.




