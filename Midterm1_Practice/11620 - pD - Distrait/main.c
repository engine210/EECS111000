//
//  main.c
//  11620
//
//  Created by engine210 on 2018/10/22.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int i,j,k,flag;
    int T,N;
    int bingo[6][6];
    int sel[30];
    int ver[6],hor[6],obliqueL,obliqueR;
    
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            scanf("%d", &bingo[i][j]);
        }
    }
    
    scanf("%d", &T);
    int times = 1;
    while (T >= times) {
        memset(ver, 0, sizeof(ver));
        memset(hor, 0, sizeof(hor));
        obliqueL = 0;
        obliqueR = 0;
        
        scanf("%d", &N);
        
        for (i = 0; i < N; i++) {
            scanf("%d", &sel[i]);
        }
        
        for (i = 0; i < N; i++) {
            flag = 0;
            for (j = 1; j <= 5; j++) {
                for (k = 1; k <= 5; k++) {
                    if (sel[i] == bingo[j][k]) {
                        ver[j]++;
                        hor[k]++;
                        if (j == k) {
                            obliqueL++;
                        }
                        if (j == 6 - k) {
                            obliqueR++;
                        }
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            
            flag = 0;
            if(obliqueL == 5 || obliqueR == 5) {
                printf("Case #%d: %d\n", times, i + 1);
                flag = 1;
                break;
            }
            for (j = 1; j <= 5; j++) {
                if (ver[j] == 5 || hor[j] == 5) {
                    printf("Case #%d: %d\n", times, i + 1);
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        
        if (!flag) {
            printf("Case #%d: Not yet \\(^o^)/\n", times);
        }
        
        times++;
    }
    return 0;
}
