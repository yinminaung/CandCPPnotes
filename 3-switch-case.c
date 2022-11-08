#include "stdio.h"

int main() {
    char letter;
    printf("Plese enter your direction(lrud): ");
    scanf("%c", &letter);
    switch (letter) {
        case 'l':
            printf("Moving left!\n");
            break;
        case 'r':
            printf("Moving right!\n");
            break;
        case 'u':
            printf("Moving up!\n");
            break;
        case 'd':
            printf("Moving down!\n");
            break;
        default:
            printf("I don't know what to do!");
    }
    return 0;
}