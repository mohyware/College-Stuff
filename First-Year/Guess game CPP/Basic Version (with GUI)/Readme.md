# C++ Console Game

This is a simple console-based game developed in C++ where users are presented with geometric shapes and must calculate their area within a limited time based on the difficulty level they choose. The game is played in the console and has a basic menu system and user interface.

## Features

- Main menu with options to start the game, get help, or quit.
- Three difficulty levels: Easy, Medium, and Hard.
- Real-time shape area calculation game.
- Score is calculated based on the player's speed and accuracy.
- Console GUI using `SetConsoleTextAttribute` to change colors.
- Navigation through the menu using arrow keys and selection with the Enter key.
- Game loop with multiple trials, adjustable based on the chosen difficulty level.

## Getting Started

### Prerequisites

You need a Windows machine to run this game since it uses Windows-specific libraries such as `windows.h` for handling colors and console cursor movement.

### Compiling and Running

1. Make sure you have a C++ compiler installed (such as MinGW).
2. Open your terminal or command prompt and navigate to the directory where the game source code is located.
3. Compile the game using the following command:

   ```bash
   g++ -o game.exe game.cpp
   ```
4. Run the compiled game:
    ```bash
    ./game.exe
    ```