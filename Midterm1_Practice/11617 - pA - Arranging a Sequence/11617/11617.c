//
//  main.c
//  11617
//
//  Created by engine210 on 2018/10/17.
//  Copyright c 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int n,m,i,j,pos;
	int e[100010];
	int seq[200010];
	
	//input
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d", &e[i]);
	}
	
	//set integer sequence
	for(i = 0; i < n; i++) {
		seq[i] = i + 1;
	}
	
	//progress
	for(i = 0; i < m; i++) {
		for(pos = 0; pos < n; pos++) {
			if(seq[pos] == e[i]){
				break;
			}
		}
		for(j = pos; j > 0; j--) {
			seq[j] = seq[j-1];
		}
		seq[0] = e[i];
	}
	
	//output
	for(i = 0; i < n; i++) {
		//if(i) printf("\n");
		printf("%d\n", seq[i]);
	}
	
	return 0;
}
