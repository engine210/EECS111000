//
//  main.c
//  11619
//
//  Created by engine210 on 2018/10/19.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int T,N;
    int i,j,k;
    int temp,lineNum;
    int count[110];
    long long x[110],y[110];
    
    scanf("%d", &T);
    
    while (T > 0) {
        
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%lld%lld", &x[i], &y[i]);
        }
        memset(count, 0, sizeof(count));
        
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                temp = 2;
                for (k = 0; k < N; k++) {
                    if (k != i && k != j && (x[j] - x[i]) * (y[k] - y[j]) == (x[k] - x[j]) * (y[j] - y[i])) {
                        temp++;
                    }
                }
                count[temp]++;
            }
        }
        
        lineNum = 0;
        for (i = 3; i <= N; i++) {
            count[i] = (count[i] * 2) / (i * (i - 1));
            lineNum += count[i];
        }
        printf("%d\n", lineNum);
        
        T--;
    }
    return 0;
}
