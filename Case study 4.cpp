#include <iostream>
using namespace std;

const int SIZE = 5;

void inputTemperatures(float temperature[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter temperatures for Zone " << i + 1 << ":\n";
        for (int j = 0; j < SIZE; j++) {
            cout << "  Location " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }
}

void calculateRowAverages(float temperature[SIZE][SIZE], float averages[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        float sum = 0;
        for (int j = 0; j < SIZE; j++) {
            sum += temperature[i][j];
        }
        averages[i] = sum / SIZE;
    }
}

void findExtremeSpots(float temperature[SIZE][SIZE], float& maxTemp, int& maxRow, int& maxCol,
    float& minTemp, int& minRow, int& minCol) {
    maxTemp = minTemp = temperature[0][0];
    maxRow = minRow = 0;
    maxCol = minCol = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (temperature[i][j] > maxTemp) {
                maxTemp = temperature[i][j];
                maxRow = i;
                maxCol = j;
            }
            if (temperature[i][j] < minTemp) {
                minTemp = temperature[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}

void displayResults(float averages[SIZE], float maxTemp, int maxRow, int maxCol,
    float minTemp, int minRow, int minCol) {
    cout << "\nAverage Temperature per Zone:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Zone " << i + 1 << ": " << averages[i] << endl;
    }

    cout << "\nExtreme Spots:\n";
    cout << "Hottest spot: " << maxTemp << " at Zone " << maxRow + 1 << ", Location " << maxCol + 1 << endl;
    cout << "Coldest spot: " << minTemp << " at Zone " << minRow + 1 << ", Location " << minCol + 1 << endl;
}

int main() {
    float temperature[SIZE][SIZE];
    float averages[SIZE];
    float maxTemp, minTemp;
    int maxRow, maxCol, minRow, minCol;

    inputTemperatures(temperature);
    calculateRowAverages(temperature, averages);
    findExtremeSpots(temperature, maxTemp, maxRow, maxCol, minTemp, minRow, minCol);
    displayResults(averages, maxTemp, maxRow, maxCol, minTemp, minRow, minCol);

    return 0;
}
