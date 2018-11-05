//
//  main.c
//  11618_improved
//
//  Created by engine210 on 2018/11/2.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a / gcd(a, b)) * b;
}

int main(int argc, const char * argv[]) {
    
    int T,i;
    unsigned long long n,x[3];
    
    scanf("%d", &T);
    
    while (T > 0) {
        scanf("%llu", &n);
        for (i = 0; i < 3; i++) {
            scanf("%llu", &x[i]);
        }
        
        for (i = 0; i < 3; i++) {
            x[i] = gcd(n, x[i]);
        }
        
        printf("%llu\n", n / lcm(lcm(x[0], x[1]), x[2]));
        
        T--;
    }
    return 0;
}
