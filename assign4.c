#include "stdio.h"
#include "stdlib.h"



int search(char word[], int fullScore);
void main() {
    char myWord[] = {'w', 'i', 'n', 'h', 't', 'u', 't'};
    char myWord2[] = {'N', 'a', 't', 'i', 'o', 'n', 'a', 'l', 'C', 'y', 'b', 'e', 'r', 'C', 'i', 't', 'y'};

    printf("The text file contains %d \"winhtut\" word.\n", search(myWord, 7));
    printf("The text file contains %d \"NationalCyberCity\" word.\n", search (myWord2, 17));
}

int search(char word[], int fullScore) {
    FILE *fptr;
    fptr = fopen("text.txt", "r");
    char c;
    int index = 0;
    int score = 0;
    // score must be 7. If the word has all 7 same charaters, this work get score 7. 
    int sameWordCount = 0;

    if (fptr == NULL) {
        printf("Unable to open the file.\n");
        exit(0);
    } 
    do {
        c = fgetc(fptr);
        if (c == word[index]) {
            score++;
            index++;
        } else {
            index = 0;
            score = 0;
        }

        if (score == fullScore) {
            sameWordCount++;
        }
    } while (c != EOF);

    fclose(fptr); // close file 
    return sameWordCount;
}

