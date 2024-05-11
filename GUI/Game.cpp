#include "Game.hpp"

Game::Game() {
    create_empty_board();
    this->Current_player = 1;
    marks[0] = 'X';
    marks[1] = 'O';
}

void Game::create_empty_board() {
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

char Game::getmark() {
    return marks[Current_player-1];
}

bool Game::valid_input(int input_location) {
    if (board[input_location] != ' '){

        return false;
    }
    return true;
}

void Game::make_move(int input_location) {
    board[input_location] = getmark();
}

int Game::getplayer() {
    return this->Current_player;
}

void Game::switch_player() {
    if (Current_player == 1)
    {
        Current_player = 2;
    }
    else
    {
        Current_player = 1;
    }
}

char Game::check_game() {
    for (int i = 0; i < 3; i++) {
        if (compare_row((i * 3), "row") != ' ') {
            return board[(i * 3)];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (compare_row(i, "column") != ' ') {
            return board[i];
        }
    }

    if (compare_row(0, "diag") != ' ') {
        return board[0];
    }

    if (compare_row(2, "diag") != ' ') {
        return board[2];
    }

    if (checkallcells() == 0)
    {
        return 'C';
    }

    return ' ';
}

char Game::compare_row(int frst, string direction) {
    int output1 = 0;
    int change;

    if (direction == "row") {
        change = 1;
    }
    else if (direction == "column") {
        change = 3;
    }
    else {
        if (frst > 1)
        {
            change = 2;
        }
        else {
            change = 4;
        }

    }

    char markvalue;
    for (int i = 0; i < 2; i++)
    {
        markvalue = board[frst + (i * change)];
        if (markvalue != board[frst + ((i + 1) * change)] || markvalue == ' ') {
            output1 = 1;
        }
    }

    if (output1 == 1)
    {
        return ' ';
    }
    return board[frst];
}

int Game::checkallcells() {
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return 1;
        }
    }
    return 0;
}

