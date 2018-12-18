#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;

int compare_Grade_ascend(const void *a, const void *b) {
    const Grade* ga = (const Grade*) a;
    const Grade* gb = (const Grade*) b;
    if (ga->total > gb->total) {
        return 1;
    }
    else if (ga->total < gb->total) {
        return -1;
    }
    else {
        if (ga->Chinese > gb->Chinese) {
            return 1;
        }
        else if (ga->Chinese < gb->Chinese) {
            return -1;
        }
        else {
            if (ga->English > gb->English) {
                return 1;
            }
            else if (ga->English < gb->English) {
                return -1;
            }
            else {
                if (ga->math > gb->math) {
                    return 1;
                }
                else if (ga->math < gb->math) {
                    return -1;
                }
                else {
                    if (ga->science > gb->science) {
                        return 1;
                    }
                    else if (ga->science < gb->science) {
                        return -1;
                    }
                    else {
                        if (ga->ID > gb->ID) {
                            return 1;
                        }
                        else if (ga->ID < gb->ID) {
                            return -1;
                        }
                        else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

int compare_Grade_descend(const void *a, const void *b) {
    const Grade* ga = (const Grade*) a;
    const Grade* gb = (const Grade*) b;
    if (ga->total < gb->total) {
        return 1;
    }
    else if (ga->total > gb->total) {
        return -1;
    }
    else {
        if (ga->Chinese < gb->Chinese) {
            return 1;
        }
        else if (ga->Chinese > gb->Chinese) {
            return -1;
        }
        else {
            if (ga->English < gb->English) {
                return 1;
            }
            else if (ga->English > gb->English) {
                return -1;
            }
            else {
                if (ga->math < gb->math) {
                    return 1;
                }
                else if (ga->math > gb->math) {
                    return -1;
                }
                else {
                    if (ga->science < gb->science) {
                        return 1;
                    }
                    else if (ga->science > gb->science) {
                        return -1;
                    }
                    else {
                        if (ga->ID > gb->ID) {
                            return 1;
                        }
                        else if (ga->ID < gb->ID) {
                            return -1;
                        }
                        else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

void sortGrade(Grade *gList, int n, char *order) {
    int i;
    for (i = 0; i < n; i++) {
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    }
    if (order[0] == 'a') {
        qsort(gList, n, sizeof(Grade), compare_Grade_ascend);
    }
    else {
        qsort(gList, n, sizeof(Grade), compare_Grade_descend);
    }
}

#endif
