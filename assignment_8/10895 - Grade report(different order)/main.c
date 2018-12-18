//
//  main.c
//  10895
//
//  Created by engine210 on 2018/12/16.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, const char * argv[]){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    sortGrade(gradeList, n, order);
    
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    
    return 0;
}




/*
8 descending
104062888 100 98 100 100
104062444 98 100 100 100
104062555 100 100 98 100
104062222 98 100 100 100
104062666 100 100 100 100
104062111 100 100 100 98
104062333 100 100 100 97
104062777 100 99 99 100
*/
