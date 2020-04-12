#include <stdio.h>
#include <string.h>

#include "input_output.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    initialize_turns(players, board);

    return 0;
}
