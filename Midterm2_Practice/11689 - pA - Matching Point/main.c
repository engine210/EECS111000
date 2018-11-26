//
//  main.c
//  11689
//
//  Created by engine210 on 2018/11/22.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char s[25], t[25];
int count;
int lenS, lenT;

void search(int curS, int curT) {
    int i;
    i = curS;
    if (curT == lenT) {
        count++;
    }
    else {
        while (i <= lenS - lenT + curT) {
            if (s[i] == t[curT]) {
                search(i + 1, curT + 1);
            }
            i++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    while (scanf("%s", s) != EOF) {
        scanf("%s", t);
        count = 0;
        lenS = (int)strlen(s);
        lenT = (int)strlen(t);
        search(0, 0);
        printf("%d\n", count);
    }
    
    return 0;
}
