#include "stdio.h"

int main() {
    int size;
    printf("Please enter the length of the squares: ");
    scanf("%d", &size);
    drawSquare(size);
    return 0;
}

void drawSquare(size) {
    if (size == 1) {
        drawBorder(size);
    } else { 
        drawBorder(size);
        for (int i = 2; i < size; i++) {
            drawBody(size);
        }
        drawBorder(size);
    }
}

void drawBorder(size) {
    for (int i = 0; i < size; i++) {
        printf("* ");
    }
    printf("\n");
}

void drawBody(size) {
    printf("* ");
    for (int i = 2; i < size; i++) {
        printf("  ");
    }
    printf("*\n");
}