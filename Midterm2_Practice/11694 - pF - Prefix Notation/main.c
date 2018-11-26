//
//  main.c
//  11694
//
//  Created by engine210 on 2018/11/26.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

float cal() {
    char c = getchar();
    if (c == '+') {
        return cal() + cal();
    }
    else if (c == '-') {
        return cal() - cal();
    }
    else if (c == '*') {
        return cal() * cal();
    }
    else if (c == '/') {
        return cal() / cal();
    }
    else {
        return c - '0';
    }
}

int main(int argc, const char * argv[]) {
    
    printf("%.3f", cal());
    
    return 0;
}
