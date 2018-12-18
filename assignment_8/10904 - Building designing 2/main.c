//
//  main.c
//  10904
//
//  Created by engine210 on 2018/12/18.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define MAX_FLOOR_NUM 20000

int main(int argc, const char * argv[]) {
    int floorNum;
    int i;
    
    Floor floorArr[MAX_FLOOR_NUM];
    
    scanf("%d", &floorNum);
    
    for (i = 0; i < floorNum; i++) {
        scanf(" %c %d", &floorArr[i].color, &floorArr[i].size);
    }
    
    printf("%d", design(floorNum, floorArr));
    return 0;
}
