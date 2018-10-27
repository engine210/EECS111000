#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char str[1010];
	int len,i,j;
	
	scanf("%s",str);
	
	len = strlen(str);
	
	for(i = 0; i < len; i++) {
		for(j = i + 1; j < len; j++){
			printf("%c",str[j]);
		}
		for(j = 0; j <= i; j++){
			printf("%c",str[j]);
		}
		printf("\n");
	}
	
	return 0;
}
