//
//  main.c
//  11691
//
//  Created by engine210 on 2018/11/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

char map[1010][1010];
int m,n;

void flag(int y, int x) {
    if (map[y][x] == '~' && y >= 0 && x >= 0 && y < m && x < n) {
        map[y][x] = '0';
        flag(y+1, x);
        flag(y-1, x);
        flag(y, x+1);
        flag(y, x-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int i,j,count;
    
    scanf("%d%d", &m, &n);
    
    for (i = 0; i < m; i++) {
        scanf("%s", map[i]);
    }
    
    count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (map[i][j] == '~') {
                count++;
                flag(i,j);
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
