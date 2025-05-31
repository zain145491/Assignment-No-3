#include <iostream>
using namespace std;

const int TEAMS = 6;
const int ROUNDS = 4;

void inputScores(int scores[TEAMS][ROUNDS]) {
    for (int i = 0; i < TEAMS; i++) {
        cout << "Enter scores for Team " << i + 1 << " in 4 rounds:\n";
        for (int j = 0; j < ROUNDS; j++) {
            cout << "  Round " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
}

void calculateTotalScores(int scores[TEAMS][ROUNDS], int total[TEAMS]) {
    for (int i = 0; i < TEAMS; i++) {
        total[i] = 0;
        for (int j = 0; j < ROUNDS; j++) {
            total[i] += scores[i][j];
        }
    }
}

void findWinnerAndRunner(int total[TEAMS], int& winner, int& runner) {
    winner = runner = -1;
    int first = -1, second = -1;

    for (int i = 0; i < TEAMS; i++) {
        if (total[i] > first) {
            second = first;
            runner = winner;
            first = total[i];
            winner = i;
        }
        else if (total[i] > second) {
            second = total[i];
            runner = i;
        }
    }
}

void findLowScoringTeams(int scores[TEAMS][ROUNDS], bool flagged[TEAMS]) {
    for (int i = 0; i < TEAMS; i++) {
        flagged[i] = false;
        for (int j = 0; j < ROUNDS; j++) {
            if (scores[i][j] <= 10) {
                flagged[i] = true;
                break;
            }
        }
    }
}

void displayResults(int total[TEAMS], int winner, int runner, bool flagged[TEAMS]) {
    cout << "\nTotal Scores:\n";
    for (int i = 0; i < TEAMS; i++) {
        cout << "Team " << i + 1 << ": " << total[i] << endl;
    }

    cout << "\nWinner: Team " << winner + 1 << " with " << total[winner] << " points.\n";
    cout << "Runner-up: Team " << runner + 1 << " with " << total[runner] << " points.\n";

    cout << "\nTeams that scored 10 or less in any round:\n";
    bool found = false;
    for (int i = 0; i < TEAMS; i++) {
        if (flagged[i]) {
            cout << "Team " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) cout << "None\n";
}

int main() {
    int scores[TEAMS][ROUNDS];
    int total[TEAMS];
    int winner, runner;
    bool lowScoring[TEAMS];

    inputScores(scores);
    calculateTotalScores(scores, total);
    findWinnerAndRunner(total, winner, runner);
    findLowScoringTeams(scores, lowScoring);
    displayResults(total, winner, runner, lowScoring);

    return 0;
}
