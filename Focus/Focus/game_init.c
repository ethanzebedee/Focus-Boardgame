#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM]){

    char choice = 'n';

    for (int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Player %d enter your name:", i + 1);
        scanf("%s", players[i].name);

        while (choice != 'G' && choice != 'R')
        {
            printf("What colour would you like, R for red or G for green:");
            scanf("\n%c", &choice);
        }

        if(choice == 'G'){
            players[i].player_color = GREEN;
            choice = 'R';
        } else if (choice == 'R'){
            players[i].player_color = RED;
            choice = 'G';
        }
    }

}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}

void initialize_turns(player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE], piece pieces){

    int turnNum = 1;
    int x,y,move;
    int x2,y2;
    int stackHeight;
    int nxtPlyr, curPlyr, available;
    int victory = 0;
    char direction[10];
    piece *current;

    while (victory == 0){

        if(turnNum % 2 == 1){

            curPlyr = 1;
            nxtPlyr = 2;

        } else {

            curPlyr = 2;
            nxtPlyr = 1;

        }

            printf("Player %d turn \n", curPlyr);
            printf("Enter Square you want to move \n");
            scanf("%d%d", &x, &y);

            if(board[x][y].stack->p_color == players[curPlyr].player_color) {

                printf("Enter direction (up, down, left, right): \n");
                scanf("%s", direction);

                if (strncmp(direction, "up", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if(move <= board[x][y].num_pieces && move > 0){

                        y2 = y + move;

                        if(board[x][y2].type == VALID) {

                            current = board[x][y].stack;

                            while(current->next != NULL){

                                current = current->next;

                            }

                            current->next = board[x][y2].stack;
                            board[x][y2].stack = board[x][y].stack;
                            board[x][y].stack = NULL;

                        }

                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x][y2].stack;
                    stackHeight = 0;

                    while(current->next != NULL){

                        current = current->next;
                        stackHeight++;
                    }

                    if(stackHeight> 5){

                        while(current->next != NULL){

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].captured++;

                            }

                        }

                    }

                } else if (strncmp(direction, "down", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if(move <= board[x][y].num_pieces && move > 0){

                        y2 = y - move;

                        if(board[x][y2].type == VALID) {

                            current = board[x][y].stack;

                            while(current->next != NULL){

                                current = current->next;

                            }

                            current->next = board[x][y2].stack;
                            board[x][y2].stack = board[x][y].stack;
                            board[x][y].stack = NULL;

                        }

                    } else {

                        printf("Invalid moves\n");

                    }

                    current = board[x][y2].stack;
                    stackHeight = 0;

                    while(current->next != NULL){

                        current = current->next;
                        stackHeight++;
                    }

                    if(stackHeight> 5){

                        while(current->next != NULL){

                            current = current->next;

                            if(players->player_color == current->p_color){

                                players[curPlyr].captured++;

                            }

                        }

                    }

                } else if (strncmp(direction, "left", 10) == 0) {

                    printf("Enter how far you'd like to move (You can move a 1 space for every piece in the stack): \n");
                    scanf("%d", &move);

                    if(move <= board[x][y].num_pieces && move > 0){

                        x2 = x - move;

                        if(board[x2][y].type == VALID) {

                            current = board[x][y].stack;

                            while(current->next != NULL){

                                current = current->next;

                            }

                            current->next = board[x2][y].stack;
                            board[x2][y].stack = board[x][y].stack;
                            board[x][y].stack = NULL;

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

                                players[curPlyr].captured++;

                            }

                        }

                    }

                } else if (strncmp(direction, "right", 10) == 0) {

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

                                players[curPlyr].captured++;

                            }

                        }

                    }

                } else {
                    printf("Wrong input");
                }

            } else {

                printf("That piece is not your colour");

            }

            available = 0;

        for(int i=0; i< BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {

                if(board[x][y].stack->p_color == players[nxtPlyr].player_color){

                    available++;

                }

                if(available <= 0){

                    victory = 1;


                }

            }
        }

        turnNum++;

    }

    if(victory == 1){

        printf("Player %d wins!", curPlyr);

    }

}

