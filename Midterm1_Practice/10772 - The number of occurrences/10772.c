//
//  main.c
//  10772
//
//  Created by engine210 on 2018/10/17.
//  Copyright c 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
	
	char a[10];
	char b[15][15];
	int i,j,k,n,cont,max,flag;
	
	//input
	scanf("%s %d", a, &n);
	for(i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	
	max = 0;
	
	for(i = 0; i < n; i++) {
		cont = 0;
		for(j = 0; j < strlen(b[i]) - strlen(a) + 1; j++) {
			flag = 1;
			for(k = 0; k < strlen(a); k++) {
				if(b[i][k+j] != a[k]) {
					flag = 0;
					break;
				}
			}
			if(flag) {
				cont++;
			}
		}
		if(cont > max) {
			max = cont;
		}
	}
	
	printf("%d", max);
	return 0;
}
