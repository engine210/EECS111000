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
	int e_flag[200010];
	
	//input
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d", &e[i]);
	}
	
	memset(seq,1,sizeof(seq));
	memset(e_flag,0,sizeof(e_flag));
	
	//progress
	for(i = 0; i < m; i++) {
		seq[e[i]] = 0;
	}
	
	//output
	for(i = m - 1; i >= 0; i--) {
		if(e_flag[e[i]] == 0){
			printf("%d\n", e[i]);
			e_flag[e[i]] = 1;
		}
	}
	for(i = 1; i <= n; i++) {
		if(seq[i]){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
