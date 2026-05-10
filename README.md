# TicTacToe

Console-based Tic-Tac-Toe game developed in C with modular source code organization and Windows console customization.

![C](https://img.shields.io/badge/C-Programming-blue)
![CMake](https://img.shields.io/badge/CMake-Build%20System-green)
![Windows](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Console App](https://img.shields.io/badge/Application-Console%20App-informational)

## Demo

https://github.com/user-attachments/assets/80936e50-ba60-4018-8a80-40d0f85f8bd0

## What is it?

TicTacToe is a desktop console application that implements the classic Tic-Tac-Toe game for two local players.

The software manages the game board, player turns, input validation, win detection, draw detection, and final result visualization directly inside a Windows console interface.

The project is organized into separate source and header files to keep the game flow, console configuration, input handling, drawing functions, and result verification clearly separated.

## Features

- Two-player local gameplay
- Console-based user interface
- Turn-based game flow
- Input validation for player moves
- Win condition detection
- Draw condition detection
- Final result visualization
- Fixed and centered Windows console window
- Custom executable icon through Windows resource files
- Modular C source code organization

## Key Technical Aspects

- Modular separation between game flow, input handling, console configuration, drawing functions, and result verification
- Windows-specific console customization using the Windows API
- CMake-based build configuration
- Custom executable icon integration through a Windows resource file
- Input validation to prevent invalid or repeated moves
- Clear separation between source files and header files

## Technology Stack

- C
- CMake
- Windows API
- Windows resource file `.rc`
- CLion or another CMake-compatible IDE

## Requirements

- Windows operating system
- CMake
- A C compiler supported by CMake
- CLion, Visual Studio, or another CMake-compatible development environment

## Quick Start

### Clone the repository

```bash
git clone https://github.com/MattiaBenati/TicTacToe.git
cd TicTacToe
```

### Build the project

Generate the build files:

```bash
cmake -S . -B build
```

Build the executable:

```bash
cmake --build build
```

### Run the application

Run the generated executable from the build directory or directly from the IDE.

## Usage

1. Start the application
2. The console window is configured and displayed
3. The Tic-Tac-Toe board is shown
4. Players take turns selecting a cell
5. The program validates each selected move
6. The board is updated after every valid move
7. The game ends when a player wins or when the board is full
8. The final result is displayed in the console

## Controls

Players interact with the game by entering the number of the cell where they want to place their symbol.

The program accepts only valid moves and prevents players from selecting cells that are already occupied.

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
└── CMakeLists.txt
```

## Architecture Overview

The project follows a modular C structure, where each source file is responsible for a specific part of the application.

- `main.c`: starts the application and manages the main program flow
- `console.c`: configures the Windows console window behavior and appearance
- `disegno.c`: manages board drawing and visual output
- `grafica.c`: manages console graphics and interface elements
- `input.c`: handles player input and input validation
- `verifica.c`: checks the game state, win conditions, and draw conditions
- `include/`: contains the header files used by the source modules
- `assets/`: contains the application icon and Windows resource file
- `CMakeLists.txt`: defines the CMake build configuration

## Output

The software runs entirely inside the Windows console.

During execution, it displays the game board, the current player turn, validated moves, updated board states, and the final match result.

The final output indicates whether one player has won or whether the match ended in a draw.
