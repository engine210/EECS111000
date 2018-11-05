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
    
    char s[2010];
    int i,count,begin,end,len;
    
    while (scanf("%s", s) != EOF) {
        
        len = (int)strlen(s);
        count = 0;
        
        for (i = 0; i < len - 1; i++) {
            begin = i;
            end = i + 1;
            while (begin >= 0 && end < len) {
                if(s[begin] == s[end]) {
                    count++;
                    begin--;
                    end++;
                }
                else {
                    break;
                }
            }
            begin = i - 1;
            end = i + 1;
            while (begin >= 0 && end < len) {
                if(s[begin] == s[end]) {
                    count++;
                    begin--;
                    end++;
                }
                else {
                    break;
                }
            }
        }
        
        printf("%d\n",count);
    }
    return 0;
}

