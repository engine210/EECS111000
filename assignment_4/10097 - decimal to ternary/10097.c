#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int x,y,i;
	int num[20];
	
	scanf("%d%d",&x,&y);
	
	memset(num,0,sizeof(num));
	
	i = 0;
	while(x != 0) {
		num[i] = x % 3;
		x /= 3;
		i++;
	}
	
	for(i = y - 1; i >= 0; i--) {
		printf("%d",num[i]);
	}
	printf("\n");
	
	return 0;
}
