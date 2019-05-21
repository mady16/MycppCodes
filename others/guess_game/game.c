#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 10
#define X 10
#define true 1
#define false 0

void readGuess(int answer[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &answer[i]);
    }
}

int isGuessCorrect(int answer[], int guess[], int size) {
    for (int i = 0; i < size; i++) {
        if (answer[i] != guess[i]) {
            return false;
        }
    }
    return true;
}

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

void countCorrectValues(int answer[], int guess[], int usedDigits[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (usedDigits[guess[i]]) {
            count++;
        }
    }

    printf("%d values correct.\n", count);
}

void countCorrectPositions(int answer[], int guess[], int size){
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (answer[i] == guess[i]) {
            count++;
        }
    }

    printf("%d positions correct.\n", count);
}

int main() {
    assert(N <= M);
    srand(time(NULL));

    int usedDigits[M] = {false};
    int answer[N];
    int previous_guess[10][N];

    generateCode(answer, usedDigits, N);

    printf("\tEnter your first guess: ");

    int attempt = 0;
    while (1) {
        readGuess(previous_guess[attempt], N);
        printf("================= Output ===================\n");
        if (isGuessCorrect(answer, previous_guess[attempt], N)) {
            printf("You Won!!!\n");
            break;
        } else {
            countCorrectValues(answer, previous_guess[attempt], usedDigits, N);
            countCorrectPositions(answer, previous_guess[attempt], N);
            attempt++;
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