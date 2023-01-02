#include "stdio.h";

int findsize(int data[]) {
    return sizeof data / sizeof data[0];
}
int main() {
    int data[] = {1, 2, 3, 4, 5, 7};
    printf("%d", findsize(data));
}