//
//  main.c
//  11142 - Matrix Multiplication
//
//  Created by engine210 on 2018/10/8.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n,m,p,i,j,k;
    long sum;
    int a[105][105],b[105][105];
    
    while(scanf("%d%d%d",&n,&m,&p) != EOF) {
        
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                scanf("%d",&a[i][j]);
            }
        }
        for(i = 1; i <= m; i++) {
            for(j = 1; j <= p; j++) {
                scanf("%d",&b[i][j]);
            }
        }
        
        for(i = 1; i <= n; i++) {
            for(j = 1; j < p; j++) {
                sum = 0;
                for(k = 1; k <= m; k++) {
                    sum += a[i][k] * b[k][j];
                }
                printf("%ld ",sum);
            }
            sum = 0;
            for(k = 1; k <= m; k++) {
                sum += a[i][k] * b[k][p];
            }
            printf("%ld\n",sum);
            //printf("\n");
        }
        printf("\n");
    }
    return 0;
}
