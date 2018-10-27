#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int N, X, Y, Z;
	
	scanf("%d%d%d%d",&N,&X,&Y,&Z);
	
	printf("%d", X + Y - N + Z);
	printf(" %d", N - Y - Z);
	
	return 0;
}
