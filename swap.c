#include "stdio.h";

void swap(int *d1, int *d2);
void passByPointer(int *value);

int main() {
    int data1 = 10;
    int data2 = 20;

    printf("Before swaping, data1 = %d & data2 = %d\n", data1, data2);
    swap(&data1, &data2); // passing by reference
    printf("After swaping, data1 = %d & data2 = %d\n", data1, data2);

    int *p;
    p = &data2;
    passByPointer(p); // pass by pointer
    printf("data2 becomes %d", data2);
    return 0;
}

void swap(int *d1, int *d2) {

    int tempo;
    tempo = *d1;
    *d1 = *d2;
    *d2 = tempo;
}

void passByPointer(int *value) {
    (*value)++;
}