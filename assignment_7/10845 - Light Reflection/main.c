//
//  main.c
//  10845
//
//  Created by engine210 on 2018/12/7.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

int x, y, height, width, k, refTime; // reflect times

void emit(char dir) {
    if (refTime < k - 1) {
        switch (dir) {
            case 'a':
                if (y == 1 && x == width) {
                    
                }
                else if (y == 1) {
                    refTime++;
                    y++;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('b');
                }
                else if (x == width) {
                    refTime++;
                    y--;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('d');
                }
                else {
                    y--;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('a');
                }
                break;
            case 'b':
                if (y == height && x == width) {
                    
                }
                else if (y == height) {
                    refTime++;
                    y--;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('a');
                }
                else if (x == width) {
                    refTime++;
                    y++;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('c');
                }
                else {
                    y++;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('b');
                }
                break;
            case 'c':
                if (y == height && x == 1) {
                    
                }
                else if (y == height) {
                    refTime++;
                    y--;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('d');
                }
                else if (x == 1) {
                    refTime++;
                    y++;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('b');
                }
                else {
                    y++;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('c');
                }
                break;
            case 'd':
                if (y == 1 && x == 1) {
                    
                }
                else if (y == 1) {
                    refTime++;
                    y++;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('c');
                }
                else if (x == 1) {
                    refTime++;
                    y--;
                    x++;
                    //printf("(%d,%d)\n", y, x);
                    emit('a');
                }
                else {
                    y--;
                    x--;
                    //printf("(%d,%d)\n", y, x);
                    emit('d');
                }
                break;
        }
    }
    else {
        switch (dir) {
            case 'a':
                y++;
                x--;
                break;
            case 'b':
                x--;
                y--;
                break;
            case 'c':
                x++;
                y--;
                break;
            case 'd':
                x++;
                y++;
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d%d", &height, &width);
    scanf("%d%d", &y, &x);
    scanf("%d", &k);
    
    refTime = 0;
    emit('a');
    
    printf("(%d,%d)", y, x);
    
    return 0;
}
