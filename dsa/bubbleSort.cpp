#include "stdio.h"
#include "stdlib.h"

void bubbleSort(int data[], int size) {
    for (int i = 0; i < size -1; i++) {
        for (int j = 0; j < size-i-1;j++) {
            if (data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
int main() {
    int data[] = {9, 8, 7, 6, 5, 0, 2, 3, 4, 3, 2, 1};
    int size = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}