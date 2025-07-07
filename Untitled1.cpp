#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

void suspensePrint(string message, int delay = 50) {
    for (char ch : message) {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

int getValidGuess() {
    int guess;
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a number! Try again." << endl;
        } else {
            return guess;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int MAX_LIVES = 7;
    int secret = rand() % 100 + 1; // random number between 1 and 100
    int lives = MAX_LIVES;
    int guess;
    int rangeShrink = 10;

    suspensePrint("Welcome to the Mystery Number Challenge!", 40);
    suspensePrint("A number between 1 and 100 has been chosen...", 40);
    suspensePrint("You have " + to_string(MAX_LIVES) + " lives. Use them wisely.\n", 40);

    int minHint = 1;
    int maxHint = 100;

    while (lives > 0) {
        cout << "\nLives left: " << lives << endl;
        cout << "Hint: The number is between " << minHint << " and " << maxHint << "." << endl;

        guess = getValidGuess();

        if (guess == secret) {
            suspensePrint("\n?? Congratulations! You guessed the number! ??", 30);
            break;
        } else if (guess < secret) {
            suspensePrint("Too low! Try something higher.", 20);
            minHint = max(minHint, guess + 1);
        } else {
            suspensePrint("Too high! Try something lower.", 20);
            maxHint = min(maxHint, guess - 1);
        }

        
		
		lives--;
        rangeShrink = max(1, rangeShrink - 1); // make hints narrower
        minHint = max(1, secret - rand() % (rangeShrink * 2));
        maxHint = min(100, secret + rand() % (rangeShrink * 2));
    }

    if (lives == 0 && guess != secret) {
        suspensePrint("\n?? You've run out of lives! The number was " + to_string(secret) + ".", 40);
        suspensePrint("Better luck next time!", 50);
    }

    return 0;
}
