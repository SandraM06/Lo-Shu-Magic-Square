#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 3

void printSquare(int square [SIZE] [SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf( "[%d]", square[i][j]);
        }
        printf("\n");
    }

}

bool isMagicSquare(int square[SIZE][SIZE]){
    int sum = 0;

    //calculates sum of first row
    for(int j = 0; j < SIZE; j++) {
        sum += square[0][j];
    }

    //check rows
    for (int i = 1; i < SIZE; i++){
        int rowSum = 0;
        for (int j = 0; j< SIZE; j++){
            rowSum += square[i][j];
        }
        if (rowSum != sum) return false;
    }

    //check columns
    for(int j = 0; j < SIZE; j++) {
        int colSum = 0;
        for (int i = 0; i < SIZE; i++){
         colSum += square[i][j];
        }
        if (colSum != sum) return false;
    }

    //check diagonal
    int diag1Sum = 0;
    int diag2Sum = 0;
    for (int i = 0; i < SIZE; i++) {
        diag1Sum += square[i][i];
        diag2Sum += square[i][SIZE - i - 1];
    }

    return diag1Sum == sum && diag2Sum == sum;
}

void generateRandomSquare(int square[SIZE][SIZE]) {
    int numbers[SIZE*SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = SIZE*SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            square[i][j] = numbers[index++];
        }
    }
}

int main(){
    int square[SIZE][SIZE];
    int count = 0;

    do {
        generateRandomSquare(square);
        count++;
    } while (!isMagicSquare(square));

    printf("Total squares generated before success: %d\n", count);
    printf("The Lo Shu Magic Square:\n");
    printSquare(square);

    return 0;

}


