#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 17, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Function to generate fruit within the generated boundry
void setup() {
    gameover = 0;

    // Stores the height and width
    x =  height/2;
    y = width /2;
    label1:
        fruitx = rand() % 20;
        if(fruitx == 0) {
            goto label1;
        }
    label2:
        fruity = rand() % 20;
        if(fruity == 0) {
            goto label2;
        }
        score = 0;
}

// Function to draw the boundaries
void draw() {
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
        printf("#");
      } 
      else {
        if (i == x && j == y) {
          printf("0");
        }
        else if (i == fruitx && j == fruity){
          printf("*");
        }
        else {
          printf(" ");
        }
      }
    }
    printf("\n");    
  }
  // Print the score after the
  // game ends
  printf("score = %d", score);
  printf("\n");
  printf("press X to quit the game");
}

// Takes the inputs from the keyboard
void input() {
    if (kbhit()) {
        switch (getch()) {
            case 'a':
                flag = 1;
            case 's':
                flag = 2;
            case 'd':
                flag = 3;
            case 'w':
                flag = 4;
            case 'x':
                gameover = 1;
                break;
        } 
    }
}

// Function to set the snakes movement, score increment, ending the game if the snale touches the boundary or it's tail,
// random fruit generation after the snake eats the fruit, and exits the game if 'x' is pressed.
void logic() {
    sleep(0.01);
    // Snakes movement
    switch(flag) {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
        default:
            break;
    }

    // If the game is over
    if(x < 0 || x > height || y < 0 || y > width) {
        gameover = 1;
    }

    // Updates the score when the snakes 'eats' the fruit
    if (x == fruitx && y == fruity) {
        label3: fruitx = rand() % 20;
            if (fruitx == 0) {
                goto label3;
            }
        label4: fruity = rand() % 20;
            if (fruity == 0) {
                goto label4;
            }
        score += 10;
    }
}

// main function
int main(){
    int m, n;

    //generate boundary
    setup();

    // Run the game until gameover
    while(!gameover){
        draw();
        input();
        logic();
    }

    return 0;
}