//
// Created by goned on 21/04/2020.
//

//calling libraries/including other files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_output.h"
#include "game_init.h"
#include "game.h"

void initialize_turns(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], piece pieces){ //function to run the game

    int turnNum = 1; //declares all the integers and such
    int x,y,move;
    int x2,y2;
    int stackHeight;
    int nxtPlyr, curPlyr, available;
    int victory = 0;
    char direction[10];
    char choice[10];
    piece *current;

    while (victory == 0){ //while victory isn't true

        if(turnNum % 2 == 1){ //checks whose turn it is

            curPlyr = 0;
            nxtPlyr = 1;

        } else {

            curPlyr = 1;
            nxtPlyr = 0;

        }

        printf("Player %d turn, %d\n", curPlyr + 1, players[curPlyr].player_color);

        printf("Move a piece or place a reserved one (type move or place) \n"); //checks whether you want to move or place a reserved piece
        scanf("%s", choice);

        if(strncmp(choice, "move", 10) == 0) {


            printf("Enter Square you want to move \n");
            scanf("%d%d", &y, &x);

            if (board[x][y].stack->p_color == players[curPlyr].player_color) { //checks if you selected the right colour

                printf("Enter direction (up, down, left, right): \n"); //checks which direction you want to move
                scanf("%s", direction);

                if (strncmp(direction, "right", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move); //move as many squares as you like

                    if (move <= board[x][y].num_pieces && move > 0) {

                        y2 = y + move; //math to work out where you go

                        if (board[x][y2].type == VALID) {

                            current = board[x][y].stack;

                            while (current->next != NULL) {

                                current = current->next;

                            }

                            current->next = board[x][y2].stack;
                            board[x][y2].stack = board[x][y].stack; //places new piece at top of stack
                            board[x][y].stack = NULL;
                            board[x][y2].num_pieces++;

                        }


                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x][y2].stack;
                    stackHeight = 0; //counts stack

                    while (current->next != NULL) {

                        current = current->next;
                        stackHeight++;
                    }

                    if (stackHeight > 5) { //checks if stack is over 5

                        while (current->next != NULL) {

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].pieces++;

                            }else if(players->player_color != current->p_color){

                                players[curPlyr].captured++;

                            }

                        } //reflects captured/reserved values

                    }

                } else if (strncmp(direction, "left", 10) == 0) { //code above repeated for the other moves

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if (move <= board[x][y].num_pieces && move > 0) {

                        y2 = y - move;

                        if (board[x][y2].type == VALID) {

                            current = board[x][y].stack;

                            while (current->next != NULL) {

                                current = current->next;

                            }

                            current->next = board[x][y2].stack;
                            board[x][y2].stack = board[x][y].stack;
                            board[x][y].stack = NULL;
                            board[x][y2].num_pieces++;

                        }

                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x][y2].stack;
                    stackHeight = 0;

                    while (current->next != NULL) {

                        current = current->next;
                        stackHeight++;
                    }

                    if (stackHeight > 5) {

                        while (current->next != NULL) {

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].pieces++;

                            }else if(players->player_color != current->p_color){

                                players[curPlyr].captured++;

                            }


                        }

                    }

                } else if (strncmp(direction, "up", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if (move <= board[x][y].num_pieces && move > 0) {

                        x2 = x - move;

                        if (board[x2][y].type == VALID) {

                            current = board[x][y].stack;

                            while (current->next != NULL) {

                                current = current->next;

                            }

                            current->next = board[x2][y].stack;
                            board[x2][y].stack = board[x][y].stack;
                            board[x][y].stack = NULL;
                            board[x2][y].num_pieces++;

                        }

                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x2][y].stack;
                    stackHeight = 0;

                    while(current->next != NULL){

                        current = current->next;
                        stackHeight++;
                    }

                    if(stackHeight> 5){

                        while(current->next != NULL){

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].pieces++;

                            }else if(players->player_color != current->p_color){

                                players[curPlyr].captured++;

                            }


                        }

                    }

                } else if (strncmp(direction, "down", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if(move <= board[x][y].num_pieces && move > 0){

                        x2 = x + move;

                        if(board[x2][y].type == VALID) {

                            current = board[x][y].stack;

                            while(current->next != NULL){

                                current = current->next;

                            }

                            current->next = board[x2][y].stack;
                            board[x2][y].stack = board[x][y].stack;
                            board[x][y].stack = NULL;
                            board[x2][y].num_pieces++;

                        }

                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x2][y].stack;
                    stackHeight = 0;

                    while(current->next != NULL){

                        current = current->next;
                        stackHeight++;
                    }

                    if(stackHeight> 5){

                        while(current->next != NULL){

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].pieces++;

                            }else if(players->player_color != current->p_color){

                                players[curPlyr].captured++;

                            }


                        }

                    }

                } else {
                    printf("Wrong input");
                }

            } else {

                printf("That piece is not your colour \n");

            }


        } else if (strncmp(choice, "place", 10) == 0) { //if choose to place a piece

            printf("Enter Square you want to place a piece on \n");
            scanf("%d%d", &x, &y);

            current = (piece*)malloc(sizeof(piece));

            if(board[x][y].type == VALID && players->pieces > 0) { //places new piece

                current->next = board[x][y].stack->next;
                board[x][y].stack = current;

            }

            players[curPlyr].pieces--;

            current = board[x][y].stack;
            stackHeight = 0;

            while(current->next != NULL){ //checks stack height

                current = current->next;
                stackHeight++;
            }

            if(stackHeight> 5){

                while(current->next != NULL){

                    current = current->next;

                    if(players->player_color == current->p_color){

                        players[curPlyr].pieces++;

                    }else if(players->player_color != current->p_color){

                        players[curPlyr].captured++;

                    }

                }

            }

        }

        available = 0;

        for(int i=0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {

                if(board[i][j].type == VALID && board[i][j].stack != NULL) {

                    if (board[i][j].stack->p_color == players[nxtPlyr].player_color) { //checks if the next player has lost

                        available++;

                    }

                }

                if(available <= 0 && players[nxtPlyr].pieces > 0){

                    victory = 1;


                }

            }
        }

        turnNum++;

        if(victory == 1){

            printf("Player %d wins! \n", curPlyr);
            printf("Player %d captured %d pieces, player %d captured %d pieces! \n", curPlyr, players[curPlyr].captured, nxtPlyr, players[nxtPlyr].captured);

        }

        print_board(board); //calls to print board again

    }

}