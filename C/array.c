#include <stdio.h>
#include <stdlib.h>

typedef double real;

/**
 * @references
 * 1. https://stackoverflow.com/questions/11656532/returning-an-array-using-c
 */
real *foo(int count) {
    real *ret = malloc(count);
    // if(!ret)
    //     return NULL;
    // for(int i = 0; i < count; ++i) 
    //     ret[i] = i;
    return ret;
}

void init(real* x, int n) {
    for (int i = 0; i < n; i++) {
        // printf("x[%d] = %f\n", i, x[i]);
        x[i] = i;
    }
}
// void show(real x[], int n); // also works
void show(real* x, int n, char* prefix) {
    printf("[%s]: ===================\n", prefix);
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}

void show2(real x[], int n) {
    printf("===================\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}

int main() {
    // printf() displays the string inside quotation
    int n = 5;

    real x[] = {1, 2, 3, 4, 5};
    char prefix[] = "hello world";
    show(x, n, prefix);
    show2(x, n);

    real *p = foo(5);
    // show(p, n);
    init(p, n);
    show2(p, n);
    
    if(p) {
        free(p);
    }
    return 0;
}
