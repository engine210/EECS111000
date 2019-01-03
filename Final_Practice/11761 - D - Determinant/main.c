//
//  main.c
//  11761
//
//  Created by engine210 on 2018/12/27.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

long long det(int a[][10], int n) {
    
    if (n == 2) {
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else {
        int b[10][10]; //create a new array b
        int i, j, k, bx, flag = 1;
        long long val = 0;
        for (i = 0; i < n; i++) {
            bx = 0; //the x-axis position of array b
            for (j = 0; j < n; j++) {
                if (j != i) { //copy the value if i != j
                    for (k = 1; k < n; k++) {
                        b[k-1][bx] = a[k][j];
                    }
                    bx++;
                }
            }
            val += a[0][i] * det(b, n - 1) * flag;
            flag *= -1;
        }
        return val;
    }
}


int main(int argc, const char * argv[]) {
    
    int n;
    int a[10][10];
    int i, j;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("%lld\n", det(a, n));
    
    return 0;
}

/*
3
1 2 3
4 5 6
7 8 9
= 0

4
9 8 7 8
7 6 7 4
6 7 9 9
6 5 7 8
= -192
*/
