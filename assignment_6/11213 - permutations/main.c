//
//  main.c
//  11213
//
//  Created by engine210 on 2018/11/21.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

char list[10];

void print(int n) {
    int i;
    printf("(");
    for (i = 0; i < n; i++) {
        if(i) printf(",");
        printf("%c", list[i]);
    }
    printf(")\n");
}

void swap(int a, int b) {
    char temp;
    temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void perm(int k, int n) {
    int i = k;
    while (i < n) {
        if(k == n - 1) {
            print(n);
            break;
        }
        swap(k, i);
        perm(k + 1, n);
        swap(k, i);
        i++;
    }
}

int main(int argc, const char * argv[]) {
    
    int i,n;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        list[i] = '1' + i;
    }
    
    perm(0, n);
    
    return 0;
}
