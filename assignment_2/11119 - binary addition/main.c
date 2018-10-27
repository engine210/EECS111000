//
//  main.c
//  11119 - binary addition
//
//  Created by engine210 on 2018/10/3.
//  Copyright © 2018年 engine210. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n,i,pos,cont;
    int bin[15];
    
    scanf("%d", &n);
    //printf("%d",n);
    
    pos = 1;
    while(n != 1){
        bin[pos] = n % 2;
        n /= 2;
        pos++;
    }
    bin[pos] = 1;
    
    cont = 0;
    bin[1] += 1;
    for(i = 1; i <= pos; i++){
        if(bin[i] == 2){
            bin[i] -= 2;
            bin[i+1]++;
            cont++;
        }
        else if(bin[i] == 1){
            break;
        }
    }
    
    if(bin[pos] == 0){
        for(i = pos+1; i > 0; i--){
            printf("%d", bin[i]);
        }
    }
    else{
        for(i = pos; i > 0; i--){
            printf("%d", bin[i]);
        }
    }
    
    printf(" %d",cont);
    
    return 0;
}
