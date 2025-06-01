#include <iostream>
using namespace std;

const int SHIFTS = 3;
const int DAYS = 7;

void inputDefects(float defects[SHIFTS][DAYS]) {
    for (int i = 0; i < SHIFTS; i++) {
        cout << "Enter defect percentages for Shift " << i + 1 << " (7 days):\n";
        for (int j = 0; j < DAYS; j++) {
            do {
                cout << "  Day " << j + 1 << ": ";
                cin >> defects[i][j];
                if (defects[i][j] < 0.0f || defects[i][j] > 100.0f)
                    cout << "    Invalid input. Enter a value between 0 and 100.\n";
            } while (defects[i][j] < 0.0f || defects[i][j] > 100.0f);
        }
    }
}

void averagePerShift(float defects[SHIFTS][DAYS], float avgShift[SHIFTS]) {
    for (int i = 0; i < SHIFTS; i++) {
        float sum = 0;
        for (int j = 0; j < DAYS; j++) {
            sum += defects[i][j];
        }
        avgShift[i] = sum / DAYS;
    }
}

void averagePerDay(float defects[SHIFTS][DAYS], float avgDay[DAYS]) {
    for (int j = 0; j < DAYS; j++) {
        float sum = 0;
        for (int i = 0; i < SHIFTS; i++) {
            sum += defects[i][j];
        }
        avgDay[j] = sum / SHIFTS;
    }
}

void identifyCriticalShifts(float avgShift[SHIFTS], bool critical[SHIFTS]) {
    for (int i = 0; i < SHIFTS; i++) {
        critical[i] = (avgShift[i] > 10.0f);
    }
}

void displayResults(float avgShift[SHIFTS], float avgDay[DAYS], bool critical[SHIFTS]) {
    cout << "\nAverage Defect Percentage per Shift:\n";
    for (int i = 0; i < SHIFTS; i++) {
        cout << "Shift " << i + 1 << ": " << avgShift[i] << "%";
        if (critical[i]) cout << " (CRITICAL)";
        cout << endl;
    }

    cout << "\nAverage Defect Percentage per Day:\n";
    for (int j = 0; j < DAYS; j++) {
        cout << "Day " << j + 1 << ": " << avgDay[j] << "%\n";
    }
}

int main() {
    float defects[SHIFTS][DAYS];
    float avgShift[SHIFTS];
    float avgDay[DAYS];
    bool critical[SHIFTS];

    inputDefects(defects);
    averagePerShift(defects, avgShift);
    averagePerDay(defects, avgDay);
    identifyCriticalShifts(avgShift, critical);
    displayResults(avgShift, avgDay, critical);

    return 0;
}
