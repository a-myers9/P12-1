// LeavingOnAJetPlan.cpp - Anna Myers - November 15, 2026
// Description: The Bombardier CRJ200 was designed to provide superior performance and operating efficiencies in airline industry.
// The CRJ 200 hasa total of 50 seats, with 12 rows of 4 seats (with an aisle between seats B and C)
// plus a thirteenth row with two seats at the rear of the plane.
// This program uses a two dimensional array that allows someone to reserve seats on a CRJ 200. 
// NOTE: the program must properly detect and handle cases where sweats are already reserved or are non-existent

#include <iostream>
#include <string>

using namespace std;

// Global Constant Declarations
const int ROWS = 13; // rows in plane
const int COLS = 4; // seats per row (A-D)
const int ERROR = -1; // returned for an invalid row/seat
const int TOTAL_SEATS = 50; // 12 x 4 seats + 2 seas in row 13

// Column indices into seats [col][row]
const int COL_A = 0;
const int COL_B = 1;
const int COL_C = 2;
const int COL_D = 3;

// Seat Letters
const char SEAT_A = 'A';
const char SEAT_B = 'B';
const char SEAT_C = 'C';
const char SEAT_D = 'D';

const int LAST_ROW = ROWS - 1;   // index of the rear row (only has seats A and B)
const char TAKEN = 'X';          // marks a reserved seat
const char NO_SEAT = ' ';        // marks a seat that does not exist 
const string QUIT = "Q";

// Lines printed between the C and B seat rows
const string TENS_LINE = "                  1 1 1 1";
const string ONES_LINE = "1 2 3 4 5 6 7 8 9 0 1 2 3";

// Messages for user
const string MSG_NO_SEAT = "Sorry, no such seat exists on the CRJ 200.";
const string MSG_OCCUPIED = "Sorry, that seat is already occupied.";
const string MSG_FULL = "The plane is full.";
const string PROMPT = "Enter a seat or Q to quit: ";

// Function Prototypes
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);
void displaySeats(char seats[][ROWS]);
void initSeats(char seats[][ROWS]);

int main() {
	// Define variables, string, and characters
	char seats[COLS][ROWS];
	string request;
	int reserved = 0;

	initSeats(seats);
	displaySeats(seats);

	while (reserved < TOTAL_SEATS) {
		cout << endl;
		cout << PROMPT;
		cin >> request;
		cout << endl;

		if (request == QUIT) 
			break;
		

		// Input is assumed well formed
		// Row Number followed by one seat letter
		int rowNum = stoi(request.substr(0, request.size() - 1));
		char seatLetter = request[request.size() - 1];

		int row = findRowIndex(rowNum);
		int col = findSeatIndex(seatLetter);

		// Error Messages
		if (row == ERROR || col == ERROR || seats[col][row] == NO_SEAT) {
			cout << MSG_NO_SEAT << endl;
			cout << endl;
		}
		else if (seats[col][row] == TAKEN) {
			cout << MSG_OCCUPIED << endl;
			cout << endl;
		}
		else {
			seats[col][row] = TAKEN;
			reserved++;
		}
		displaySeats(seats);
	}

	if (reserved == TOTAL_SEATS) {
		cout << MSG_FULL << endl;
		cout << endl;
	}

	return 0;
}

// initSeats: Fills the chart with seat letters
// Note: row 13 has no C or D
void initSeats(char seats[][ROWS]) {
	for (int r = 0; r < ROWS; r++) {
		seats[COL_A][r] = SEAT_A;
		seats[COL_B][r] = SEAT_B;
		seats[COL_C][r] = SEAT_C;
		seats[COL_D][r] = SEAT_D;
	}
	seats[COL_C][LAST_ROW] = NO_SEAT;
	seats[COL_D][LAST_ROW] = NO_SEAT;
}

// findRowIndex: given user input, returns appropriate row index into arrays
// @param thisRow - integer indicating row selected by the user
// @return appropriate index into 2-D array if the specified row is valid, ERROR otherwise
int findRowIndex(int thisRow) {
	if (thisRow >= 1 && thisRow <= ROWS) 
		return thisRow - 1;
	return ERROR;
}

// findSeatIndex: given user input, returns appropriate column index into seating array
// @param thisSeat - character indicating selected seat within row
// @return appropriate index into 2-D array if the specified seat is valid, ERROR otherwise
int findSeatIndex(char thisSeat) {
	if (thisSeat == SEAT_A) 
		return COL_A;
	if (thisSeat == SEAT_B) 
		return COL_B;
	if (thisSeat == SEAT_C) 
		return COL_C;
	if (thisSeat == SEAT_D) 
		return COL_D;
	return ERROR;
}

// dislaySeatColumn: prints one col of seats on one line
// @param seats - reference to a 2-D character array in the form of [col][row]
// @param column - which column of seats to display
void displaySeatColumn(char seats[][ROWS], int column) {
	for (int r = 0; r < ROWS; r++) {
		cout << seats[column][r] << ' ';
	} 
	cout << endl;
}

// displaySeats: prints the whole chart, D at the top down to A at the bottom
void displaySeats(char seats[][ROWS]) {
	displaySeatColumn(seats, COL_D);
	displaySeatColumn(seats, COL_C);
	cout << endl;
	cout << TENS_LINE << endl;
	cout << ONES_LINE << endl;
	cout << endl;
	displaySeatColumn(seats, COL_B);
	displaySeatColumn(seats, COL_A);
}
