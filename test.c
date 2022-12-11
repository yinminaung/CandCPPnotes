#include "stdio.h";

int main() {
    int true = 1;
    int false = 0;
    int i = 2;
    if (1) {
        int i = 10;
    }
    int *fptr = false;
    printf("%d", &fptr);
    if(fptr == false) {
        printf("Hi");
    }
    if (!fptr) {
        printf("hi");
    }
    if (1==1) {
        printf("It will run!");
    }
    if (false) {
        printf("It won't run!");
    }
    if (true) {
        printf("hello");
    }
    printf("%d", i);
    return 0;
}