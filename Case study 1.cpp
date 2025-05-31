#include <iostream>
using namespace std;

const int STUDENTS = 10;
const int SUBJECTS = 5;

void inputMarks(int marks[STUDENTS][SUBJECTS]) {
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Enter marks for Student " << i + 1 << ":\n";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
}

void calculateTotalsAndAverages(int marks[STUDENTS][SUBJECTS], int totals[], float averages[]) {
    for (int i = 0; i < STUDENTS; i++) {
        totals[i] = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            totals[i] += marks[i][j];
        }
        averages[i] = (float)totals[i] / SUBJECTS;
    }
}

int findTopScorer(int totals[]) {
    int topIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (totals[i] > totals[topIndex]) {
            topIndex = i;
        }
    }
    return topIndex;
}

char getGrade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 75) return 'B';
    else if (average >= 50) return 'C';
    else return 'F';
}

void displayResults(int totals[], float averages[]) {
    cout << "\nStudent\tTotal\tAverage\tGrade\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << i + 1 << "\t" << totals[i] << "\t" << averages[i] << "\t" << getGrade(averages[i]) << "\n";
    }
}

int main() {
    int marks[STUDENTS][SUBJECTS];
    int totals[STUDENTS];
    float averages[STUDENTS];

    inputMarks(marks);
    calculateTotalsAndAverages(marks, totals, averages);
    int topScorer = findTopScorer(totals);
    displayResults(totals, averages);

    cout << "\nTop Scorer: Student " << topScorer + 1
        << " with total marks " << totals[topScorer]
        << " and average " << averages[topScorer] << endl;

    return 0;
}
