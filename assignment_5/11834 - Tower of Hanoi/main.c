//
//  main.c
//  11834
//
//  Created by engine210 on 2018/10/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

void hanoi(int x) {
    if(x == 1) {
        printf("1\n");
    }
    else {
        hanoi(x-1);
        printf("%d\n", x);
        hanoi(x-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    scanf("%d", &n);
    
    hanoi(n);
    
    return 0;
}
