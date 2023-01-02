#include "stdio.h";
#include "stdlib.h";
#include "math.h";

int minimum(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int step = 0;
int prevStep = 0;

int stepCalculator(int size) {
    return (int)log2(size);
}
int binarySearch(int data[], int start,int end, int value) {
    while (start <= end) {
        int middle = (int) ((start + end ) / 2);
        if (data[middle]== value) {
            return middle;
        } else if (data[middle] > value) {
            return binarySearch(data, start, middle-1, value);
        } else {
            return binarySearch(data, middle+1, end, value);
        }
    }
    return -1;
}
int jumpSearch(int data[], int size, int value) {
    step += stepCalculator(size);
    while ((data[minimum(step, size)-1]) < value) {
        prevStep = step;
        step += stepCalculator(size);
        if (prevStep >= size) {
            return -1;
        }
    }
    return binarySearch(data, prevStep, step, value);
}
int main() {
    int data[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 12, 34, 55};
    int size = sizeof data / sizeof data[0];
    int index = jumpSearch(data, size, 20);
    if (index != -1) {
        printf("Your number is at index %d", index);
    } else {
        printf("Your number is not recorded in the database.");
    }
    return 0;
}