#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int rules();
int round1();

int main() {
    rules();
    printf("\n");

    round1();
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

int round1() {
    char name[55];
    int deposit, bet1, guess1, computer1, new_balance;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your deposit amount: $");
    scanf("%d", &deposit);
    printf("\n");

    if (deposit <= 0) {
        printf("Invalid deposit amount. Exiting the game.\n");
        return 0;
    }

    printf("Your current balance is $%d\n", deposit);
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
        new_balance = deposit + bet1 * 10;
    } else {
        printf("You lost $%d! The correct number was %d.\n", bet1, computer1);
        new_balance = deposit - bet1;
    }

    printf("Your new balance is $%d\n", new_balance);

    if (new_balance <= 0) {
        printf("Game Over. You have no money left.\n");
        return 0;
    }

    int decision;
    printf("Do you want to play again?\n");
    printf("Press 1 to play again, or 2 to exit: ");
    scanf("%d", &decision);

    if (decision == 1) {
        printf("\nYou have $%d as a balance.\n", new_balance);
        printf("\nStarting next round...\n\n");
        round1();  // Recursively call round1 for another round of play
    } else {
        printf("Thank you for playing! Have a great day.\n");
    }

    return 0;
}
