#include <stdio.h>

/**
 * @references
 * 1. https://stackoverflow.com/questions/13716913/default-value-for-struct-member-in-c
 * 2. https://stackoverflow.com/questions/28778625/whats-the-difference-between-and-in-c
 */
struct Leaf_s{
    int x;
    double y;
} Leaf_default = {0, 0};
typedef struct Leaf_s Leaf;

#define LEAF(...) ((Leaf){.x = 0, .y = 0, ##__VA_ARGS__})


void init_leaf_struct(Leaf *x, Leaf *replacement) {
    x->x = replacement->x;
    x->y = replacement->y;
}

void init_leaf_dbl(Leaf* x, double replacement) {
    x->x = replacement;
    x->y = replacement;
}

Leaf leaf_mul(Leaf x, Leaf y) {
    Leaf ans;
    ans.x = x.x * y.x;
    ans.y = x.y * y.y;
    return ans;
}


int main() {
    // printf() displays the string inside quotation
    printf("Hello, World!");
    double z[5] = {};
    Leaf temp = Leaf_default;
    Leaf x = LEAF(.x = 1, .y = 2);                       // no id initialization
    Leaf y = LEAF(.x = 2, .y = 4);                 // no name initialization

    init_leaf_dbl(&x, 5);
    x = leaf_mul(x, y);
    // init_leaf_struct(x, y);
    init_leaf_struct(&x, &y);
    return 0;
}
