#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void inputStatus(char books[ROWS][COLS]) {
    cout << "Enter book statuses (A = Available, I = Issued, M = Missing):\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Shelf " << i + 1 << ":\n";
        for (int j = 0; j < COLS; j++) {
            do {
                cout << "  Book " << j + 1 << ": ";
                cin >> books[i][j];
                books[i][j] = toupper(books[i][j]);
                if (books[i][j] != 'A' && books[i][j] != 'I' && books[i][j] != 'M') {
                    cout << "    Invalid. Use A, I, or M only.\n";
                }
            } while (books[i][j] != 'A' && books[i][j] != 'I' && books[i][j] != 'M');
        }
    }
}

void displayStatus(char books[ROWS][COLS]) {
    cout << "\nBook Status Grid:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++) {
            cout << books[i][j] << " ";
        }
        cout << endl;
    }
}

void countStatuses(char books[ROWS][COLS], int& available, int& issued, int& missing) {
    available = issued = missing = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (books[i][j] == 'A') available++;
            else if (books[i][j] == 'I') issued++;
            else if (books[i][j] == 'M') missing++;
        }
}

void findShelvesWithMostMissing(char books[ROWS][COLS], bool shelves[ROWS]) {
    int maxMissing = 0;
    int missingCount[ROWS];

    for (int i = 0; i < ROWS; i++) {
        missingCount[i] = 0;
        for (int j = 0; j < COLS; j++) {
            if (books[i][j] == 'M') {
                missingCount[i]++;
            }
        }
        if (missingCount[i] > maxMissing)
            maxMissing = missingCount[i];
    }

    for (int i = 0; i < ROWS; i++) {
        shelves[i] = (missingCount[i] == maxMissing && maxMissing > 0);
    }
}

void displaySummary(int available, int issued, int missing, bool shelves[ROWS]) {
    cout << "\nSummary:\n";
    cout << "Available Books: " << available << endl;
    cout << "Issued Books: " << issued << endl;
    cout << "Missing Books: " << missing << endl;

    cout << "\nShelves with Highest Missing Count:\n";
    bool any = false;
    for (int i = 0; i < ROWS; i++) {
        if (shelves[i]) {
            cout << "Shelf " << i + 1 << endl;
            any = true;
        }
    }
    if (!any) cout << "No missing books.\n";
}

int main() {
    char books[ROWS][COLS];
    int available, issued, missing;
    bool mostMissingShelves[ROWS];

    inputStatus(books);
    displayStatus(books);
    countStatuses(books, available, issued, missing);
    findShelvesWithMostMissing(books, mostMissingShelves);
    displaySummary(available, issued, missing, mostMissingShelves);

    return 0;
}
