//
//  main.c
//  12055
//
//  Created by engine210 on 2018/10/31.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[1010],b[1010],temp[1010];
    int i,j,lenA,lenB,tempLen,maxLen,posB;
    
    
    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));
    
    while(scanf("%s",a) != EOF) {
        scanf("%s",b);
        
        if(strlen(a) < strlen(b)) {
            memcpy(temp, a, sizeof(a));
            memcpy(a, b, sizeof(b));
            memcpy(b, temp, sizeof(temp));
        }
        lenA = (int)strlen(a);
        lenB = (int)strlen(b);
        //printf("%d %d\n",lenA,lenB);
        /*
        for (i = 0; i < lenA; i++) {
            printf("%c",a[i]);
        }
        printf("\n");
        for (i = 0; i < lenB; i++) {
            printf("%c",b[i]);
        }
        printf("\n");
        */
        maxLen = 0;
        for (i = 0; i < lenB; i++){
            tempLen = 0;
            posB = i;
            for (j = 0; j <= lenA; j++) {
                if (posB == lenB || j == lenA) {
                    //printf("a %d %d \n", j, posB);
                    if(tempLen > maxLen){
                        maxLen = tempLen;
                    }
                    break;
                }
                else if (a[j] == b[posB]) {
                    //printf("b %d %d \n", j, posB);
                    tempLen++;
                    posB++;
                }
                else {
                    //printf("c %d %d \n", j, posB);
                    if(tempLen) j--;
                    if(tempLen > maxLen){
                        maxLen = tempLen;
                    }
                    tempLen = 0;
                    posB = i;
                }
            }
        }
        printf("%d\n",maxLen);
        
        
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
    }
    
    
    return 0;
}

