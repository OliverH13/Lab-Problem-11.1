
#include <iostream>

using namespace std;

const int ROWS = 13;
const int COLUMNS = 8;

int find_row_index(int thisRow);
int find_seat_index(char thisSeat);
void display_seat_column(char seats[][ROWS], int COLUMNS);

int main(void) {

	char seats[COLUMNS][ROWS];
	char thisSeat;
	int thisRow;
	int row;
	int column;

	for (int column = 0; column < COLUMNS; column++) { 
		char cnt = '1';
		char cnt2 = '0';
		for (int row = 0; row < ROWS; row++) {
			if (column == 0 && row != 12) seats[0][row] = 'D';
			if (column == 0 && row == 12) seats[0][row] = ' ';
			if (column == 1 && row != 12) seats[1][row] = 'C';
			if (column == 1 && row == 12) seats[1][row] = ' ';
			if (column == 2) seats[2][row] = ' ';
			if (column == 3 && row < 9) seats[3][row] = ' ';
			if (column == 3 && row >= 9) seats[3][row] = '1';
			if (column == 4 && row < 9) {
				seats[4][row] = cnt;
				cnt++;
			}
			if (column == 4 && row >= 9) {
				seats[4][row] = cnt2;
				cnt2++;
			}
			if (column == 5) seats[5][row] = ' ';
			if (column == 6) seats[6][row] = 'B';
			if (column == 7) seats[7][row] = 'A';
		}
	}

	while (true) {

		display_seat_column(seats, COLUMNS);
		cout << "Enter a seat or Q to quit: ";
		cin >> thisRow >> thisSeat;

		if (cin.fail()) break;

		row = find_row_index(thisRow);
		column = find_seat_index(thisSeat);

		if (row == ROWS + 1 || column == COLUMNS + 1) {
			cout << "Sorry, no such seat exists on the CRJ 200. " << endl;
		}
		else if (row == 12 && column == 0) cout << "Sorry, no such seat exists on the CRJ 200. " << endl;
		else if (row == 12 && column == 1) cout << "Sorry, no such seat exists on the CRJ 200. " << endl;

		else if (seats[column][row] != 'X') {
			seats[column][row] = 'X';
		}
		else if (seats[column][row] == 'X') {
			cout << "This seat has already been taken" << endl;
		}
	}
}

int find_row_index(int thisRow) {
	if (thisRow > 0 && thisRow <= ROWS) return thisRow - 1;
	else {
		return ROWS + 1;
	}
}

int find_seat_index(char thisSeat) {
	if (thisSeat == 'D') return 0;
	else if (thisSeat == 'C') return 1;
	else if (thisSeat == 'B') return 6;
	else if (thisSeat == 'A') return 7;
	else {
		return COLUMNS + 1; 
	} 
}

void display_seat_column(char seats[][ROWS], int column) {
	cout << endl;
	for (int column = 0; column < COLUMNS; column++) {
		for (int row = 0; row < ROWS; row++) {
			cout << seats[column][row] << " ";
		}
		cout << endl;
	}
	cout << endl;
}