# include <stdio.h>

void bubbleSort(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size-1-i; j++) {
            int temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
        }
    }
}
int main() {

    int data[] = {8, 6, 4, 2, 0};
    int size = sizeof data / sizeof data[0];
    bubbleSort(data, size);

    for (int i = 0; i < size; i++) {
        printf("%d, ", data[i]);
    }
    return 0;
}