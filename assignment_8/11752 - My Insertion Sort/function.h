//
// Created by 贾松昊 on 2017/12/21.
//

#ifndef TEST_FOR_C_FUNCTION_H
#define TEST_FOR_C_FUNCTION_H

#include <stdio.h>
#include <string.h>

int compare(const void* a, const void* b) {
    const int* va = (const int*)a;
    const int* vb = (const int*)b;
    if (*va < *vb) {
        return 1;
    }
    else {
        return 0;
    }
}

void assign(char* x, char* y, size_t size) {
    memcpy(x, y, sizeof(char)*size);
}

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*)) {
    
    int i, j;
    char* a = (char*) arr;
    char* key = (char*) malloc(sizeof(char)*size);
    
    for (i = 1; i < count; i++) {
        j = i - 1;
        assign(key, a+i*size, size);
        while (j >= 0 && compare(key, a+j*size)) {
            //printf("%d %d\n", *(a+(j+1)*size), *(a+j*size));
            assign(a+(j+1)*size, a+j*size, size);
            j--;
        }
        assign(a+(j+1)*size, key, size);
    }
}

#endif //TEST_FOR_C_FUNCTION_H
