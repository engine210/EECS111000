#ifndef FUNCTION_H
#define FUNCTION_H

#include <ctype.h>
#include <string.h>
typedef struct {
	int zipcode;
	char name[15];
} Letter;

int compare(const void *a,const void *b) {
    const Letter* va = (const Letter*) a;
    const Letter* vb = (const Letter*) b;
    //return va->zipcode - vb->zipcode;
    
    if (va->zipcode > vb->zipcode) {
        return 1;
    }
    else if (va->zipcode < vb->zipcode) {
        return -1;
    }
    else {
        int a_weight = 0, b_weight = 0;
        int i = 0;
        while (va->name[i] != '\0') {
            if (isupper(va->name[i])) {
                a_weight += va->name[i] - 'A' + 2;
            }
            else {
                a_weight += va->name[i] - 'a' + 1;
            }
            i++;
        }
        i = 0;
        while (vb->name[i] != '\0') {
            if (isupper(vb->name[i])) {
                b_weight += vb->name[i] - 'A' + 2;
            }
            else {
                b_weight += vb->name[i] - 'a' + 1;
            }
            i++;
        }
        if (a_weight == b_weight) {
            return strcmp(va->name, vb->name);
        }
        else {
            return a_weight - b_weight;
        }
    }
}

#endif
