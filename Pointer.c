#include "stdio.h";

int main() {
    int intData[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%x\n", intData);
    // The name of the array is actually the memory address of the first item 
    for (int i = 0; i < 10; i++) {
        printf("%x\n", intData + i);
    }
    printf("\n");

    char charData[10] = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i','j'};
    for (int j = 0; j < 10; j++) {
        printf("%x\n", charData + j);
    }
}