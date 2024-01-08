#include <iostream>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNum = rand() % 100 + 1;
    int usernum;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> usernum;
        attempts++;

        if (usernum < secretNum) {
            cout << "Too low! Try again.\n";
        } else if (usernum > secretNum) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }

    } while (usernum != secretNum);

    return 0;
}
