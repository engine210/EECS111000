//
//  main.c
//  11693
//
//  Created by engine210 on 2018/11/26.
//  Copyright © 2018 engine210. All rights reserved.
//
//https://www.youtube.com/watch?v=feA64wXhbjo

#include <stdio.h>
#include <string.h>

int xmax,h;

void shoot(char room[][100], int y, int x, char dir) {
    room[y][x] = '*';
    if (dir == 'u') {
        if (room[y-1][x] == '-') {
            shoot(room, y+1, x+1, 'd');
        }
        else if(y > 0) {
            shoot(room, y-1, x+1, 'u');
        }
        else {
            xmax = x + 1;
        }
    }
    else {
        if (room[y+1][x] == '-') {
            shoot(room, y-1, x+1, 'u');
        }
        else if(y <= h) {
            shoot(room, y+1, x+1, 'd');
        }
        else {
            xmax = x + 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i,j;
    int c,f,s;
    char dir; //direction u or d
    char room[100][100];
    
    scanf("%d%d%d%d", &c, &f, &h, &s);
    scanf("%c", &dir);
    scanf("%c", &dir);
    
    memset(room, ' ', sizeof(room));
    
    //draw the celling and the floor
    for (i = 0; i < c; i++) {
        room[0][i] = '-';
    }
    for (i = 0; i < f; i++) {
        room[h+1][i] = '-';
    }
    
    shoot(room, s, 0, dir);
    
    //find max output wide
    if (c > xmax) {
        xmax = c;
    }
    if (f > xmax) {
        xmax = f;
    }
    
    //output
    for (i = 0; i <= h + 1; i++) {
        for (j = 0; j < xmax; j++) {
            printf("%c", room[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
