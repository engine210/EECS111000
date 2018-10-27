#include <stdio.h>
#include <string.h>

char a_ori[1010], b_ori[1010];
int a[1010], b[1010], len;
long long sum[1010], c;

void trans() {
    int i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i = 0; i < strlen(a_ori); i++) {
        a[i] = a_ori[strlen(a_ori) - 1 - i] - '0';
    }
    for(i = 0; i < strlen(b_ori); i++) {
        b[i] = b_ori[strlen(b_ori) - 1 - i] - '0';
    }
}

void add() {
    int i;
    memset(sum,0,sizeof(sum));
    for(i = 0; i < len; i++){
        sum[i] = a[i] + b[i];
    }
}

void devide() {
    int i;
    for(i = 1008; i >= 0; i--) {
        sum[i-1] += (sum[i] % c) * 10;
        sum[i] /= c;
    }
}

void round_up() {
	int i;
    for(i = 0; i <= 1008; i++) {
        sum[i+1] += sum[i] / 10;
        sum[i] %= 10;
    }
}

void print() {
    int i,flag;
    flag = 0;
    for(i = 1008; i >=0; i--) {
        if(sum[i] != 0){
            flag = 1;
        }
        if(flag) {
            printf("%lld",sum[i]);
        }
    }
    if(!flag) {
    	printf("0");
	}
    printf("\n");
}

int main(int argc, const char *argv[]) {
    
    int n,k;
    
    scanf("%d",&n);
    
    for(k = 0; k < n; k++) {
    	memset(a_ori,'\0',sizeof(a));
    	memset(b_ori,'\0',sizeof(b));
        scanf("%s%s%lld",a_ori,b_ori,&c);
        if(strlen(a_ori) > strlen(b_ori)){
        	len = strlen(a_ori); 
		}
        else{
        	len = strlen(b_ori); 
		}
        trans();
        add();
        devide();
        round_up();
        print();
    }
    return 0;
}
