//
//  main.c
//  11618
//
//  Created by engine210 on 2018/11/1.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int T,n,x[4],i,j,sum;
    int ballons[100010];
    
    scanf("%d", &T);
    
    while (T > 0) {
        scanf("%d", &n);
        for (i = 1; i <= 3; i++) {
            scanf("%d", &x[i]);
        }
        
        memset(ballons,0,sizeof(ballons));
        
        for (i = 1; i <= 3; i++) {
            j = x[i];
            ballons[j]++;
            j += x[i];
            if (j > n) {
                j -= n;
            }
            while (j != x[i]) {
                ballons[j]++;
                j += x[i];
                if (j > n) {
                    j -= n;
                }
            }
        }
        
        sum = 0;
        for (i = 1; i <= n; i++) {
            if (ballons[i] == 3) {
                sum++;
            }
        }
        
        printf("%d\n",sum);
        
        T--;
    }
    
    
    return 0;
}
