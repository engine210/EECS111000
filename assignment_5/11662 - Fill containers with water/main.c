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

int n,water,contNum[SIZE],contVolume[SIZE],minimaCont[SIZE],minimaSum,sum,flag = 0;

void filling(int pos, int liter) {
    if(pos < n && liter > 0) {
        filling(pos + 1, liter);
        contNum[pos]++;
        filling(pos, liter - contVolume[pos]);
        contNum[pos]--;
    }
    else if(liter == 0){
        if(flag) {
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += contNum[i];
            }
            if(sum < minimaSum){
                minimaSum = sum;
                memcpy(minimaCont, contNum, sizeof(contNum));
            }
        }
        else {
            memcpy(minimaCont, contNum, sizeof(contNum));
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += contNum[i];
            }
            minimaSum = sum;
            flag = 1;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int i;
    
    scanf("%d", &n);
    memset(contNum,0,sizeof(contNum));
    for (i = 0; i < n; i++) {
        scanf("%d", &contVolume[i]);
    }
    scanf("%d", &water);
    
    filling(0, water);
    
    //output
    printf("(");
    for (i = 0; i < n; i++) {
        if(i) printf(",");
        printf("%d",minimaCont[i]);
    }
    printf(")\n");
    
    return 0;
}
