//
//  main.c
//  11762
//
//  Created by engine210 on 2018/12/27.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}
