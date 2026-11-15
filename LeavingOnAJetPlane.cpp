// LeavingOnAJetPlan.cpp - Anna Myers - November 15, 2026
// Description: The Bombardier CRJ200 was designed to provide superior performance and operating efficiencies in airline industry.
// The CRJ 200 hasa total of 50 seats, with 12 rows of 4 seats (with an aisle between seats B and C)
// plus a thirteenth row with two seats at the rear of the plane.
// This program uses a two dimensional array that allows someone to reserve seats on a CRJ 200. 
// NOTE: the program must properly detect and handle cases where sweats are already reserved or are non-existent

#include <iostream>
#include <string>

using namespace std;

const int ROWS = 13; // rows in plane
const int COLS = 4; // seats per row (A-D)
const int ERROR = -1; // returned for an invalid row/seat
const int TOTAL_SEATS = 50; // 12 x 4 seats + 2 seas in row 13

// Column indices into seats [col][row]
const int COL_A = 0;
const int COL_B = 1;
const int COL_C = 2;
const int COL_D = 3;

const int FIRST_ROW_NUM = 1; // row numbers the user types start at 1
const int LAST_ROW_INDEX = ROWS - 1; // the rear row (only has Seats a and b)

const char FIRST_SEAT = 'A';
const char LAST_SEAT = 'D';
const char TAKEN = 'X'; // marks a reserved seat
const char NO_SEAT = ' '; // marksa seat that does not exist
const string QUIT = "Q";

// Lines printed between the C and B seat rows
const string TENS_LINE = "                  1 1 1 1";
const string ONES_LINE = "1 2 3 4 5 6 7 8 9 0 1 2 3";

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
	char seats[COLS][ROWS]; 
	string request;
	int reserved = 0;

	initSeats(seats);
	displaySeats(seats);

}