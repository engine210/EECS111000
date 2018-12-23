//
//  main.c
//  11766
//
//  Created by engine210 on 2018/12/21.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, const char * argv[]) {
    
    int n;
    
    // Read inputs
    scanf("%d",&n);
    Letter *letters=(Letter*)malloc(sizeof(Letter)*n);
    
    int i;
    for(i=0; i!=n; ++i)
        scanf("%d %s",&(letters[i].zipcode),letters[i].name);
    
    // Sort the data
    qsort(letters,n,sizeof(Letter),compare);
    
    // Output result
    for(i=0; i!=n; ++i)
        printf("%d %s\n",letters[i].zipcode,letters[i].name);
    
    free(letters);
}
