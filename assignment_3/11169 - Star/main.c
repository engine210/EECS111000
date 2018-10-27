//
//  main.c
//  11169
//
//  Created by engine210 on 2018/10/9.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n,m,x,y,i,j;
    char matrix[20][20];
    
    scanf("%d%d%d%d",&n,&m,&x,&y);
    
    for(i = 0; i < n; i++) {
        for( j = 0; j < m; j++) {
            matrix[i][j] = '-';
        }
    }
    
    for(i = 0; i < n; i++) {
        matrix[i][y] = '+';
    }
    
    for(j = 0; j < m; j++) {
        matrix[x][j] = '+';
    }
    
    for(i = 1; i <= n || i <= m; i++) {
        if(x-i >= 0 && y-i >= 0){
            matrix[x-i][y-i] = '*';
        }
        if(x+i < n && y-i >= 0){
            matrix[x+i][y-i] = '*';
        }
        if(x-i >= 0 && y+i < m){
            matrix[x-i][y+i] = '*';
        }
        if(x+i < n && y+i < m){
            matrix[x+i][y+i] = '*';
        }
    }
    
    matrix[x][y] = 'S';
    
    for(i = 0; i < n; i++) {
        for( j = 0; j < m; j++) {
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
