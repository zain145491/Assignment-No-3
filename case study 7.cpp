#include <iostream>
using namespace std;

const int USERS = 10;
const int PRODUCTS = 5;

void inputRatings(int ratings[USERS][PRODUCTS]) {
    for (int i = 0; i < USERS; i++) {
        cout << "Enter ratings (1-5) for User " << i + 1 << ":\n";
        for (int j = 0; j < PRODUCTS; j++) {
            do {
                cout << "  Product " << j + 1 << ": ";
                cin >> ratings[i][j];
                if (ratings[i][j] < 1 || ratings[i][j] > 5)
                    cout << "    Invalid. Enter a number between 1 and 5.\n";
            } while (ratings[i][j] < 1 || ratings[i][j] > 5);
        }
    }
}

void calculateAverages(int ratings[USERS][PRODUCTS], float avg[PRODUCTS]) {
    for (int j = 0; j < PRODUCTS; j++) {
        int sum = 0;
        for (int i = 0; i < USERS; i++) {
            sum += ratings[i][j];
        }
        avg[j] = static_cast<float>(sum) / USERS;
    }
}

void countPerfectRatings(int ratings[USERS][PRODUCTS], int perfect[PRODUCTS]) {
    for (int j = 0; j < PRODUCTS; j++) {
        perfect[j] = 0;
        for (int i = 0; i < USERS; i++) {
            if (ratings[i][j] == 5)
                perfect[j]++;
        }
    }
}

void findWorstProducts(float avg[PRODUCTS], bool worst[PRODUCTS]) {
    float minAvg = avg[0];
    for (int i = 1; i < PRODUCTS; i++) {
        if (avg[i] < minAvg)
            minAvg = avg[i];
    }
    for (int i = 0; i < PRODUCTS; i++) {
        worst[i] = (avg[i] == minAvg);
    }
}

void displayResults(float avg[PRODUCTS], int perfect[PRODUCTS], bool worst[PRODUCTS]) {
    cout << "\nAverage Ratings per Product:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "Product " << i + 1 << ": " << avg[i] << endl;
    }

    cout << "\nPerfect 5-Star Ratings per Product:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "Product " << i + 1 << ": " << perfect[i] << " user(s)\n";
    }

    cout << "\nProduct(s) with Worst Average Rating:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        if (worst[i])
            cout << "Product " << i + 1 << endl;
    }
}

int main() {
    int ratings[USERS][PRODUCTS];
    float avg[PRODUCTS];
    int perfect[PRODUCTS];
    bool worst[PRODUCTS];

    inputRatings(ratings);
    calculateAverages(ratings, avg);
    countPerfectRatings(ratings, perfect);
    findWorstProducts(avg, worst);
    displayResults(avg, perfect, worst);

    return 0;
}
