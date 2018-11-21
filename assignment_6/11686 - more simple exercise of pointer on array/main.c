//
//  main.c
//  11686
//
//  Created by engine210 on 2018/11/22.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
    int i,temp;
    for (i = 0; i < length; i++) {
        temp = array_a[i];
        array_a[i] = array_b[i];
        array_b[i] = temp;
    }
}


