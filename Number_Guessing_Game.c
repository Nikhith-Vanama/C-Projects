#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;
    const int MAX_ATTEMPTS = 3;

    // Initialize random number generator
    srand(time(0));
    secret = rand() % 100 + 1; // Random number between 1 and 100

    printf("🎯 Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secret) {
            printf("🎉 Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (guess < secret) {
            printf("📉 Too low! Try again.\n");
        } else {
            printf("📈 Too high! Try again.\n");
        }

        printf("Attempts left: %d\n\n", MAX_ATTEMPTS - attempts);
    }

    if (guess != secret) {
        printf("❌ Sorry! You’ve used all your attempts. The number was: %d\n", secret);
    }

    return 0;
}
