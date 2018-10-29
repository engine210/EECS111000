//
//  main.c
//  11662
//
//  Created by engine210 on 2018/10/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 10

int n,water,contNum[SIZE],contVolume[SIZE],possibleNum[100][SIZE],totalOfPossibleNum[100];
int possibleCount = 0;

void filling(int pos, int liter) {
    if(pos < n && liter < water) {
        filling(pos + 1, liter);
        contNum[pos]++;
        filling(pos, liter + contVolume[pos]);
        contNum[pos]--;
    }
    else {
        if(liter == water) {
            memcpy(possibleNum[possibleCount], contNum, sizeof(contNum));
            possibleCount++;
        }
    }
}

int findMinima() {
    int i,j,min,minPos;
    memset(totalOfPossibleNum, 0, sizeof(totalOfPossibleNum));
    for (i = 0; i < possibleCount; i++) {
        for (j = 0; j < n; j++) {
            totalOfPossibleNum[i] += possibleNum[i][j];
        }
    }
    min = totalOfPossibleNum[0];
    minPos = 0;
    for (i = 1; i < possibleCount; i++) {
        if (totalOfPossibleNum[i] < min) {
            min = totalOfPossibleNum[i];
            minPos = i;
        }
    }
    return minPos;
}

int main(int argc, const char * argv[]) {
    
    int i,idealCase;
    
    scanf("%d", &n);
    memset(contNum,0,sizeof(contNum));
    for (i = 0; i < n; i++) {
        scanf("%d", &contVolume[i]);
    }
    scanf("%d", &water);
    
    filling(0, 0);
    idealCase = findMinima();
    
    //output
    printf("(");
    for (i = 0; i < n; i++) {
        if(i) printf(",");
        printf("%d",possibleNum[idealCase][i]);
    }
    printf(")\n");
    
    return 0;
}
