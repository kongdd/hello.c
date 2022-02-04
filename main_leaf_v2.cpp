//!g++ -std=c++17 main_leaf_v2.cpp && ./a.out
#include "leaf_v2.hpp"

int main()
{
    Leaf x(1, 2, 3, 4); // x = 1; y = 2
    auto y = Leaf(1, 2);
    
    y.replace(2); show(y);
    y.replace(2, 3); show(y);
    y.replace(Leaf(4, 3, 2, 1)); show(y);
    y.replace(x); show(y);

    // 2. Test for Leaf
    show(Leaf(1, 2) - 0.5, "Leaf(1, 2) - 0.5");
    show(Leaf(1, 2) / 0.5, "Leaf(1, 2) / 0.5");
    show(Leaf(1, 2) - Leaf(), "Leaf(1, 2) - Leaf()");
    show(Leaf(1, 2, 3, 4) - Leaf(), "Leaf(1, 2) - Leaf()");

    show(1 / (1 + x) * x -1 + x, "1 / (1 + x) * x - 1 + x");
    
    Layer layer;
    layer.replace(1);
    layer.replace(1, 2, 3);
    show(-layer);
    // 2. Test for layer
    // show(Layer(1, 2, 3) - Layer(), "Layer(1, 2, 3) - Layer()");
    return 1;
}
