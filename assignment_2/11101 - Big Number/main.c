#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num, mid, a, b, c1, c2, c3;
	
	scanf("%d", &num);
	
	a = num/10000;
	b = num%10000;
	mid = 2*a*b;
	
	c3 = (b*b)%10000;
	c2 = mid + (b*b)/10000 + ((a*a)%10000)*10000;
	c1 = a*a/10000+c2/100000000;
	
	//printf("%d %d %d",b*b,mid,c2);
	
	printf("%4d",c1);
	printf("%08d",c2%100000000);
	printf("%04d",c3);	
	
	return 0;
}
