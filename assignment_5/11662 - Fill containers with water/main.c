//
//  main.c
//  11662
//
//  Created by engine210 on 2018/10/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(int argc, const char * argv[]) {
    
    int contVolume[SIZE],contNum[SIZE];
    int n,i,water;
    
    scanf("%d", &n);
    memset(contNum,0,sizeof(contNum));
    for (i = 0; i < n; i++) {
        scanf("%d", &contVolume[i]);
    }
    scanf("%d", &water);
    
    i = 0;
    while (water > 0) {
        contNum[i] += water / contVolume[i];
        water %= contVolume[i];
        i++;
    }
    
    printf("(");
    for (i = 0; i < n; i++) {
        if(i) printf(",");
        printf("%d", contNum[i]);
    }
    printf(")\n");
    
    return 0;
}

/*
4
50 10 5 1
57
*/
