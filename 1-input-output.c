#include "stdio.h"

int main() {
    int age = 0;
    char favChar;
    printf("Please enter your age :");
    scanf("%d", &age);
    printf("Please enter the first character of your name: ");
    scanf(" %c", &favChar);
    printf("Your first character is %c and your age is %d", favChar, age);
    return 0;
}