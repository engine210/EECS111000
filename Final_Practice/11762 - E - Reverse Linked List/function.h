#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Create_List(Node*, int);
Node* Reverse_List(Node*);
void Print_List(Node*);
void Free_List(Node*);

#endif
