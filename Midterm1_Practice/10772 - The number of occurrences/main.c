//
//  main.c
//  10772
//
//  Created by engine210 on 2018/11/6.
//  Copyright © 2018 engine210. All rights reserved.
//


#include <stdio.h>
#include <string.h>

int main(void){
    
    int n,i,max,curA,curB,count;
    char a[10], b[20];
    
    scanf("%s", a);
    scanf("%d", &n);
    max = 0;
    
    while (n > 0) {
        scanf("%s", b);
        count = 0;
        for (i = 0; i <= strlen(b) - strlen(a); i++) {
            curA = 0;
            curB = i;
            while (a[curA] == b[curB]) {
                if (curA == strlen(a) - 1) {
                    count++;
                    break;
                }
                curA++;
                curB++;
            }
        }
        if (count > max) {
            max = count;
        }
        n--;
    }
    
    printf("%d", max);
    
    return 0;
}
