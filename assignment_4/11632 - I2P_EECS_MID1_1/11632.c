#include <stdio.h>
#include <stdlib.h>
#define test

int rows,columes,ins_len;
char TankDir;
char ins[110];
char map[110][110];
int x,y;//tank center location
int money;

void FindTankLocation() {
	int i,j,flag;
	flag = 0;
	for(i = 0; i < columes; i++) {
		for(j = 0; j < rows; j++) {
			if(map[i][j] == 'O' || map[i][j] == 'o' || map[i][j] == 'x') {
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	x = j+1;
	y = i+1;
}

void rotate_r() {
	char temp;
	temp = map[y-1][x-1];
	map[y-1][x-1] = map[y+1][x-1];
	map[y+1][x-1] = map[y+1][x+1];
	map[y+1][x+1] = map[y-1][x+1];
	map[y-1][x+1] = temp;
	
	temp = map[y-1][x];
	map[y-1][x] = map[y][x-1];
	map[y][x-1] = map[y+1][x];
	map[y+1][x] = map[y][x+1];
	map[y][x+1] = temp;
	
	if(TankDir == 'N'){
		TankDir = 'E';
	}
	else if(TankDir == 'E'){
		TankDir = 'S';
	}
	else if(TankDir == 'S'){
		TankDir = 'W';
	}
	else if(TankDir == 'W'){
		TankDir = 'N';
	}
}

void move() {
	if(TankDir == 'N'){
		if(!block()) {
			
			if(map[y-2][x-1] == '$') money++;
			if(map[y-2][x] == '$') money++;
			if(map[y-2][x+1] == '$') money++;
			
			map[y-2][x-1] = 'x';
			map[y-2][x] = 'o';
			map[y-2][x+1] = 'x';
			
			map[y-1][x-1] = 'O';
			map[y-1][x] = 'O';
			map[y-1][x+1] = 'O';
			
			map[y+1][x-1] = '=';
			map[y+1][x] = '=';
			map[y+1][x+1] = '=';
			y--;
		}
	}
	else if(TankDir == 'E'){
		if(!block()) {
			
			if(map[y-1][x+2] == '$') money++;
			if(map[y][x+2] == '$') money++;
			if(map[y+1][x+2] == '$') money++;
			
			map[y-1][x+2] = 'x';
			map[y][x+2] = 'o';
			map[y+1][x+2] = 'x';
			
			map[y-1][x+1] = 'O';
			map[y][x+1] = 'O';
			map[y+1][x+1] = 'O';
			
			map[y-1][x-1] = '=';
			map[y][x-1] = '=';
			map[y+1][x-1] = '=';
			x++;
		}
	}
	else if(TankDir == 'S'){
		if(!block()) {
			
			if(map[y+2][x-1] == '$') money++;
			if(map[y+2][x] == '$') money++;
			if(map[y+2][x+1] == '$') money++;
			
			map[y+2][x-1] = 'x';
			map[y+2][x] = 'o';
			map[y+2][x+1] = 'x';
			
			map[y+1][x-1] = 'O';
			map[y+1][x] = 'O';
			map[y+1][x+1] = 'O';
			
			map[y-1][x-1] = '=';
			map[y-1][x] = '=';
			map[y-1][x+1] = '=';
			y++;
		}
	}
	else if(TankDir == 'W'){
		if(!block()) {
			
			if(map[y-1][x-2] == '$') money++;
			if(map[y][x-2] == '$') money++;
			if(map[y+1][x-2] == '$') money++;
			
			map[y-1][x-2] = 'x';
			map[y][x-2] = 'o';
			map[y+1][x-2] = 'x';
			
			map[y-1][x-1] = 'O';
			map[y][x-1] = 'O';
			map[y+1][x-1] = 'O';
			
			map[y-1][x+1] = '=';
			map[y][x+1] = '=';
			map[y+1][x+1] = '=';
			x--;
		}
	}
}

int block(){
	if(TankDir == 'N'){
		if((map[y-2][x-1]=='='||map[y-2][x-1]=='$')
			&& (map[y-2][x]=='='||map[y-2][x]=='$')
			&& (map[y-2][x+1]=='='||map[y-2][x+1]=='$')){
			return 0;
		}
		else return 1;
	}
	else if(TankDir == 'E'){
		if((map[y-1][x+2]=='='||map[y-1][x+2]=='$')
			&& (map[y][x+2]=='='||map[y][x+2]=='$')
			&& (map[y+1][x+2]=='='||map[y+1][x+2]=='$')){
			return 0;
		}
		else return 1;
	}
	else if(TankDir == 'S'){
		if((map[y+2][x-1]=='='||map[y+2][x-1]=='$')
			&& (map[y+2][x]=='='||map[y+2][x]=='$')
			&& (map[y+2][x+1]=='='||map[y+2][x+1]=='$')){
			return 0;
		}
		else return 1;
	}
	else if(TankDir == 'W'){
		if((map[y-1][x-2]=='='||map[y-1][x-2]=='$')
			&& (map[y][x-2]=='='||map[y][x-2]=='$')
			&& (map[y+1][x-2]=='='||map[y+1][x-2]=='$')){
			return 0;
		}
		else return 1;
	}
}

#ifndef test
void print() {
	int i,j;
	for(i = 0; i < columes; i++){
		for(j = 0; j < rows; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	printf("%c %d\n",TankDir,money);
}
#endif

int main(int argc, char *argv[]) {
	
	int i, j;
	
	scanf("%d %d %d %c",&rows,&columes,&ins_len,&TankDir);
	
	scanf("%s",ins);

	for(i = 0; i < columes; i++){
		scanf("%s",&map[i]);
	}
	money = 0;
	FindTankLocation();
	
	#ifdef test
	for(i = 0; i < ins_len; i++){
		if(ins[i] == 'R'){
			rotate_r();
		}
		else if(ins[i] == 'L'){
			rotate_r();
			rotate_r();
			rotate_r();
		}
		else if(ins[i] == 'F'){
			move();
		}
	}
	printf("%d\n",money);
	#endif
	
	#ifndef test
	char in;
	while(scanf("%c",&in)!=EOF){
		if(in == 'R'){
			rotate_r();
			print();
		}
		else if(in == 'L'){
			rotate_r();
			rotate_r();
			rotate_r();
			print();
		}
		else if(in == 'F'){
			move();
			print();
		}
	}
	#endif
	
	return 0;
}

/*
10 10 12 E
LFFRFFFRFFLL
##########
#========#
#===$==$=#
#========#
#==OOx===#
#==OOo=^=#
#==OOx===#
#========#
#========#
##########

10 10 11 N
FFRFFFRFFLL
##########
#========#
#===$==$=#
#========#
#==xox===#
#==OOO=^=#
#==OOO===#
#========#
#========#
##########


20 20 27 E
LRRFFFRFFFLFFFFLFFFFFFFFFFF
####################
#==================#
#====$======^======#
#=========$======^=#
#===^==============#
#==================#
#===$======^==$====#
#==================#
#====OOx===========#
#====OOo======$====#
#==$=OOx^==========#
#==================#
#===========^==^===#
#=========^======^=#
#^===^^============#
#============$=====#
#=====$======$$$===#
#==$===$===========#
#==========^=======#
####################

20 10 21 W
LFRFFFFFRFFFFRFFFFFFF
####################
#==================#
#====$======^======#
#=========$======^=#
#===^=xOO==========#
#=====oOO==========#
#===$=xOO==^==$====#
#==================#
#======^===========#
####################
*/
