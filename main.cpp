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

void show_available_moves() {
	int s;
	for (int i = 0; i<9; i++) {
		if (i<3) {
			cout << ++s << ". mark cell a" << i + 1 << " as";
			//
		}
	}
}

void make_move(int num) {
	int cell;
	cin >> cell;
	cout << endl;
	while (cell>9 || cell<1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
		cout << " Enter a correct cells  number to make move";
		cin >> cell;
		cout << endl;


		// cout  команды как???

	}
	if (num == 1) {
		cells[cell - 1] ='X';
		
	}
	else cells[cell - 1] = 'O';



	
}

char check(){
	for (int i = 0; i < 3; i++) { //Для победы нужны 3 клеточки

		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]){ //по горизонтали 0-1-2, 3-4-5 и 6-7-8

			return cells [i];;
			}

		if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]){ //по вертикали 0-3-6, 1-4-7 и 2-5-8
		return cells [i];
			}

		if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8])){ // по диагонали 0-4-8 и 2-4-6

			return cells [i];
			}
	}
	
		return ' '; //Иначе - ничья
	
}




int main() {
	show_cells();
	show_available_moves();
	for (int move = 1; move <= 9; move++) {
		if (move % 2) {
			make_move(1);
		}
		else make_move(2);
		show_cells();
		if (move >= 5) { /*Если номер хода 5 или больше, то проходит проверка на победу (раньше, чем на 5-ом ходе победить нельзя)*/
		check();
			char  win = check(); //Символ победы - это возвращенное значение функции проверки
			if(win!=' ') {
			    if (win == 'X') {
		cout << "X win";
	}
	 if (win == 'O') {
		cout << "O win";
	}
	if (win == ' ') {
		cout << " nichja";
		}
			    
			    break;
			    }
		
		}
	}
	
	return 0;
}
