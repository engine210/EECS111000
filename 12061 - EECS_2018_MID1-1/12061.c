#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char str[110];
	int i, j, len;
	int wide, maxWide, maxCur;
	int front, back;
	
	while(scanf("%s", str) != EOF) {
		

		len = strlen(str);
		i = 0;
		maxWide = 0;
		while(i < len) {
			
			front = i - 1;
			back = i + 1;
			wide = 1;
			while(front >= 0 && back < len && str[front] == str[back]) {
				front--;
				back++;
				wide += 2;
			}
			if(wide > maxWide) {
				maxWide = wide;
				maxCur = i;
			}
			
			front = i;
			back = i + 1;
			wide = 0;
			while(front >= 0 && back < len && str[front] == str[back]) {
				front--;
				back++;
				wide+= 2;
			}
			if(wide > maxWide) {
				maxWide = wide;
				maxCur = i;
			}
			
			i++;
		}

		if(maxWide % 2) {
			for(i = maxCur - maxWide / 2; i <= maxCur + maxWide / 2; i++) {
				printf("%c", str[i]);
			}
		}
		else {
			for(i = maxCur - maxWide / 2 + 1; i <= maxCur + maxWide / 2; i++) {
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
