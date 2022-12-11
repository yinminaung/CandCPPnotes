/**
 * @file linkedList.c
 * @author Yin Min Aung
 * 
 */
#include "stdio.h";
#include "stdlib.h";



struct node {
    int data;
    struct node *next;
};

// function declarations
void printData(struct node *firstNode);
void insertAtEnd(struct node *prevNode, int);
struct node* insertAtStart(struct node *firstNode, int);
struct node* lastNode(struct node *firstNode);


int main() {
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    head = one;

    one->data = 10;
    two->data = 20;
    three->data = 30;

    one->next = two;
    two->next = three;
    three->next = NULL;
    

    // testing 
    printData(head);
    printf("Adding 40 at the end....\n");
    insertAtEnd(lastNode(head), 40);
    printData(head);

    printf("Adding 50 at the end....\n");
    insertAtEnd(lastNode(head), 50);
    printData(head);

    // insert at beginning
    printf("Inserting 0 at the beginning....\n");
    head = insertAtStart(head, 0);
    printData(head);

    return 0;
}
struct node* lastNode(struct node *startNode) {
    if (startNode == NULL) {
        printf("The first node is NULL!\n");
        return;
    }
    struct node *nextLast;
    while (startNode->next != NULL) {
        startNode = startNode->next;
        nextLast = startNode;
    }
    return nextLast;

}
void printData(struct node *myNode) {
    if (myNode == NULL) {
        printf("The first node is NULL!\n");
        return;
    }
    while (myNode != NULL) {
        printf("%d\n", myNode->data);
        myNode = myNode->next;
    }
}

void insertAtEnd(struct node *prevNode, int myData) {
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = myData;
    newNode->next = NULL;

    prevNode->next = newNode;
}

struct node* insertAtStart(struct node *firstNode, int myData) {
    if (firstNode == NULL) {
        printf("Your first Node is NULL!\n");
        return;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = myData;
    newNode->next = firstNode;

    return newNode;
}
