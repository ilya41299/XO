#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
char win;
int k_quit;
int ex;

void show_cells(char *cells) {
	cout << "   1   2   3" << endl;
	cout << " +---+---+---+" << endl;
	cout << "a| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "b| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "c| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |" << endl;
	cout << " +---+---+---+" << endl;
}

void show_available_moves(char op, char *cells) {

	int k = 0;
	for (int i = 0; i < 9; i++) {
		if (!(cells[i] == 'X' || cells[i] == 'O')) {
			if (i < 3) {
				cout << ++k << ".mark cell a" << i + 1 << " as " << op << endl;
			}
			if (i>2 && i<6) {
				cout << ++k << ".mark cell b" << i - 2 << " as " << op << endl;
			}
			if (i>5) {
				cout << ++k << ".mark cell c" << i - 5 << " as " << op << endl;
			}
		}
	}
	cout << ++k << ". quit" << endl;
	k_quit = k;
}

int make_move(int move, char op, char *cells) {
	int cell;
	string string;
	getline(cin, string);
	istringstream stream(string);
	stream >> cell;
	while (cell < 1 || cell >(11 - move)) {
		cout << endl << "You can not use this move. Enter another move" << endl;
		getline(cin, string);
		istringstream stream(string);
		stream >> cell;
	}
	int k = 0;
	for (int i = 0; i < 10; i++){
		if (cells[i] == ' ') {
			k++;
		}
		if (k == cell) {
			cells[i] = op;
			show_cells(cells);
			return 0;
			}
	}
	if (cell == k_quit) {
		cout << "GAME OVER" << endl;
		ex = k_quit;
		return -1;
	}
	return 0;
}

char check(char *cells) {
	for (int i = 0; i < 3; i++) {

		if ((cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) && cells[i * 3] != ' ') {

			return cells[i];;
		}

		if ((cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) && cells[i] != ' ') {
			return cells[i];
		}

		if (((cells[2] == cells[4] && cells[4] == cells[6]) && cells[2] != ' ') || ((cells[0] == cells[4] && cells[4] == cells[8]) && cells[0] != ' ')) {

			return cells[i];
		}
	}

	return ' ';

}

int main() {
	char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char op;
	show_cells(cells);
	for (int move = 1; move <= 9; move++) {
		if (move % 2) {
			op = 'X';
			show_available_moves(op, cells);
			make_move(move, op, cells);
		}
		else {
			op = 'O';
			show_available_moves(op, cells);
			make_move(move, op, cells);
		}
		if (k_quit == ex) {
			return -1;
		}
		if (move >= 5) {
			check(cells);
			char  win = check(cells);
			if (win == 'X') {
				cout << "X win" << endl;
				return -1;
			}
			if (win == 'O') {
				cout << "O win" << endl;
				return -1;
			}
			if (move == 9 && win != 'X' && win != 'O') {
				cout << "Draw!" << endl;
				return -1;
			}
		}
	}
	if (k_quit == ex) {
		return -1;
	}
	return 0;
}
