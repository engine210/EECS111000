//
//  main.c
//  10786
//
//  Created by engine210 on 2018/10/17.
//  Copyright c 2018 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int n1,n2,n3;
	
	scanf("%d%d%d", &n1, &n2, &n3);
	
	if(n2 - n1 == n3 - n2){
		printf("%d %d", n1 - (n2 - n1), n3 + (n2 - n1));
	}
	else{
		printf("%d %d", n1 * n1 / n2, n3 * n3 / n2);
	}
	return 0;
}
