//
//  main.c
//  11692
//
//  Created by engine210 on 2018/11/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

char map[1010][1010];
int m,n;
int life; //dead or alive

void flag(int y, int x) {
    if (map[y][x] == '~') {
        life = 1;
    }
    else if (map[y][x] != '^' && y >= 0 && x >= 0 && y < m && x < n) {
        map[y][x] = '^';
        flag(y+1, x);
        flag(y-1, x);
        flag(y, x+1);
        flag(y, x-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int i,j;
    int ex,ey; //th position of eccioa
    
    scanf("%d%d", &m, &n);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if ((map[i][j] = getchar()) == '\n'){
                j--;
            }
            if (map[i][j] == 'e') {
                ey = i;
                ex = j;
            }
        }
    }
    
    life = 0;
    flag(ey, ex);
    
    if (life) {
        printf("Alive!\n");
    }
    else {
        printf("Dead!\n");
    }
    
    return 0;
}

/*
test data

5 5
^^^^~
...^.
.^.^.
.^.^.
e^...
*/
