//
//  main.c
//  10852
//
//  Created by engine210 on 2018/12/7.
//  Copyright © 2018 engine210. All rights reserved.
//


#include <stdio.h>

int addition(int* a, int array_num, int* entry[], int* index_to_add, int num_ind) {
    int i,sum = 0;
    for (i = 0; i < num_ind * 2; i += 2) {
        sum += entry[array_num][index_to_add[i] * 50 + index_to_add[i+1]];
        sum += a[index_to_add[i] * 50 + index_to_add[i+1]];
        //below code are only testing
        //sum += arr[index_to_add[i]][index_to_add[i+1]];
        //sum += *(a + index_to_add[i] + index_to_add[i+1]);
        //sum += a[index_to_add[i]][index_to_add[i+1]];
        //sum += (*(a+1))[1];
        //sum += entry[array_num][index_to_add[i]+index_to_add[i+1]];
        //sum += *(arr + index_to_add[i] * 2 + index_to_add[i+1]);
        //sum += arr[index_to_add[i]][index_to_add[i+1]];
        //printf("%d %d\n", index_to_add[i], index_to_add[i+1]);
    }
    return sum;
}

int main(void) {
    
    int a[50][50], b[50][50], c[50][50], d[50][50];
    int index_to_add[20];
    int *entry[3];
    int i, j, m, n, array_num, num_ind;
    
    scanf("%d %d", &m, &n);
    
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &b[i][j]);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &c[i][j]);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &d[i][j]);
    
    scanf("%d", &array_num);
    scanf("%d", &num_ind);
    for(i=0; i<num_ind*2; i=i+2)
        scanf("%d %d", &index_to_add[i], &index_to_add[i+1]);
    
    entry[0] = &b[0][0];
    entry[1] = &c[0][0];
    entry[2] = &d[0][0];
    
    printf("%d\n", addition(&a[0][0], array_num, entry, index_to_add, num_ind));
    printf("%d\n", a[1][1]);
    return 0;
}

