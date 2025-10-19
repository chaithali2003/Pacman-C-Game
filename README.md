# 🕹️ Pac-Man C Game

A simple **console-based Pac-Man game** implemented in C. Navigate Pac-Man through the board, eat all the food, and avoid demons!

---

## 🎯 Game Overview

* Collect all food items (`.`) on the board.
* Avoid demons (`X`), which end the game if touched.
* Navigate using the keyboard: `W` (Up), `A` (Left), `S` (Down), `D` (Right).
* Walls (`|`) block movement.
* The game ends when:

  * All food is eaten → **You Win!**
  * Pac-Man touches a demon → **Game Over!**

---

## ⚙️ Features

* Randomly generated game board each time.
* Random placement of walls, demons, and food.
* Score tracking (number of food eaten).
* Console-based interactive gameplay.
* Simple and lightweight implementation in C.

---

## 🛠️ Tools Required

* **Compiler:** GCC or any C compiler
* **IDE/Editor:** VS Code, Code::Blocks, Dev-C++, or any text editor
* **Operating System:** Windows (uses `conio.h` for keyboard input)

---

## 💻 How to Run

1. **Clone or download** the repository:

   ```bash
   git clone https://github.com/your-username/pacman-c-game.git
   cd pacman-c-game
   ```

2. **Compile the C program**:

   ```bash
   gcc pacman.c -o pacman
   ```

3. **Run the executable**:

   ```bash
   ./pacman      # Linux/macOS
   pacman.exe    # Windows
   ```

4. **Controls**:

   * `W` → Move Up
   * `A` → Move Left
   * `S` → Move Down
   * `D` → Move Right
   * `Q` → Quit the game

---

## 🏆 Gameplay Screenshot (Example)

```
########################################
#C.......|.....X......................#
#.........|..........................#
#.........|..........................#
#........................X...........#
#....................................#
#...........|.........................#
########################################
Score: 0
Total Food Left: 50
```

---

## 📄 Game Logic

* **Initialization**: Random walls, demons, food, and Pac-Man position.
* **Movement**: Pac-Man moves if the next cell is empty or contains food.
* **Score**: Increases when Pac-Man eats food.
* **End Game**: Win if all food is eaten; Lose if a demon is touched.

---

## 🤝 Contributing

Contributions are welcome!

* Feel free to improve the game logic.
* Add features like multiple levels, multiple demons, or improved AI.

---

## 📜 License

This project is **open-source** and free to use for learning purposes.

---

**Author:** Chaithali S
