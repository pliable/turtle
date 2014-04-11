#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

/**
   Turtle program - This program will
      read input and move a little turtle
      around a map, drawing or not as it
      moves around. The original spec was
      a friends assignment but I did it
      for fun.

   @author Steve Choo
*/
void print_arr(short floor[MAX_SIZE][MAX_SIZE]);
void turn(int *cur_dir, int direction);
void move(short floor[MAX_SIZE][MAX_SIZE], int *current_direction, int coords[2], int steps, int pen_position);

/*
   Could be optimized further probably, but works for the most part
   */
int main(int argc, char *argv[]) {
   int i, j, nastyflag = 0;
   int steps;
   int pen_position = PEN_UP;
   int coord[2] = { 0, 0 };
   short floor[MAX_SIZE][MAX_SIZE];
   int current_command, current_direction = NORTH;

   for(i = 0; i < MAX_SIZE; i++) {
      for(j = 0; j < MAX_SIZE; j++) {
         floor[i][j] = 0;
      }
   }


   while(1) {
      printf("Enter a command: ");
      scanf("%d", &current_command);
      printf("\n");

      switch(current_command) {
         case PEN_UP:
            pen_position = PEN_UP;
            printf("Pen is up now dog.\n");
            break;
         case PEN_DOWN:
            pen_position = PEN_DOWN;
            printf("Pen is down now dog.\n");
            break;
         case TURN_RIGHT:
            turn(&current_direction, TURN_RIGHT);
            printf("I just turned right dog.\n");
            break;
         case TURN_LEFT:
            turn(&current_direction, TURN_LEFT);
            printf("I just turned left dog.\n");
            break;
         case MOVE_FORWARD:
            printf("How many motherfucking steps do you want to take? ");
            scanf("%d", &steps);
            move(floor, &current_direction, coord, steps, pen_position);
            printf("If your move was valid, I just moved %d steps dog.\n", steps);
            break;
         case PRINT_ARR:
            print_arr(floor);
            break;
         case END_OF_DATA:
            printf("Thank you goodbye\n");
            exit(EXIT_SUCCESS);
            break;
         default:
            printf("Invalid command, please try again\n");
            break;
      }
   }

   
   return 0;
}

void move(short floor[MAX_SIZE][MAX_SIZE], int *current_direction, int coords[2], int steps, int pen_position) {
   int i;
   
   if(*current_direction == NORTH) {
      if(coords[Y] + steps > MAX_SIZE - 1) {
         printf("Invalid move, out of bounds");
         return;
      }
      
      if(pen_position == PEN_DOWN) {
         for(i = coords[Y]; i < coords[Y] + steps; i++) {
            floor[coords[X]][i] = 1;
         }
      }

      coords[Y] += steps;

   } else if(*current_direction == SOUTH) {
      if(coords[Y] - steps < 0) {
         printf("Invalid move, out of bounds");
         return;
      }

      if(pen_position == PEN_DOWN) {
         for(i = coords[Y] - steps; i < coords[Y]; i++) {
            floor[coords[X]][i] = 1;
         }
      }

      coords[Y] -= steps;
   } else if(*current_direction == WEST) {
      if(coords[X] - steps < 0) {
         printf("Invalid move, out of bounds");
         return;
      }

      if(pen_position == PEN_DOWN) {
         for(i = coords[X] - steps; i < coords[X]; i++) {
            floor[i][coords[Y]] = 1;
         }
      }

      coords[X] -= steps;

   } else if(*current_direction == EAST) {
      if(coords[X] + steps > MAX_SIZE - 1) {
         printf("Invalid move, out of bounds");
         return;
      }

      if(pen_position == PEN_DOWN) {
         for(i = coords[X]; i < coords[X] + steps; i++) {
            floor[i][coords[Y]] = 1;
         }
      }

      coords[X] += steps;
   }
}

//feel like this could be simplified but meh
void turn(int *cur_dir, int direction) {
   if(direction == TURN_RIGHT) {
      switch(*cur_dir) {
         case NORTH:
            *cur_dir = EAST;
            break;
         case SOUTH:
            *cur_dir = WEST;
            break;
         case EAST:
            *cur_dir = SOUTH;
            break;
         case WEST:
            *cur_dir = NORTH;
            break;
         default:
            break;
      }

   } else {
      switch(*cur_dir) {
         case NORTH:
            *cur_dir = WEST;
            break;
         case SOUTH:
            *cur_dir = EAST;
            break;
         case EAST:
            *cur_dir = NORTH;
            break;
         case WEST:
            *cur_dir = SOUTH;
            break;
         default:
            break;
      }
   }
}

void print_arr(short floor[MAX_SIZE][MAX_SIZE]) {
   int i, j;

   for(i = 0; i < MAX_SIZE; i++) {
      for(j = 0; j < MAX_SIZE; j++) {
         if(floor[i][j]) {
            printf("[ * ]");
         } else {
            printf("[   ]");
         }
      }
      printf("\n");
   }
}
