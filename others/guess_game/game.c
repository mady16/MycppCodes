// including required libraries
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defining needed constants
#define N 4
#define M 10
#define X 10
#define true 1
#define false 0

// this function scans the guess from standard input
void readGuess(int answer[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &answer[i]);
    }
}

// this function checks for a guess attempt by user, if thats correct or not
int isGuessCorrect(int answer[], int guess[], int size) {
    for (int i = 0; i < size; i++) {
        if (answer[i] != guess[i]) {
            return false;
        }
    }
    return true;
}

// this function generates the new secret code for game
void generateCode(int answer[], int usedDigits[], int size) {
    int temp;

    for (int i = 0; i < size; i++) {
        temp = rand() % M;
        if (usedDigits[temp]) {
            i--;
            continue;
        }
        answer[i] = temp;
        usedDigits[temp] = true;
        // printf("%d ", answer[i]);
    }
}

// this function count the values which are both in guess and answer 
void countCorrectValues(int answer[], int guess[], int usedDigits[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (usedDigits[guess[i]]) {
            count++;
        }
    }
    printf("%d values correct.\n", count);
}

// this function count the number of correct values which are at correct place in guess
void countCorrectPositions(int answer[], int guess[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (answer[i] == guess[i]) {
            count++;
        }
    }
    printf("%d positions correct.\n", count);
}


// main function
int main() {
    // ensure that N is always less than or equal to M
    assert(N <= M);
    // seed the random with current time
    srand(time(0));

    // store used digits in array
    int usedDigits[M] = {false};
    // store secret code
    int answer[N];
    // store all guesses
    int previous_guess[X][N];

    // generate secret code for game
    generateCode(answer, usedDigits, N);

    printf("\tEnter your first guess: ");

    int attempt = 0;
    // continue till last attempt or correct guess
    while (1) {
        // read the new guess from standard input
        readGuess(previous_guess[attempt], N);
        printf("================= Output ===================\n");
        // check if guess is correct
        if (isGuessCorrect(answer, previous_guess[attempt], N)) {
            printf("You Won!!!\n");
            break;
        } else {
            // count correct values and positions and print counts
            countCorrectValues(answer, previous_guess[attempt], usedDigits, N);
            countCorrectPositions(answer, previous_guess[attempt], N);
            attempt++;
            // check if all are used attempts
            if (attempt == X) {
                printf("You Loss.\n");
                break;
            }

            printf("Wrong answer. %d attempts remaining. \nTry Again.\n\n",
                   X - attempt);
            printf("\tEnter your next guess: ");
        }
    }

    return 0;
}