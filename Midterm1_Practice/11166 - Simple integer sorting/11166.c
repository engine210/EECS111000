//
//  main.c
//  11166
//
//  Created by engine210 on 2018/10/17.
//  Copyright c 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int v[10010];
int n;

void sort() {
	int i,j,temp;
	for(i = 1; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			if(v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	int t,i,j;
	
	scanf("%d", &t);
	
	for(i = 0; i < t; i++) {
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d", &v[j]);
		}
		
		sort();
		
		for(j = 0; j < n; j++){
			if(j) printf(" ");
			printf("%d", v[j]);
		}
		printf("\n");
	}
	return 0;
}
