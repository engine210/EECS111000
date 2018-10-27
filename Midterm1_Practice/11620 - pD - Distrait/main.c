//
//  main.c
//  11620
//
//  Created by engine210 on 2018/10/22.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int MarkTable[6][6];
int card[6][6];

void mark(int a) {
    int i,j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            if(card[i][j] == a) {
                MarkTable[i][j] = 1;
                break;
            }
        }
        if(MarkTable[i][j]) {
            break;
        }
    }
}

int check() {
    int i,j,flag;
    for (i = 1; i <= 5; i++) {
        flag = 1;
        for (j = 1; j <= 5; j++) {
            if(!MarkTable[i][j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            return 1;
        }
    }
    
    for (j = 1; j <= 5; j++) {
        flag = 1;
        for (i = 1; i <= 5; i++) {
            if(!MarkTable[i][j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            return 1;
        }
    }
    
    flag = 1;
    for (i = 1; i <= 5; i++) {
        if(!MarkTable[i][i]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        return 1;
    }
    
    flag = 1;
    for (i = 1; i <= 5; i++) {
        if(!MarkTable[i][6-i]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int i,j,k;
    int t,n,flag;
    int sel[30];
    
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            scanf("%d", &card[i][j]);
        }
    }
    
    scanf("%d", &t);
    
    for(k = 1; k <= t; k++) {
        memset(MarkTable,0,sizeof(MarkTable));
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &sel[i]);
        }
        flag = 1;
        for (i = 0; i < n; i++) {
            mark(sel[i]);
            if(check()) {
                printf("Case #%d: %d\n", k, i + 1);
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("Case #%d: Not yet \\(^o^)/\n", k);
        }
    }
    return 0;
}
