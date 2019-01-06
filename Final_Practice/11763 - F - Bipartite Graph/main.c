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
int depth;

void show(void);

void dfs(int vertice) {
    int i;
    //show();
    if (edge[0][vertice] == 0) {
        edge[0][vertice] = depth;
        for (i = 1; i <= n; i++) {
            if (edge[i][vertice]) {
                depth++;
                dfs(i);
                depth--;
            }
        }
    }
}

int judge() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (edge[i][j] && (edge[0][i] + edge[0][j]) % 2 == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void show() {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d ", edge[i][j]);
        }
        printf("\n");
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
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &vertice_1, &vertice_2);
            edge[vertice_1][vertice_2] = 1;
            edge[vertice_2][vertice_1] = 1;
        }
        
        depth = 1;
        dfs(1);
        judge() ? printf("Yes\n") : printf("No\n");
        
        T--;
    }
    
    return 0;
}
