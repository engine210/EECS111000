//
//  main.c
//  11619
//
//  Created by engine210 on 2018/10/19.
//  Copyright © 2018 engine210. All rights reserved.
//

#include <stdio.h>

float line[2][10000];
int LineNum;
int VerLine[1000];
int VerLineNum;

int SearchLine(float a, float b) {
    int i,flag;
    flag = 0;
    for(i = 0; i < LineNum; i++) {
        if(a == line[0][i] && b == line[1][i]){
            flag = 1;
            break;
        }
    }
    return flag;
}

void SetLine(float a, float b) {
    line[0][LineNum] = a;
    line[1][LineNum] = b;
}

int SearchVerLine(int a) {
    int i,flag;
    flag = 0;
    for(i = 0; i < VerLineNum; i++) {
        if(a == VerLine[i]){
            flag = 1;
            break;
        }
    }
    return flag;
}

void SetVerLine(int a) {
    VerLine[VerLineNum] = a;
}

int main(int argc, const char * argv[]) {
    
    int t,n,i,j,k;
    float m; //slope
    int point[2][110]; //point[1][i]:xi, point[1][i]:yi
    
    scanf("%d",&t);
    
    while(t > 0){
        
        //input
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d%d", &point[0][i], &point[1][i]);
        }
        
        //memset(line,0,sizeof(line));
        //memset(VerLine,0,sizeof(VerLine));
        LineNum = 0;
        VerLineNum = 0;
        
        for(i = 0; i < n - 2; i++) {
            for(j = i + 1; j < n - 1; j++) {
                if(point[0][j] == point[0][i]) {  //if this line is vertical
                    if(!SearchVerLine(point[0][j])) {
                        for(k = j + 1; k < n; k++) {
                            if(point[0][k] == point[0][j]) {
                                SetVerLine(point[0][j]);
                                //printf("x=%d, %d %d %d, verline=%d %d %d %d %d verlinenum=%d\n",point[0][j],i,j,k,VerLine[0],VerLine[1],VerLine[2],VerLine[3],VerLine[4],VerLineNum);
                                VerLineNum++;
                                break;
                            }
                        }
                    }
                }
                else { //if this line isn't vertical
                    m = (float)(point[1][j] - point[1][i]) / (float)(point[0][j] - point[0][i]);
                    if(!SearchLine(m, (float)point[1][j] - ((float)point[0][j]) * m)){
                        for(k = j + 1; k < n; k++) {
                            if((float)(point[1][k] - point[1][j]) / (float)(point[0][k] - point[0][j]) == m) {
                                    SetLine(m, (float)point[1][k] - ((float)point[0][k]) * m);
                                    //printf("y=%fx+%f, %d %d %d verlinenum=%d\n",m,(float)point[1][k] - ((float)point[0][k]) * m,i,j,k,VerLineNum);
                                    LineNum++;
                                    break;
                            }
                        }
                    }
                }
            }
        }
        
        printf("%d\n", LineNum + VerLineNum);
        t--;
    }
    
    return 0;
}

/*
11
0 0
0 3
0 4
1 1
1 2
1 3
1 4
2 3
3 1
3 2
3 3
 
11
0 0
1 1
1 2
1 3
1 4
2 3
3 1
3 2
3 3
0 3
0 4
 
9
0 0
0 1
1 1
1 0
1 -1
0 -1
-1 -1
-1 0
-1 1
*/

