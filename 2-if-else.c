#include "stdio.h"

int main() {
    int age = 0;
    int allowedAge = 18;
    printf("please enter your age: ");
    scanf("%d", &age);

    if (age < 18) {
        printf("You cannot go into KTV!\n");
        printf("But don't worry, you can go there in %d years.\n", allowedAge - age);
    } else if (age == 18) {
        printf("The first time of going KTV, isn't it?");
    } else {
        printf("Enjoy in the KTV!\n");
    }
    return 0;
}