#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int a, n, d;
	
	scanf("%d%d%d", &a, &n, &d);
	
	printf("%d", a + (n - 1) * d);
	printf(" %d", (a + a + (n - 1) * d) * n / 2);
	
	return 0;
}
