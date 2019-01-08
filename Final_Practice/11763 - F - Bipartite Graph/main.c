//
//  main.c
//  11763
//
//  Created by engine210 on 2018/12/29.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int n;
int edge[1010][1010];
int flag;

void dfs(int vertice, int depth) {
    int i;
    if (edge[0][vertice] == 0) {
        edge[0][vertice] = depth;
        for (i = 1; i <= n; i++) {
            if (edge[i][vertice]) {
                dfs(i, depth + 1);
            }
        }
    }
    else {
        if ((edge[0][vertice] + depth) % 2) {
            flag = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int T, m;
    int i;
    
    int vertice_1, vertice_2;
    
    scanf("%d", &T);
    
    while (T > 0) {
        scanf("%d%d", &n, &m);
        memset(edge, 0, sizeof(edge));
        for (i = 0; i < m; i++) {
            scanf("%d%d", &vertice_1, &vertice_2);
            edge[vertice_1][vertice_2] = 1;
            edge[vertice_2][vertice_1] = 1;
        }
        
        flag = 1;
        dfs(1, 1);
        flag ? printf("Yes\n") : printf("No\n");
        
        
        T--;
    }
    
    return 0;
}
