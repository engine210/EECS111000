#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n,a1,a2,a3,total;
	float average;
	
	scanf("%d",&n);
	
	a1 = n/100;
	a2 = (n-a1*100)/10;
	a3 = n%10;
	
	total = (n + a3*100 + a2*10 + a1);
	average = (float)total / 2;
	
	printf("%.1f",average);
	
	return 0;
}
