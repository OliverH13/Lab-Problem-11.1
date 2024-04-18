
#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 13;

int find_row_index(int this_row);
int find_seat_index(char this_seat);
void display_seat_column(char seats[][ROWS], int column);

int main() {
	char seats[50][ROWS];
	int seat;

	while (true) {
		display_seat_column(seats, 4);
		cout << "Enter a seat or Q to quit: ";
		cin >> seat;
		if (cin.fail()) break;

	}
}

int find_row_index(int this_row) {


	return 0;
}

int find_seat_index(char this_seat) {


	return 0;
}

void display_seat_column(char seats[][ROWS], int column) {
	cout << endl << "D D D D D D D D D D D D" << endl << "C C C C C C C C C C C C" << endl;
	cout << endl << "                 " << " 1" << " 1" << " 1" << " 1" << endl;
	cout << "1" << " 2" << " 3" << " 4" << " 5" << " 6" << " 7" << " 8" << " 9" << " 0" << " 1" << " 2" << " 3" << endl << endl;
	cout << "B B B B B B B B B B B B B" << endl << "A A A A A A A A A A A A A" << endl << endl;
}
