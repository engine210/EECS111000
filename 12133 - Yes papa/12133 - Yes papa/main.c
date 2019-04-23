//
//  main.c
//  12133 - Yes papa
//
//  Created by engine210 on 2019/4/23.
//  Copyright © 2019 engine210. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isEqual(char* str1, char* str2, int s1, int e1, int s2, int e2) {
    int len = e1 - s1;
    if (len % 2) {
        return 0;
    }
    else if (len == 2) {
        if (((str1[s1] == str2[s2]) && (str1[s1+1] == str2[s2+1])) || ((str1[s1] == str2[s2+1]) && (str1[s1+1] == str2[s2]))) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    if ((isEqual(str1, str2, s1, s1+len/2, s2, s2+len/2) && isEqual(str1, str2, s1+len/2, e1, s2+len/2, e2)) ||
        (isEqual(str1, str2, s1, s1+len/2, s2+len/2, e2) && isEqual(str1, str2, s1+len/2, e1, s2, s2+len/2))) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int main(int argc, char* argv[]) {
    
    char *str1 = malloc(sizeof(char) * 100000);
    char *str2 = malloc(sizeof(char) * 100000);
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    if (isEqual(str1, str2, 0, (int)strlen(str1), 0, (int)strlen(str2))) {
        printf("YES\n");
    }
    else if (strcmp(str1, str2) == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    
    return 0;
}

