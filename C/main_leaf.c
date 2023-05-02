#include "leaf.h"

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
    init_leaf_struct2(&x, &y);

    return 0;
}
