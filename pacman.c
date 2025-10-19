#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// Game Elements
#define WIDTH 40 
#define HEIGHT 20 
#define PACMAN 'C' 
#define WALL '|' 
#define FOOD '.' 
#define EMPTY ' ' 
#define DEMON 'X' 

// Global Variables
int res = 0; 
int score = 0; 
int pacman_x, pacman_y; 
char board[HEIGHT][WIDTH]; 
int food = 50; 
int curr = 0; 

// Function to Initialize the Game Board
void initialize() 
{ 
    srand(time(0)); // Seed for random numbers to ensure different layouts

    // Creating Outer Walls (Boundaries)
    for (int i = 0; i < HEIGHT; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
            if (i == 0 || j == WIDTH - 1 || j == 0 || i == HEIGHT - 1) { 
                board[i][j] = WALL; 
            } else {
                board[i][j] = EMPTY; 
            }
        } 
    } 

    // Placing Random Walls inside the Game
    int count = rand() % 40 + 20;  // Randomized number of walls for variation
    while (count > 0) { 
        int i = rand() % HEIGHT; 
        int j = rand() % WIDTH; 

        if (board[i][j] == EMPTY) { 
            board[i][j] = WALL; 
            count--; 
        } 
    } 

    // Placing Random Demons
    count = rand() % 6 + 3; // Randomized number of demons
    while (count > 0) { 
        int i = rand() % HEIGHT; 
        int j = rand() % WIDTH; 

        if (board[i][j] == EMPTY) { 
            board[i][j] = DEMON; 
            count--; 
        } 
    } 

    // Setting Pacman at a Random Start Position
    while (1) {
        pacman_x = rand() % WIDTH;
        pacman_y = rand() % HEIGHT;
        if (board[pacman_y][pacman_x] == EMPTY) {
            board[pacman_y][pacman_x] = PACMAN;
            break;
        }
    }

    // Placing exactly 50 food items 
    count = 50;
    while (count > 0) {
        int i = rand() % HEIGHT;
        int j = rand() % WIDTH;

        // Place food only if the space is empty (not a wall or demon)
        if (board[i][j] == EMPTY) {
            board[i][j] = FOOD;
            count--;
        }
    }
} 

// Function to Draw the Game Board
void draw() 
{ 
    system("cls"); // Clears the console screen

    // Display the Game Board
    for (int i = 0; i < HEIGHT; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
            printf("%c", board[i][j]); 
        } 
        printf("\n"); 
    } 

    // Display Score
    printf("Score: %d\n", score); 
    printf("Total Food Left: %d\n", food);
} 

// Function to Move Pacman
void move(int move_x, int move_y) 
{ 
    int x = pacman_x + move_x; 
    int y = pacman_y + move_y; 

    if (board[y][x] != WALL) { 
        if (board[y][x] == FOOD) { 
            score++; 
            food--; 
            curr++; 
            if (food == 0) { 
                res = 2; // Player Wins
                return; 
            } 
        } 
        else if (board[y][x] == DEMON) { 
            res = 1; // Player Loses
        } 

        // Update Pacman's Position
        board[pacman_y][pacman_x] = EMPTY; 
        pacman_x = x; 
        pacman_y = y; 
        board[pacman_y][pacman_x] = PACMAN; 
    } 
} 

// Main Function
int main() 
{ 
    char ch;
    
        initialize(); 

        // Instructions
        printf("Use keys: W (Up), A (Left), D (Right), S (Down)\n");
        printf("Press any key to quit.\n");
        printf("Press 'Y' to start the game: \n"); 

        ch = getch(); 
        if (ch != 'Y' && ch != 'y') { 
            printf("Exit Game! \n"); 
            return 1; 
        }

        // Game Loop
        while (1) { 
            draw(); 

            // Check Win/Lose Condition
            if (res == 1) { 
                system("cls"); 
                printf("Game Over! You were caught by a Demon.\n");
                printf("Total Food Eaten: %d\n\n", score); 
                break;
            } 

            if (res == 2) { 
                system("cls"); 
                printf("Congratulations! You Won!\n");
                printf("Total Food Eaten: %d\n\n", score); 
                break;
            } 

            // Take Input from User
            ch = getch(); 

            // Move Pacman Based on Input
            switch (ch) { 
            case 'w': move(0, -1); break; 
            case 's': move(0, 1); break; 
            case 'a': move(-1, 0); break; 
            case 'd': move(1, 0); break; 
            case 'q': case 'Q': 
                printf("Game Over! Total Food Eaten: %d\n\n", score); 
                return 0; 
            } 
      }
    return 0; 
}
