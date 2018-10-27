//
//  main.c
//  11621_faster
//
//  Created by engine210 on 2018/10/24.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char in[2010];
    char s[4020];
    int i,j,cont,pos,len;
    
    while (scanf("%s", in) != EOF) {
        memset(s,'\0',sizeof(s));
        len = (int)strlen(in);
        for (i = 0; i < len; i++) {
            s[i*2] = in[i];
        }
        len = len * 2 - 1;
        cont = 0;
        
        pos = 1;
        for (i = 1; i <= len / 2; i++) {
            for (j = 1; j <= i; j++) {
                if (s[pos+j] == s[pos-j]) {
                    if(s[pos+j] != '\0') {
                        cont++;
                    }
                }
                else {
                    break;
                }
            }
            pos++;
        }
        for (i = len / 2 - 1; i >= 1; i--) {
            for (j = 1; j <= i; j++) {
                if (s[pos+j] == s[pos-j]) {
                    if(s[pos+j] != '\0') {
                        cont++;
                    }
                }
                else {
                    break;
                }
            }
            pos++;
        }
        
        printf("%d\n",cont);
    }
    return 0;
}
