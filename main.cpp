#include <iostream>
using namespace std;
	char win;
	char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


void show_cells() {
	cout << "   1   2   3" << endl;
	cout << " +---+---+---+" << endl;
	cout << "a| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "b| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "c| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |" << endl;
	cout << " +---+---+---+" << endl;
}

void show_available_moves(char op) {
		
	int k = 0;
	for (int i = 0; i < 9; i++) {
			if (!(cells[i] == 'X' || cells[i] == 'O')) {
				if (i < 3) {
					cout << ++k << ".mark cell a" << i + 1 << " as " << op << endl;
				}
				if (i>2 && i<6) {
					cout << ++k << ".mark cell b" << i + 1 << " as " << op << endl;
				}
				if (i>5) {
					cout << ++k << ".mark cell c" << i + 1 << " as " << op << endl;
				
			}
		}
	}
	cout << ++k << ". quit" << endl;
}

void make_move( int cell) {
	cin >> cell;
	cout << endl;
		while (cin >> cell)
		{
			int k = 0;
			for (int i = 0; i < 9; i++)
			{
				if (cells[i] == ' ') {
					k++;
				}
				if (cells[i] == 'X') {
					break;
				}
				if (cells[i] == 'O') {
					break;
				}
			}
		}
	}

char check() {
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
	char op;
	show_cells();
	for (int move = 1; move <= 9; move++) {
		if (move % 2) {
		   	op='X';
		   	show_available_moves(op);
			make_move(1);
		}
		else 	op='O';
		show_available_moves(op);
		make_move(2);
		show_cells();
		if (move >= 5) {
			check();
			char  win = check();
			if (win == 'X') {
				cout << "X win";
			}
			if (win == 'O') {
				cout << "O win";
			}
			if (move==9 && (win!='O') && (win!='X')) {
				cout << " nichja";
			}
			break;
		}

	}

	return 0;
}
