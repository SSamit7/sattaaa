#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for randomness

int rules();
int round1(int deposit);

int main() {
    rules();
    printf("\n");

    int deposit;
    printf("Enter your deposit amount: $");
    scanf("%d", &deposit);
    if (deposit <= 0) {
        printf("Invalid deposit amount. Exiting the game.\n");
        return 0;
    }

    printf("Your starting balance is $%d\n", deposit);
    round1(deposit);

    return 0;
}

int rules() {
    printf("----------------------------------------------------------------------\n");
    printf("  Rules of the game: \n");
    printf("----------------------------------------------------------------------\n");
    printf("1. Choose a number between 1 and 10. \n");
    printf("2. If you win, you will get 10X your betting amount. \n");
    printf("3. If you bet on the wrong number, you lose your betting amount. \n");
    printf("----------------------------------------------------------------------\n");
}

int round1(int deposit) {
    char name[55];
    int bet1, guess1, computer1, new_balance;

    printf("Enter your name: ");
    scanf("%s", name);

    while (deposit > 0) {
        printf("\nYour current balance is $%d\n", deposit);
        printf("Enter your bet amount: $");
        scanf("%d", &bet1);

        if (bet1 > deposit) {
            printf("Insufficient funds. Please enter a valid bet: $");
            scanf("%d", &bet1);
        }

        srand(time(NULL)); // Seed for random number generator
        computer1 = rand() % 10 + 1; // Random number between 1 and 10

        printf("Enter your guess (1 to 10): ");
        scanf("%d", &guess1);
        printf("\n");

        if (guess1 < 1 || guess1 > 10) {
            printf("Invalid guess! The number should be between 1 and 10. Exiting the game.\n");
            return 0;
        }

        if (guess1 == computer1) {
            printf("Congratulations, you won $%d!\n", bet1 * 10);
            new_balance = deposit + bet1 * 10; // Add winnings to the balance
        } else {
            printf("You lost $%d! The correct number was %d.\n", bet1, computer1);
            new_balance = deposit - bet1; // Deduct loss from the balance
        }

        printf("Your new balance is $%d\n", new_balance);

        if (new_balance <= 0) {
            printf("Game Over. You have no money left.\n");
            // Ask if they want to play again with a new deposit
            int decision;
            printf("Do you want to play again?\n");
            printf("Press 1 to play again with a new deposit, or 2 to exit: ");
            scanf("%d", &decision);

            if (decision == 1) {
                // Ask for a new deposit if they choose to play again
                printf("\nEnter a new deposit amount: $");
                scanf("%d", &deposit);
                if (deposit <= 0) {
                    printf("Invalid deposit amount. Exiting the game.\n");
                    return 0;
                }
                printf("Your new balance is $%d\n", deposit);
                round1(deposit);  // Restart the round with the new deposit
                return 0;
            } else {
                printf("Thank you for playing! Have a great day.\n");
                return 0;
            }
        }

        deposit = new_balance; // Update deposit with the new balance

        int decision;
        printf("Do you want to play again?\n");
        printf("Press 1 to play again, or 2 to exit: ");
        scanf("%d", &decision);

        if (decision == 2) {
            printf("Thank you for playing! Have a great day.\n");
            return 0;
        }
    }

    return 0;
}

