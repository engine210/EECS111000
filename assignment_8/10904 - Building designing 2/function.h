#ifndef FUNCTION_H
#define FUNCTION_H


#define RED 0
#define BLUE 1
typedef struct {
    char color;
    unsigned int size;
} Floor;

int compare(const void *a, const void *b) {
    const Floor* va = (const Floor*) a;
    const Floor* vb = (const Floor*) b;
    return vb->size - va->size;
}

// Modify the design function
int design(int floorNum, Floor floorArr[]) {
    int height, color;
    int idx;
    int idx_pre;
    
    //sorting the floor from the largest size to the smallest
    qsort(floorArr, floorNum, sizeof(Floor), compare);
    
    height = 1;
    color = (floorArr[0].color == 'B') ? BLUE : RED;
    idx_pre = 0; //the previous picked floor
    /*
    //test for sorting
    for (idx = 0; idx < floorNum; idx++) {
        printf("%c %d\n", floorArr[idx].color, floorArr[idx].size);
    }
    */
    for (idx = 1; idx < floorNum; idx++) {
        if (color == BLUE && floorArr[idx].color == 'R' && (floorArr[idx_pre].size + floorArr[idx].size) % 2) {
            height++;
            idx_pre = idx;
            color = RED;
            //printf("%c %d\n", floorArr[idx].color, floorArr[idx].size);
        }
        else if (color == RED && floorArr[idx].color == 'B' && (floorArr[idx_pre].size + floorArr[idx].size) % 2) {
            height++;
            idx_pre = idx;
            color = BLUE;
            //printf("%c %d\n", floorArr[idx].color, floorArr[idx].size);
        }
    }
    return height;
}
#endif
