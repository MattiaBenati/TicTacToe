# TicTacToe

A Windows console-based Tic-Tac-Toe game developed in C, featuring a fixed console layout, local two-player gameplay, score tracking, and custom executable resources.

## Demo

[Watch the demo video](TicTacToe.mp4)

## Overview

TicTacToe is a desktop console application that implements the classic 3x3 Tic-Tac-Toe game for two local players. The software allows players to alternate turns using the symbols `X` and `O`, select board positions through numeric input, track the score across multiple rounds, and exit the game through a confirmation screen.

The project is organized into separate modules for console configuration, board management, graphics rendering, input handling, and game-state verification. It also includes Windows-specific console customization, such as a fixed console size, centered window positioning, disabled resizing, a custom console title, and an embedded executable icon.

## Main Features

- Local two-player Tic-Tac-Toe gameplay
- Turn-based input for players `X` and `O`
- Numeric board position selection
- Remaining-position display during the game
- Score tracking for both players across multiple rounds
- Row, column, and diagonal win detection
- Draw handling when the board is full
- Exit confirmation screen with final score display
- Fixed and centered Windows console window
- Disabled console resizing, maximize action, quick edit, insert mode, and mouse input
- Custom executable icon and version metadata through a Windows resource file
- Prebuilt Windows executable included in the repository
- Desktop demo video included in the repository

## Requirements

To run the prebuilt executable:

- Windows operating system
- `TicTacToe.exe`

To build the project from source:

- Windows operating system
- CMake 4.0 or later
- C compiler compatible with the Windows API, such as MinGW
- IDE with CMake support, such as CLion, or a terminal-based CMake workflow

## Installation

Clone the repository or download the project files:

```bash
git clone https://github.com/username/TicTacToe.git
cd TicTacToe
```

Replace `username` with the correct GitHub account name.

## How to Run

To run the included executable on Windows, open the project folder and launch:

```bash
TicTacToe.exe
```

Alternatively, run the executable from the terminal:

```bash
./TicTacToe.exe
```

## Usage

After launching the software, the console window opens with a fixed layout and shows the game board, the current score, the remaining available positions, and the current player turn.

The player selects a position by typing a number from `1` to `9`:

```text
7 8 9
4 5 6
1 2 3
```

The number `0` opens the exit confirmation screen.

During the game:

1. Player `X` starts the round
2. Players alternate turns
3. Each player selects one available position
4. The program checks rows, columns, and diagonals after each move
5. When a player wins, the score is updated
6. If all positions are filled without a winner, the round ends as a draw
7. A new round starts automatically unless the user chooses to exit

## Project Structure

```text
TicTacToe/
├── assets/
│   ├── icon.ico
│   ├── icon.png
│   └── resource.rc
├── include/
│   ├── console.h
│   ├── disegno.h
│   ├── grafica.h
│   ├── input.h
│   └── verifica.h
├── src/
│   ├── console.c
│   ├── disegno.c
│   ├── grafica.c
│   ├── input.c
│   ├── main.c
│   └── verifica.c
├── CMakeLists.txt
├── TicTacToe.exe
├── TicTacToe.mp4
└── README.md
```

## Software Architecture

The project is divided into focused C modules:

- `main.c`: controls the main game loop, turn management, score tracking, round reset, and program termination
- `console.c`: configures the Windows console title, input mode, window style, fixed size behavior, and centered position
- `disegno.c`: allocates, initializes, and releases the 3x3 game board memory
- `grafica.c`: renders the console interface, borders, score area, available positions, game board, and final result screen
- `input.c`: reads and validates user input, converts numeric positions into board coordinates, and places the selected symbol
- `verifica.c`: checks rows, columns, diagonals, and exit confirmation input
- `resource.rc`: embeds the application icon and version information into the Windows executable
- Header files in `include/`: expose the functions used across the source modules

## Build Instructions

From the project root, configure and build the project with CMake:

```bash
cmake -S . -B build
cmake --build build
```

The executable will be generated inside the build output directory created by CMake.

The `CMakeLists.txt` file defines the project name through the `PROJECT_NAME` variable, includes all source files, registers the Windows resource file, and adds the `include/` directory to the compiler header search paths.

## Output

The software displays a console-based graphical interface containing:

- Current score for player `X` and player `O`
- Remaining available board positions
- Current player turn
- Tic-Tac-Toe board
- Exit confirmation screen
- Final score and match result when the user exits

The repository also contains:

- `TicTacToe.exe`: prebuilt Windows executable
- `TicTacToe.mp4`: desktop demo video of the software running
