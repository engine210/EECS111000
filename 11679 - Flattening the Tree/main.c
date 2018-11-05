//
//  main.c
//  11679
//
//  Created by engine210 on 2018/11/5.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int a[1500];
int n;

void dfs(int cur, int level);

int main() {
    
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    dfs(0,1);
    printf("\n");
    
    return 0;
}

void dfs(int cur, int level) {
    if(cur + pow(2,level) < n) {
        dfs(cur * 2 + 1, level + 1);
        printf("%d ", a[cur]);
        dfs(cur * 2 + 2, level + 1);
    }
    else {
        if (cur == n - 1) {
            printf("%d", a[cur]);
        }
        else {
            printf("%d ", a[cur]);
        }
    }
}

