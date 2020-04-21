#include <stdio.h>
#include <string.h>

#include "input_output.h"
#include "game_init.h"
#include "game.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    piece pieces;

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    initialize_turns(players, board, pieces);

    return 0;
}
