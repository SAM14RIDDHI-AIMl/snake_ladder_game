#include<stdio.h>
#include <stdlib.h>
#include <time.h>
  int main() {
const int SNAKE_HEAD[]={ 16,20,25,31,34};
const int SNAKE_TAIL[]={ 2,5,12,20,22};
const int num_snake = sizeof(SNAKE_HEAD)/sizeof(SNAKE_HEAD[0]);
const int LADDER_STARTS[]={6,11,15,21,23};
const int LADDER_ENDS[]={18,14,22,28,35};
const int num_ladder= sizeof(LADDER_STARTS)/sizeof(LADDER_STARTS[0]);
int player1position=0;
int player2position=0;
int diceroll;
int currentturn = 1;
char player_input;
srand(time(0));
printf("welcome to the game of snake and ladder");
while(player1position<100 && player2position<100 ){
if(currentturn == 1){
printf(" Player 1's Turn (Current Position: %d)\n", player1position);
do {
  printf("Player 1, press 'r' to roll the dice: ");
  scanf(" %c", &player_input);
if (player_input != 'r' && player_input != 'R') {
  printf("Invalid input! Please press 'r' or 'R'.\n");
  }
} 
while (player_input != 'r' && player_input != 'R');
diceroll = (rand() % 6) + 1;
printf("the outcome is %d\n",diceroll);
if (player1position + diceroll <= 100) {
 player1position += diceroll;
 printf("Player 1 moves to  the position %d.\n", player1position);
   }
else {
       printf("A %d would take Player 1 past 100. Stay put at %d.\n", diceroll, player1position);
}
            
for (int i = 0; i < num_snake; i++) {
    if (player1position == SNAKE_HEAD[i]) {
        printf("you landed on a snake at %d! and now you are Sliding down to %d.\n", player1position, SNAKE_TAIL[i]);
        player1position = SNAKE_TAIL[i];
        break; 
}
}

for (int i = 0; i < num_ladder; i++) {
    if (player1position == LADDER_STARTS[i]) {
        printf("you got a ladder at %d up to %d.\n", player1position, LADDER_ENDS[i]);
        player1position = LADDER_ENDS[i];
        break; 
    }
}
    

currentturn =2;
}
else{
printf(" Player 2's Turn(Current Position: %d )\n",player2position);
do {
  printf("Player 2, press 'r' to roll the dice: ");
  scanf(" %c", &player_input);
if (player_input != 'r' && player_input != 'R') {
  printf("Invalid input! Please press 'r' or 'R'.\n");
  }
} 
while (player_input != 'r' && player_input != 'R');
diceroll = (rand() % 6) + 1;
printf("the outcome is %d\n",diceroll);
if (player2position + diceroll <= 100) {
 player2position += diceroll;
 printf("Player 2 moves to  the position %d.\n", player2position);
            } 
else {
      printf("A %d would take Player 2 past 100. Stay put at %d.\n", diceroll, player2position);
            }
for (int i = 0; i < num_snake; i++) {
    if (player2position == SNAKE_HEAD[i]) {
        printf("you landed on a snake at %d! and now you are Sliding down to %d.\n", player2position, SNAKE_TAIL[i]);
        player2position = SNAKE_TAIL[i];
        break; 
}
}

for (int i = 0; i < num_ladder; i++) {
    if (player2position == LADDER_STARTS[i]) {
        printf("you got a ladder at %d up to %d.\n", player2position, LADDER_ENDS[i]);
        player2position = LADDER_ENDS[i];
 break; 
    }
}
currentturn =1;
}
}
if (player1position >= 100) {
        printf("🎉 Congratulations Player 1! You reached 100 first!\n");
    } 
else if (player2position >= 100) {
        printf("🎉 Congratulations Player 2! You reached 100 first!\n");
    }
    printf("Final Positions: Player 1 at %d, Player 2 at %d\n", player1position, player2position);

    return 0; 
}


