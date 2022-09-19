//Written by Olumayowa Olowomeye   8/2018
#include <iostream>
#include <vector>


using namespace std;
struct winFlag {
	bool win;
	char player;
	winFlag(bool a, char b) :win(a), player(b) {};
	winFlag() :win(false), player(' ') {};
};
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char player = 'X';
void draw() {
	system("cls");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			cout << " " << board[i][j] << " ";
			if (j != 2) {
				cout << "|";
			}
		}
		cout << endl;
	}
}
void input() {
	char x;
	cout << "Choose the number you wish to place your piece (" << player << ") on: \n 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 " << endl;
	cin >> x;
	switch (x){
	case '1':
		if (board[0][0] == ' ') {
			board[0][0] = player;
		}
		else {
			draw();
			cout <<  "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '2':
		if (board[0][1] == ' ') {
			board[0][1] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '3':
		if (board[0][2] == ' ') {
			board[0][2] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '4':
		if (board[1][0] == ' ') {
			board[1][0] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '5':
		if (board[1][1] == ' ') {
			board[1][1] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '6':
		if (board[1][2] == ' ') {
			board[1][2] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '7':
		if (board[2][0] == ' ') {
			board[2][0] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '8':
		if (board[2][1] == ' ') {
			board[2][1] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	case '9':
		if (board[2][2] == ' ') {
			board[2][2] = player;
		}
		else {
			draw();
			cout << "There is already a value a that point please try again" << endl;
			input();
		}
		break;
	default:
		draw();
		cout << "That is not a valid input. Please try again" << endl;
		input();
		break;
	}
}
bool same(char* x) {
	if (x[0] == x[1] && x[1] == x[2]) {
		return true;
	};
	return false;
}
void changePlayer() {
	if (player =='X'){
		player = 'O';
	}
	else {
		player = 'X';
	}
}
winFlag check() {
	if (same(board[0])) {
		return winFlag(true, board[0][0]);
	}
	else if (same(board[1])) {
		return winFlag(true, board[1][0]);
	}
	else if (same(board[2])) {
		return winFlag(true, board[2][0]);
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		return winFlag(true, board[1][0]);
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
		return winFlag(true, board[0][1]);
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
		return winFlag(true, board[0][2]);
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return winFlag(true, board[0][0]);
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return winFlag(true, board[0][2]);
	}
	else {
		return winFlag(false, ' ');
	}
}
int main() {
	bool win = false;
	winFlag flag;
	int count =0;
	char test[3] = {'a','a','a'};
	char test2[3] = {'a','b','c'};
	cout << same(test) << ' ' << same(test2) << endl;
	while (!win) {
		draw();
		input();
		changePlayer();
		count++;
		flag = check();
		if (flag.player != ' ' && flag.win) {
			draw();
			cout << "Player " << flag.player << " has won"<< endl;
			win = true;
		}
		else if (count == 9 && check().win==false) {
			draw();
			cout << "This is a tie" << endl;
			win = true;
		}
	}
	return 0;
}
