#include <stdio.h>

/**
 * @references
 * 1. https://stackoverflow.com/questions/13716913/default-value-for-struct-member-in-c
 * 2. https://stackoverflow.com/questions/28778625/whats-the-difference-between-and-in-c
 */

/** first solution */
// struct Leaf_s {
//     int x;
//     double y;
// } Leaf_default = {0, 0};
// typedef struct Leaf_s Leaf;

/** second solution */
typedef struct {
    int x;
    double y;
} Leaf;
Leaf Leaf_default = {0, 0};


#define LEAF(...) ((Leaf){.x = 0, .y = 0, ##__VA_ARGS__})

// void init_leaf_struct(Leaf x[], Leaf replacement[]);
// void init_leaf_struct2(Leaf *x, Leaf *replacement); // equal to the above
void
init_leaf_struct(Leaf x[], Leaf replacement[]) {
    x->x = replacement->x;
    x->y = replacement->y;
}

void init_leaf_struct2(Leaf *x, Leaf *replacement) {
    x->x = replacement->x;
    x->y = replacement->y;
}

/** Note that C has no that style */
// void init_leaf_struct_v3(Leaf *x, Leaf &replacement) {
//     x->x = replacement.x;
//     x->y = replacement.y;
// }

void init_leaf_dbl(Leaf *x, double replacement) {
    x->x = replacement;
    x->y = replacement;
}

Leaf leaf_mul(Leaf x, Leaf y) {
    Leaf ans;
    ans.x = x.x * y.x;
    ans.y = x.y * y.y;
    return ans;
}
