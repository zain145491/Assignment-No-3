#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 4;

void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = 'E';
}

void displaySeats(char seats[ROWS][COLS]) {
    cout << "\nFlight Seat Layout:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void bookSeat(char seats[ROWS][COLS], int row, int col) {
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid seat selection.\n";
        return;
    }
    if (seats[row - 1][col - 1] == 'B') {
        cout << "Seat already booked!\n";
    }
    else {
        seats[row - 1][col - 1] = 'B';
        cout << "Seat successfully booked.\n";
    }
}

int countAvailableSeats(char seats[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == 'E')
                count++;
    return count;
}

int findRowWithMaxEmpty(char seats[ROWS][COLS]) {
    int maxEmpty = -1, rowIndex = -1;
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == 'E') count++;
        if (count > maxEmpty) {
            maxEmpty = count;
            rowIndex = i;
        }
    }
    return rowIndex;  // returns 0-based row index
}

int main() {
    char seats[ROWS][COLS];
    initializeSeats(seats);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Count Available Seats\n";
        cout << "4. Row with Maximum Empty Seats\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(seats);
            break;
        case 2: {
            int row, col;
            cout << "Enter Row (1-6): ";
            cin >> row;
            cout << "Enter Column (1-4): ";
            cin >> col;
            bookSeat(seats, row, col);
            break;
        }
        case 3:
            cout << "Total available seats: " << countAvailableSeats(seats) << endl;
            break;
        case 4: {
            int row = findRowWithMaxEmpty(seats);
            cout << "Row " << row + 1 << " has the most empty seats.\n";
            break;
        }
        case 5:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
