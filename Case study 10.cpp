#include <iostream>
using namespace std;

const int CANDIDATES = 4;
const int STATIONS = 6;

void inputVotes(int votes[CANDIDATES][STATIONS]) {
    for (int i = 0; i < CANDIDATES; i++) {
        cout << "Enter votes for Candidate " << i + 1 << " from each station:\n";
        for (int j = 0; j < STATIONS; j++) {
            do {
                cout << "  Station " << j + 1 << ": ";
                cin >> votes[i][j];
                if (votes[i][j] < 0)
                    cout << "    Invalid. Votes cannot be negative.\n";
            } while (votes[i][j] < 0);
        }
    }
}

void totalVotesPerCandidate(int votes[CANDIDATES][STATIONS], int totals[CANDIDATES]) {
    for (int i = 0; i < CANDIDATES; i++) {
        totals[i] = 0;
        for (int j = 0; j < STATIONS; j++) {
            totals[i] += votes[i][j];
        }
    }
}

void totalVotesPerStation(int votes[CANDIDATES][STATIONS], int totals[STATIONS]) {
    for (int j = 0; j < STATIONS; j++) {
        totals[j] = 0;
        for (int i = 0; i < CANDIDATES; i++) {
            totals[j] += votes[i][j];
        }
    }
}

void findWinners(int totals[CANDIDATES], bool winners[CANDIDATES]) {
    int maxVotes = totals[0];
    for (int i = 1; i < CANDIDATES; i++) {
        if (totals[i] > maxVotes)
            maxVotes = totals[i];
    }
    for (int i = 0; i < CANDIDATES; i++) {
        winners[i] = (totals[i] == maxVotes);
    }
}

void displayResults(int totalsCandidates[CANDIDATES], int totalsStations[STATIONS], bool winners[CANDIDATES], int votes[CANDIDATES][STATIONS]) {
    cout << "\nTotal votes per Candidate:\n";
    for (int i = 0; i < CANDIDATES; i++) {
        cout << "Candidate " << i + 1 << ": " << totalsCandidates[i] << endl;
    }

    cout << "\nTotal votes per Polling Station:\n";
    for (int j = 0; j < STATIONS; j++) {
        cout << "Station " << j + 1 << ": " << totalsStations[j] << endl;
    }

    cout << "\nWinner(s):\n";
    for (int i = 0; i < CANDIDATES; i++) {
        if (winners[i]) {
            cout << "Candidate " << i + 1 << endl;
        }
    }

    cout << "\nStations with voter turnout less than 100:\n";
    bool anyLowTurnout = false;
    for (int j = 0; j < STATIONS; j++) {
        if (totalsStations[j] < 100) {
            cout << "Station " << j + 1 << " (Turnout: " << totalsStations[j] << ")\n";
            anyLowTurnout = true;
        }
    }
    if (!anyLowTurnout) {
        cout << "None\n";
    }
}

int main() {
    int votes[CANDIDATES][STATIONS];
    int totalsCandidates[CANDIDATES];
    int totalsStations[STATIONS];
    bool winners[CANDIDATES];

    inputVotes(votes);
    totalVotesPerCandidate(votes, totalsCandidates);
    totalVotesPerStation(votes, totalsStations);
    findWinners(totalsCandidates, winners);
    displayResults(totalsCandidates, totalsStations, winners, votes);

    return 0;
}
