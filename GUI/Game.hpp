#pragma once
#include <array>
#include <string>

using namespace std;

class Game
{
private:
	int Current_player = 1;
	array<char, 9> board;
	array<char, 2> marks;

public:
	explicit Game();
	char getmark();
	bool valid_input(int input_location);
	void create_empty_board();
	void switch_player();
	int getplayer();
	void make_move(int input_location);
	char check_game();
	char compare_row(int frst, string direction);
	int checkallcells();
};

