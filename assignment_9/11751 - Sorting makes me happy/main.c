//
//  main.c
//  11751
//
//  Created by engine210 on 2018/12/21.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


int main(int argc, const char * argv[]) {
    
    
    MyData data[100];
    MyData* book[100];
    int i, size;
    
    //freopen("test_in4.txt", "r", stdin);
    //freopen("test_out4.txt", "w", stdout);
    
    scanf("%d", &size);
    
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i].value);
    }
    for (i = 0; i < size; i++) {
        scanf("%s", data[i].str);
    }
    for (i = 0; i < size; i++) {
        scanf("%f", &data[i].x);
    }
    for (i = 0; i < size; i++) {
        book[i] = &data[i];
    }
    
    
    qsort(book, size, sizeof(MyData*), compare_function);
    
    for (i=size-1; i>=0; i--) {
        printf("%d %s %.3f\n", book[i]->value, book[i]->str, book[i]->x);
    }
    
    return 0;
    
}


