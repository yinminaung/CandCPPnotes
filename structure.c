#include "stdio.h";
#include "string.h";

struct Cat {
    int age;
    char name[50];
    char color[50];
};

int main() {

    struct Cat pussy, muli;
    pussy.age = 1;
    strcpy(pussy.name, "Pussy");
    strcpy(pussy.color, "brown");

    muli.age = 2;
    strcpy(muli.name, "Muli");
    strcpy(muli.color, "yellow");


    printf("First cat is %s\n", pussy.name);
    printf("Second cat is %s\n", muli.name);


    return 0;
}