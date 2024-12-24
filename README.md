# **2048 Game**

**Description**  
This is a command-line implementation of the popular 2048 game. The objective is to slide numbered tiles on a 4x4 grid and combine them to create a tile with the value 2048. Players can move tiles in four directions (up, down, left, right), and the game ends when there are no valid moves left. The game also supports features like undo, restart, and high score saving.

---

## **Table of Contents**

1. [Features](#features)  
2. [How to Play](#how-to-play)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements) 

---

## **Features**

### **1. Core Gameplay**
- Slide numbered tiles in four directions to combine them.  
- Add a random tile (2 or 4) after every valid move.  
- Game ends when no valid moves are available.  

### **2. Score and High Score**
- Tracks the current score for each game.  
- Saves the highest score to a file (`highscore.txt`) across sessions.  

### **3. Undo and Restart**
- **Undo**: Revert to the previous state of the board.  
- **Restart**: Reset the game with a new board and score.  

### **4. User-Friendly Interface**
- Clear and interactive console display with formatted board.  
- Supports intuitive controls:  
  - **W**: Move Up  
  - **A**: Move Left  
  - **S**: Move Down  
  - **D**: Move Right  
  - **U**: Undo  
  - **R**: Restart  
  - **Q**: Quit  

---

## **How to Play**

1. **Start the Game**:  
   - Launch the program to see a 4x4 grid with two random tiles (2 or 4).  

2. **Make Moves**:  
   - Use the following keys to move the tiles:  
     - **W**: Slide Up  
     - **A**: Slide Left  
     - **S**: Slide Down  
     - **D**: Slide Right  

3. **Combine Tiles**:  
   - Tiles with the same value combine to form a new tile with twice the value.  

4. **Game Over**:  
   - The game ends when there are no empty spaces or valid moves left.  

5. **Additional Options**:  
   - **U**: Undo the last move.  
   - **R**: Restart the game with a new grid.  
   - **Q**: Quit the game and save the high score.  

---

## **Installation**

Follow these steps to set up and run the game locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd 2048-Game
   ```

2. Compile the program:
   ```bash
   g++ -o 2048 2048.cpp
   ```

3. Run the program:
   ```bash
   ./2048
   ```

---

## **Technologies Used**

- **Language**: C++  
- **Libraries**: `<iostream>`, `<fstream>`, `<ctime>`  

---

## **Future Enhancements**

- Add support for customizable grid sizes (e.g., 5x5 or 6x6).  
- Implement a graphical user interface (GUI) using libraries like SFML or SDL.  
- Introduce an online leaderboard for global high scores.  
- Add difficulty levels with varying probabilities for spawning tiles.  

---
