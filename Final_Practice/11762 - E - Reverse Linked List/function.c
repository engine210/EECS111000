//
//  function.c
//  11762
//
//  Created by engine210 on 2018/12/29.
//  Copyright © 2018 engine210. All rights reserved.
//

#include "function.h"

Node* Create_List(Node* head, int data) {
    struct _Node* newPtr = (struct _Node*) malloc(sizeof(struct _Node));
    struct _Node *curPtr, *prePtr;
    
    newPtr->data = data;
    newPtr->next = NULL;
    
    curPtr = head;
    prePtr = NULL;
    
    while (curPtr != NULL) {
        prePtr = curPtr;
        curPtr = curPtr->next;
    }
    
    if (prePtr == NULL) {
        head = newPtr;
        return head;
    }
    else {
        prePtr->next = newPtr;
        return head;
    }
}

Node* Reverse_List(Node* head) {
    struct _Node *prePtr, *curPtr, *nextPtr;
    
    prePtr = head;
    curPtr = head->next;
    if (curPtr != NULL) {
        nextPtr = curPtr->next;
        prePtr->next = NULL;
        
        while (nextPtr != NULL) {
            curPtr->next = prePtr;
            
            prePtr = curPtr;
            curPtr = nextPtr;
            nextPtr = curPtr->next;
        }
        curPtr->next = prePtr;
        return curPtr;
    }
    else {
        return head;
    }
}

void Print_List(Node* head) {
    struct _Node *curPtr = head;
    printf("%d", curPtr->data);
    curPtr = curPtr->next;
    while (curPtr != NULL) {
        printf("->%d", curPtr->data);
        curPtr = curPtr->next;
    }
    printf("\n");
}

void Free_List(Node* head) {
    struct _Node *curPtr = head, *nextPtr = curPtr->next;
    while (nextPtr != NULL) {
        free(curPtr);
        curPtr = nextPtr;
        nextPtr = nextPtr->next;
    }
}
