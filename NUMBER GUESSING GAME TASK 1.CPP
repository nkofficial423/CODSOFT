#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // Seed the random number generator with the current time.
  srand(time(NULL));

  // Generate a random number between 1 and 100.
  int random_number = rand() % 100 + 1;

  // Ask the user to guess the number.
  int guess;
  do {
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    // Check if the guess is correct.
    if (guess == random_number) {
      cout << "Congratulations! You guessed the correct number." << endl;
      break;
    } else if (guess < random_number) {
      cout << "Your guess is too low." << endl;
    } else {
      cout << "Your guess is too high." << endl;
    }
  } while (true);

  return 0;
}
