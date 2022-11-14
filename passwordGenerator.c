#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void passwordGenerator();

int main() {
    srand(time(NULL));
    printf("Printing 5 random passwords....\n");
    for (int i = 0; i < 5; i++) {
        passwordGenerator();
    }
    return 0;
}

void passwordGenerator() {
    // password size is 8
    // each characters in the password with be from ASCII 48 to 122
    int passArray[8] =  {0, 0, 0, 0, 0, 0, 0, 0};


    for (int i = 0; i < 8; i++) {
        int randNumber = rand() % 75;
        passArray[i] = randNumber + 48;

    }
    printf("Your passowrd is ");
    for (int i = 0; i < 8; i++) {
        printf("%c", passArray[i]);
    }
    printf("\n");
}