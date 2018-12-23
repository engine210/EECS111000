#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void insert_increase_list(Node** head, int data) {
    struct _Node *newPtr, *curPtr, *prePtr;
    newPtr = (struct _Node*) malloc(sizeof(struct _Node));
    curPtr = (*head);
    prePtr = NULL;
    newPtr->data = data;
    
    while (curPtr != NULL && data > curPtr->data) {
        prePtr = curPtr;
        curPtr = curPtr->next;
    }
    if (prePtr == NULL) {
        newPtr->next = (*head);
        (*head) = newPtr;
    }
    else {
        prePtr->next = newPtr;
        newPtr->next = curPtr;
    }
}
