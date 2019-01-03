//
//  main.c
//  11758
//
//  Created by engine210 on 2018/12/25.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mul(double A[10][10], double x[10], int n) {
    int i, j;
    double temp[10];
    for (i = 0; i < n; i++) {
        temp[i] = 0;
        for (j = 0; j < n; j++) {
            temp[i] += A[i][j] * x[j];
        }
    }
    memcpy(x, temp, sizeof(temp));
}

int main(int argc, const char * argv[]) {
    
    double A[10][10];
    double x[10];
    int T, n, p;
    int i, j;
    
    
    scanf("%d", &T);
    
    while (T > 0) {
        
        //input
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%lf", &A[i][j]);
            }
        }
        for (i = 0; i < n; i++) {
            scanf("%lf", &x[i]);
        }
        scanf("%d", &p);
        
        /*
         this is a short cut to solve this problem.
         we can just simply output "Never" if x[0] doesn't reach p after 100 times of multiplication.
         but it may output wrong answer in extreme testcase
        */
        i = 0; //set the years to 0
        while (x[0] > p) {
            mul(A, x, n); //calculate Ax
            i++;
            if (i > 120) break;
        }
        
        //output
        if (i > 100) printf("Never\n");
        else printf("%d\n", i);
        
        T--;
    }
    
    return 0;
}
