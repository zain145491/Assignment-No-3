#include <iostream>
using namespace std;

const int PATIENTS = 5;
const int DAYS = 7;

void inputStatus(char status[PATIENTS][DAYS]) {
    for (int i = 0; i < PATIENTS; i++) {
        cout << "Enter status (S/C/R) for Patient " << i + 1 << " for 7 days:\n";
        for (int j = 0; j < DAYS; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> status[i][j];
            // Validate input
            while (status[i][j] != 'S' && status[i][j] != 'C' && status[i][j] != 'R') {
                cout << "  Invalid input. Enter S, C, or R: ";
                cin >> status[i][j];
            }
        }
    }
}

void countStatusTypes(char status[PATIENTS][DAYS], int& stableCount, int& criticalCount, int& recoveredCount) {
    stableCount = criticalCount = recoveredCount = 0;
    for (int i = 0; i < PATIENTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (status[i][j] == 'S') stableCount++;
            else if (status[i][j] == 'C') criticalCount++;
            else if (status[i][j] == 'R') recoveredCount++;
        }
    }
}

void countCriticalDaysPerPatient(char status[PATIENTS][DAYS], int criticalDays[PATIENTS]) {
    for (int i = 0; i < PATIENTS; i++) {
        criticalDays[i] = 0;
        for (int j = 0; j < DAYS; j++) {
            if (status[i][j] == 'C') criticalDays[i]++;
        }
    }
}

void displayResults(int stableCount, int criticalCount, int recoveredCount, int criticalDays[PATIENTS]) {
    cout << "\nOverall Status Count:\n";
    cout << "Stable: " << stableCount << "\n";
    cout << "Critical: " << criticalCount << "\n";
    cout << "Recovered: " << recoveredCount << "\n";

    cout << "\nNumber of days each patient was in Critical condition:\n";
    for (int i = 0; i < PATIENTS; i++) {
        cout << "Patient " << i + 1 << ": " << criticalDays[i] << " day(s)\n";
    }
}

int main() {
    char status[PATIENTS][DAYS];
    int stable, critical, recovered;
    int criticalDays[PATIENTS];

    inputStatus(status);
    countStatusTypes(status, stable, critical, recovered);
    countCriticalDaysPerPatient(status, criticalDays);
    displayResults(stable, critical, recovered, criticalDays);

    return 0;
}
