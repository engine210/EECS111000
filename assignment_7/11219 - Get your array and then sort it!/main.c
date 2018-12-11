//
//  main.c
//  11219
//
//  Created by engine210 on 2018/12/5.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* readInput() {
    int i, N, *seq;
    scanf("%d", &N);
    seq = (int*)malloc(sizeof(int)*(N + 1));
    //printf("seq %p\n", seq);
    seq[0] = N;
    for(i=1; i<N+1; i++)
        scanf("%d", &seq[i]);
    return seq;
}

void my_sort(int* B) {
    /*
    int* arr = (int*) *B;
    int i,j,temp;
    
    for(i = 1; i < arr[0]; i++) {
        for(j = 1; j <= arr[0] - i; j++) {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    */
    int** arr = (int**) B;
    int i,j,temp;
    
    for(i = 1; i < (*arr)[0]; i++) {
        for(j = 1; j <= (*arr)[0] - i; j++) {
            if((*arr)[j] > (*arr)[j+1]){
                temp = (*arr)[j];
                (*arr)[j] = (*arr)[j+1];
                (*arr)[j+1] = temp;
            }
        }
    }
}

int main() {
    int i;
    int *A = readInput();
    //printf("%p\n", A);
    my_sort((int*)&A);
    printf("%d", A[1]);
    for(i=2;i<A[0]+1;i++)
        printf(" %d", A[i]);
    printf("\n");
    return 0;
}
