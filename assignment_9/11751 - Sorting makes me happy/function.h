#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct {
	int value;
	char str[30];
	float x;
} MyData;

int compare_function(const void* a, const void* b) {
    const MyData** va = (const MyData**) a;
    const MyData** vb = (const MyData**) b;
    
    if ((*va)->value > (*vb)->value) {
        return 1;
    }
    else if((*va)->value < (*vb)->value) {
        return -1;
    }
    else {
        if (strcmp((*va)->str, (*vb)->str) > 0) {
            return 1;
        }
        else if(strcmp((*va)->str, (*vb)->str) < 0) {
            return -1;
        }
        else {
            if ((*va)->x > (*vb)->x) {
                return 1;
            }
            else if((*va)->x < (*vb)->x) {
                return -1;
            }
            else {
                return 0;
            }
        }
        
    }
}

#endif
