#include <stdio.h>

#include <string>

/**
 * @author Dongdong Kong; 01 Jan, 2022
 * 考察知识点:
 *
 * - struct
 * - 构造函数
 * - 友元函数
 * - 运算符重载
 */

typedef struct Leaf {
    int x = 1;
    double y = 2;
    double z[5] = {};

    Leaf() {};
    Leaf(double x) : x(x), y(x){};
    Leaf(int x, double y) : x(x), y(y){};
    Leaf(const Leaf &A) {
        x = A.x;
        y = A.y;
    }

    void show(std::string prefix = "") {
        printf("%s:| x = %d, y = %f\n", prefix.c_str(), x, y);
    }

    void replace(const double A);
    void replace(const Leaf &A);
    
    template<class T, class U>
    friend Leaf operator+(const T &A, const T &B);
    friend Leaf operator+(const Leaf &A, const Leaf &B);

    template <class T, class U>
    friend Leaf operator-(const T &A, const T &B);
    friend Leaf operator-(const Leaf &A, const Leaf &B);

    template<class T, class U>
    friend Leaf operator*(const T &A, const T &B);
    friend Leaf operator*(const Leaf &A, const Leaf &B);

    template<class T, class U>
    friend Leaf operator/(const T &A, const T &B);
    friend Leaf operator/(const Leaf &A, const Leaf &B);
} Leaf;

void Leaf::replace(const Leaf &A) {
    x = A.x;
    y = A.x;
}

void Leaf::replace(const double A) {
    x = A;
    y = A;
}

template<class T, class U>
Leaf operator+(const T &A, const U &B) {
    return Leaf(A) + Leaf(B);
}
Leaf operator+(const Leaf &A, const Leaf &B) {
    return Leaf(A.x + B.x, A.y + B.y);
}

template <class T, class U>
Leaf operator-(const T &A, const U &B) {
    return Leaf(A) - Leaf(B);
}
Leaf operator-(const Leaf &A, const Leaf &B) {
    return Leaf(A.x - B.x, A.y - B.y);
}

template<class T, class U>
Leaf operator*(const T &A, const U &B) {
    return Leaf(A) * Leaf(B);
}
Leaf operator*(const Leaf &A, const Leaf &B) {
    return Leaf(A.x * B.x, A.y * B.y);
}

template<class T, class U>
Leaf operator/(const T &A, const U &B) {
    return Leaf(A) / Leaf(B);
}
Leaf operator/(const Leaf &A, const Leaf &B) {
    return Leaf(A.x / B.x, A.y / B.y);
}

/** global functions ---------------------------------------------------------*/
// C++ can implement those functions in a more elegant way
void init_leaf(Leaf &x, Leaf &replacement) {
    x.x = replacement.x;
    x.y = replacement.y;
}

void init_leaf(Leaf *x, Leaf *replacement) {
    x->x = replacement->x;
    x->y = replacement->y;
}

void init_leaf(Leaf *x, double replacement) {
    x->x = replacement;
    x->y = replacement;
}
