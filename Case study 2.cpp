#include <iostream>
using namespace std;

const int ITEMS = 4;
const int DAYS = 7;

void inputSales(float sales[ITEMS][DAYS]) {
    for (int i = 0; i < ITEMS; i++) {
        cout << "Enter sales for Item " << i + 1 << " over 7 days:\n";
        for (int j = 0; j < DAYS; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}

void calculateItemTotals(float sales[ITEMS][DAYS], float itemTotals[]) {
    for (int i = 0; i < ITEMS; i++) {
        itemTotals[i] = 0;
        for (int j = 0; j < DAYS; j++) {
            itemTotals[i] += sales[i][j];
        }
    }
}

void calculateDayTotals(float sales[ITEMS][DAYS], float dayTotals[]) {
    for (int j = 0; j < DAYS; j++) {
        dayTotals[j] = 0;
        for (int i = 0; i < ITEMS; i++) {
            dayTotals[j] += sales[i][j];
        }
    }
}

int findMaxIndex(float array[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void displayResults(float itemTotals[], float dayTotals[]) {
    cout << "\nTotal Sales per Item:\n";
    for (int i = 0; i < ITEMS; i++) {
        cout << "Item " << i + 1 << ": " << itemTotals[i] << endl;
    }

    cout << "\nTotal Sales per Day:\n";
    for (int j = 0; j < DAYS; j++) {
        cout << "Day " << j + 1 << ": " << dayTotals[j] << endl;
    }

    int bestDay = findMaxIndex(dayTotals, DAYS);
    int bestItem = findMaxIndex(itemTotals, ITEMS);

    cout << "\nDay with highest total sales: Day " << bestDay + 1 << " (Sales: " << dayTotals[bestDay] << ")\n";
    cout << "Item with highest total sales: Item " << bestItem + 1 << " (Sales: " << itemTotals[bestItem] << ")\n";
}

int main() {
    float sales[ITEMS][DAYS];
    float itemTotals[ITEMS];
    float dayTotals[DAYS];

    inputSales(sales);
    calculateItemTotals(sales, itemTotals);
    calculateDayTotals(sales, dayTotals);
    displayResults(itemTotals, dayTotals);

    return 0;
}
