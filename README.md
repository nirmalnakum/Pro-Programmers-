# Snake Game (Console Application)

This is a simple Snake Game implemented in C++ where the player controls the snake to eat food, avoiding the snake's own body or the screen boundaries. The game increases speed as the score goes up. The game ends if the snake collides with its own body or the screen borders.

## Requirements

- A C++ compiler (e.g., GCC, MSVC)
- Windows operating system (because of `conio.h` and `windows.h`)

## Files

- `SnakeGame.cpp` - The main code for the Snake game.

## How to Play

1. Use **W**, **A**, **S**, **D** to control the snake.
   - **W**: Move up
   - **A**: Move left
   - **S**: Move down
   - **D**: Move right
2. The objective is to eat the fruit (represented by "F"). Each time you eat a fruit, your score increases by 10, and the length of the snake increases.
3. The snake's speed increases every time you score 50 points.
4. The game ends if the snake hits the wall or collides with its own body.
5. Press **Q** to quit the game.

## Features

- **Snake Movement**: The snake can move in four directions: up, down, left, right.
- **Fruit Eating**: The snake eats fruits, increasing its length.
- **Increasing Speed**: The game becomes more challenging as the speed increases.
- **Restart Game**: When the game ends, you can choose to restart or exit the game.

## Controls

- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right
- **Q**: Quit the game

## Code Overview

### Classes and Methods

- **SnakeGame class**: This class represents the Snake Game.
  - **Private Members**:
    - `w`, `h`: Dimensions of the game board.
    - `x`, `y`: Current position of the snake's head.
    - `foodX`, `foodY`: Position of the fruit.
    - `score`: Current score of the player.
    - `tailX[100]`, `tailY[100]`: Arrays to store the positions of the snake's tail.
    - `nTail`: Length of the snake's tail.
    - `speed`: Speed of the game.
    - `dir`: Current direction of the snake.
    - `gameOver`: Flag indicating if the game is over.
  - **Public Methods**:
    - `Draw()`: Draws the game screen, including the snake, food, and border.
    - `Input()`: Takes input from the user to change the snake's direction.
    - `Logic()`: Updates the snake's position and checks for collisions.
    - `Reset()`: Resets the game to the starting state.
    - `Run()`: Runs the main game loop.
  
### Key Features

- **`gotoxy()`**: This method moves the cursor to a specific position on the console.
- **`HideCursor()`**: This hides the cursor during gameplay for a smoother experience.
- **Game Speed**: The game speed decreases as the score increases, making the game more challenging as you play.

### Game Over and Restart
When the game ends:
- The player is prompted with the option to restart the game by pressing **Y** or exit the game by pressing **N**.

## How to Compile

1. **Windows (MSVC or MinGW)**:
   - Open a terminal (Command Prompt or PowerShell).
   - Navigate to the directory containing `SnakeGame.cpp`.
   - Run the following command to compile the code:
     ```
     g++ SnakeGame.cpp -o SnakeGame
     ```
   - Run the game:
     ```
     SnakeGame
     ```

## License

This project is open-source and can be modified as needed.
