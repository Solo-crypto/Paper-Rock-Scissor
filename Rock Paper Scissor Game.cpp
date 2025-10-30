#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int rule(char p, char c) {
    if (p != 'r' && p != 'p' && p != 's') {
        return 2;
    }

    if (p == c) return 0;
    if (p == 'r' && c == 'p') return -1;
    if (p == 's' && c == 'p') return 1;
    if (p == 'p' && c == 'r') return 1;
    if (p == 's' && c == 'r') return -1;
    if (p == 'r' && c == 's') return 1;
    if (p == 'p' && c == 's') return -1;

    return 0;
}

int main() {

    char computer;
    char player;
    char playmore;

    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;

    cout << "     Welcome to Rock, Paper and Scissors Game" << endl;

    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;

    cout << "Note: " << endl;
    cout << "  r - Rock" << endl;
    cout << "  p - Paper" << endl;
    cout << "  s - Scissor" << endl << endl;

    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;

    do {
        int number = 0;
        srand(time(0));
        number = rand() % 100;
        if (number < 33)
        {
            computer = 'r';
        }
        else if (number > 66)
        {
            computer = 's';
        }
        else
        {
            computer = 'p';
        }

        cout << "Enter your choice: ";
        cin >> player;
        int result = rule(player, computer);

        if (result == 2) {
            cout << "Invalid choice! Please enter 'r', 'p', or 's'." << endl;
        }
        else if (result == 1) {
            cout << "You won!" << endl;
        }
        else if (result == -1) {
            cout << "You lose!" << endl;
        }
        else if (result == 0) {
            cout << "That's a Tie!" << endl;
        }

        cout << "Do you want to Play Again?" << endl;
        cout << "Press 'q' + Enter to continue or 'n' + Enter to exit: ";
        cin >> playmore;

        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;
    } while (playmore != 'n');

    return 0;
}
