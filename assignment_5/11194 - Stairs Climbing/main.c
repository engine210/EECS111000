//
//  main.c
//  11194
//
//  Created by engine210 on 2018/10/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

int fib(int x);

int main(int argc, const char * argv[]) {
    
    int n,x;
    
    scanf("%d", &n);
    
    while (n > 0) {
        scanf("%d", &x);
        printf("%d\n", fib(x));
        n--;
    }
    
    return 0;
}

int fib(int x) {
    if(x == 1) return 1;
    else if(x == 2) return 2;
    else return fib(x-1) + fib(x-2);
}
