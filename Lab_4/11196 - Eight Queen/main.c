//
//  main.c
//  11196
//
//  Created by engine210 on 2018/11/28.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int in[10][10];
int board[10][10];
int max,n;

int only(int x, int y) {
    int i,xc,yc;
    int flag = 1;
    for (i = 1; i <= 8; i++) {
        if (board[i][x] == 1) {
            flag = 0;
            break;
        }
    }
    xc = x;
    yc = y;
    while (xc > 0 && yc > 0) {
        if (board[yc][xc] == 1) {
            flag = 0;
            break;
        }
        xc--;
        yc--;
    }
    xc = x;
    yc = y;
    while (xc > 0 && yc <= 8) {
        if (board[yc][xc] == 1) {
            flag = 0;
            break;
        }
        xc--;
        yc++;
    }
    xc = x;
    yc = y;
    while (xc <= 8 && yc > 0) {
        if (board[yc][xc] == 1) {
            flag = 0;
            break;
        }
        xc++;
        yc--;
    }
    xc = x;
    yc = y;
    while (xc <= 8 && yc <= 8) {
        if (board[yc][xc] == 1) {
            flag = 0;
            break;
        }
        xc++;
        yc++;
    }
    return flag;
}

int cal(){
    int q = 0;
    int i,j;
    for(i = 1; i <= 8; i++) {
        for(j = 1; j <= 8; j++) {
            if(board[i][j]){
                q += in[i][j];
            }
        }
    }
    return q;
}

void find(int y) {
    int i;
    if(y > 8) {
        int q;
        q = cal();
        if(q > max){
            max = q;
        }
    }
    else {
        for(i = 1; i <= 8; i++) {
            if(only(i, y)){
                board[y][i] = 1;
                find(y+1);
                board[y][i] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,j;
    
    scanf("%d", &n);
    
    while(n > 0) {
        for(i = 1; i <= 8; i++) {
            for(j = 1; j <= 8; j++) {
                scanf("%d", &in[i][j]);
            }
        }
        
        memset(board, 0, sizeof(board));
        max = 0;
        find(1);
        printf("%d\n", max);
        
        n--;
    }
    return 0;
}
