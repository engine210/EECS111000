#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char n[3];
	int i;
	
	scanf("%s",n);
	
	for(i = 0; i < 3; i++){
		printf("%c", n[i] + 16);
	}
	
	return 0;
}
