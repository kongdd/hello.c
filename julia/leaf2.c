#include <stdio.h>

/**
 * @references
 * 1. https://stackoverflow.com/questions/13716913/default-value-for-struct-member-in-c
 * 2. https://stackoverflow.com/questions/28778625/whats-the-difference-between-and-in-c
 */

/** second solution */
typedef struct {
    double x;
    double y[5];
    double z[5];
} Leaf;

void init_leaf_struct(Leaf *l) {
  l->x = 1.0;
  for (int i = 0; i < 5; i++) {
    l->y[i] = 2.0;
    l->z[i] = 3.0;
  }
}

void set_2th_value(Leaf *l, double value) {
  l->y[1] = value;
}

void show(Leaf *l) {
  printf("x = %.2f\n", l->x);
  for (int i = 0; i < 5; i++) {
    printf("y[%i] = %.2f\n", i, l->y[i]);
    printf("z[%i] = %.2f\n", i, l->z[i]);
  }
}

// also
void hello() {
  printf("Hello world!\n");
}
