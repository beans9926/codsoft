#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printCard(){
	system("clear");
	cout << "Welcome to the Guessing Game!" << endl;
	cout << "I've chosen a number between 1 and 100. Can you guess it?" << endl;
	return;
}

int main() {
  // Seed the random number generator
  srand(time(0));

	// Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

	printCard();
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            break;
        } else if (guess < randomNumber) {
            cout << "Too low. Try a higher number.\n" << endl;
        } else {
            cout << "Too high. Try a lower number.\n" << endl;
        }

        // Give a hint if the guess is within 10 of the random number
        if (abs(guess - randomNumber) <= 10) {
            cout << "You're close!\n" << endl;
        }
    } while (true);

    return 0;
}
