#include "stdio.h";

int main() {
    // writing from 1 to 100 
    FILE *fptr;
    fptr = fopen("output.txt", "w");
    int i;
    for (i = 1; i <= 100; i++) {
        fprintf(fptr, "%d\n", i);
    }
    fclose(fptr);

    // reading the file and store the values in the array
    int intArray[100];
    int index = 0; // to track the array's index;
    fptr = fopen("output.txt", "r");
    char line[5];
    if (fptr == NULL) {
        printf("File not found!");
        return 0;
    }

    while (fgets(line, 5, fptr)) { 
        // line is the array of characters, we need to change to the integers back
        // first we need to know how many digits are there
        int digits = 0;
        while (line[digits] != '\n') {
            digits++;
        }  // here, we know the number of digits

        // let's calculate the integer from the array of char
        // ['1', '2', '3'] -> 1 * 100 + 2 * 10 + 3
        int answer = 0; // the final integer
        for (int i = 0; i < digits; i++) {
            answer = answer * 10 + ((int)line[i] - 48); // '1' -> 49 in ASCII code, so I subtract 48 before computing the answer
        }
        // here we change the array of chars to the integer and store in the answer

        // storing the answer in the array
        intArray[index] = answer;
        index++;
    }


    // printing the array in the console;
    printf("[");
    for (int i = 0; i < 100; i++) {
        if (i == 99) {
            printf("%d", intArray[i]); // removing the last comma in the list
        } else {
            printf("%d, ", intArray[i]);
        }
    }
    printf("]\n");

    // closing the file 
    fclose(fptr);
    return 0;
}