//
//  main.c
//  11621
//
//  Created by engine210 on 2018/10/22.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char s[2010];
    int i,j,k,cont,flag;
    
    while (scanf("%s", s) != EOF) {
        cont = 0;
        for (i = 2; i <= strlen(s); i++) {
            for (j = 0; j <= strlen(s) - i; j++) {
                flag = 1;
                for (k = 0; k < i / 2; k++) {
                    if (s[j+k] != s[j+i-k-1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    cont++;
                }
                //printf("%d %d %d %d\n",i,j,k,flag);
            }
        }
        printf("%d\n",cont);
    }
    return 0;
}
