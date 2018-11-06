//
//  main.c
//  11617_faster
//
//  Created by engine210 on 2018/11/6.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int n,m,i;
    int e[100010];
    int flag[200010];
    
    scanf("%d%d", &n, &m);
    
    memset(flag,1,sizeof(flag));
    
    for (i = 0; i < m; i++) {
        scanf("%d", &e[i]);
    }
    
    for (i = m - 1; i >= 0; i--) {
        if (flag[e[i]]) {
            printf("%d\n", e[i]);
            flag[e[i]] = 0;
        }
    }
    for (i = 1; i <= n; i++) {
        if (flag[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
