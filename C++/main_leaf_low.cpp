#include <stdio.h>
#include "leaf_low.hpp"

/**
 * @references
 * 1. https://stackoverflow.com/questions/13716913/default-value-for-struct-member-in-c
 * 2. https://stackoverflow.com/questions/28778625/whats-the-difference-between-and-in-c
 */

//  Leaf_default = {0, 0};
// typedef struct Leaf_s Leaf;

// #define LEAF(...) ((Leaf){.x = 0, .y = 0, ##__VA_ARGS__})
int main() {
    // printf() displays the string inside quotation
    printf("Hello, World!\n");
    // Leaf temp = Leaf_default;
    Leaf x;  // = LEAF(.x = 1, .y = 2);  // no id initialization
    Leaf y(x);  // = LEAF(.x = 2, .y = 4);  // no name initialization
    
    x.show("Leaf()");
    x = Leaf(1);
    x.show("Leaf(1)");

    Leaf r1 = x + y;
    // Leaf r2 = x - y;
    // Leaf r3 = x * y;
    // Leaf r4 = x / y;

    double a = 1.2;
    Leaf r = 1 / (1 + x) * x - 1 + x;
    r.show("1 / (1 + x) * x - 1 + x");
    Leaf z1 = a + x;
    Leaf z12 = x + a;

    z1.show();
    z12.show();
    // Leaf z2 = a - x;
    // Leaf z3 = a * x;
    // Leaf z4 = a / x;

    x.replace(10);
    x.replace(y);
    // init_leaf(&x, 5);
    x.show();
    // x = leaf_mul(x, y);
    // init_leaf(x, y);
    // init_leaf(&x, &y); // init_leaf(Leaf *x, Leaf *replacement)
    init_leaf(x, y);  // init_leaf(Leaf &x, Leaf &replacement)
    return 0;
}
