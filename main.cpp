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


		// cout  êîìàíäû êàê???

	}
	if (num == 1) {
		cells[cell - 1] ='X';
		
	}
	else cells[cell - 1] = 'O';



	
}

char check(){
	for (int i = 0; i < 3; i++) { //Äëÿ ïîáåäû íóæíû 3 êëåòî÷êè

		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2] && cells[i * 3]!=' '){ //ïî ãîðèçîíòàëè 0-1-2, 3-4-5 è 6-7-8

			return cells [i];;
			}

		if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6] && cells[i]!=' '){ //ïî âåðòèêàëè 0-3-6, 1-4-7 è 2-5-8
		return cells [i];
			}

		if ((cells[2] == cells[4] && cells[4] == cells[6] && cells[2]!=' ') || (cells[0] == cells[4] && cells[4] == cells[8]) && cells[0]!=' '){ // ïî äèàãîíàëè 0-4-8 è 2-4-6

			return cells [i];
			}
	}
	
		return ' '; //Èíà÷å - íè÷üÿ
	
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
		if (move >= 5) { /*Åñëè íîìåð õîäà 5 èëè áîëüøå, òî ïðîõîäèò ïðîâåðêà íà ïîáåäó (ðàíüøå, ÷åì íà 5-îì õîäå ïîáåäèòü íåëüçÿ)*/
		check();
			char  win = check(); //Ñèìâîë ïîáåäû - ýòî âîçâðàùåííîå çíà÷åíèå ôóíêöèè ïðîâåðêè
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
