#include <iostream>
#include <string>
#include <array>

using namespace std;

typedef struct Leaf {
    double o_sunlit = 0;
    double o_shaded = 0;
    double u_sunlit = 0;
    double u_shaded = 0;

    Leaf(){};
    Leaf(double o) : o_sunlit(o), o_shaded(o), u_sunlit(o), u_shaded(o){};
    Leaf(double o, double u): o_sunlit(o), o_shaded(o), u_sunlit(u), u_shaded(u){};
    Leaf(double o_sunlit, double o_shaded, double u_sunlit, double u_shaded):
        o_sunlit(o_sunlit), o_shaded(o_shaded), u_sunlit(u_sunlit), u_shaded(u_shaded){};
    Leaf(const Leaf &l) {
        o_sunlit = l.o_sunlit;
        o_shaded = l.o_shaded;
        u_sunlit = l.u_sunlit;
        u_shaded = l.u_shaded;
    }

    void replace(const double o) {
        o_sunlit = o; o_shaded = o;
        u_sunlit = o; u_shaded = o;
    };
    void replace(const double o, const double u) {
        o_sunlit = o; o_shaded = o;
        u_sunlit = u; u_shaded = u;
    };
    void replace(const Leaf &l) {
        o_sunlit = l.o_sunlit; o_shaded = l.o_shaded;
        u_sunlit = l.u_sunlit; u_shaded = l.u_shaded;
    }
} Leaf;

// overstory, understory and ground
typedef struct Layer {
    double o = 0;
    double u = 0;
    double g = 0;

    Layer(){};
    Layer(double o) : o(o), u(o), g(o){};
    Layer(double o, double u, double g): o(o), u(u), g(g){};
    Layer(const Layer &l) {
        o = l.o; u = l.u; g = l.g;
    }

    void replace(const double o) {
        this->o = o; this->u = o; this->g = o;
    };
    void replace(const double o, const double u, const double g) {
        this->o = o; this->u = u; this->g = g;
    };
    void replace(const Layer &l) {
        o = l.o; u = l.u; g = l.g;
    }
} Layer;


void show(const Leaf &l, std::string prefix = "") {
    printf("\"%s\": \n", prefix.c_str());
    printf("> o_sunlit = %.2f, o_shaded = %.2f, u_sunlit = %.2f, u_shaded = %.2f\n", 
        l.o_sunlit, l.o_shaded, l.u_sunlit, l.u_shaded);
    printf("\n");
}
void show(const Layer &l, std::string prefix = "") {
    printf("\"%s\": \n", prefix.c_str());
    printf("> o = %.2f, u = %.2f, g = %.2f\n", l.o, l.u, l.g);
    printf("\n");
}

/** TEMPLATE for Leaf ------------------------------------------------------- */
template <class F>
Leaf apply(const Leaf &A, const Leaf &B, F f){
    return Leaf(
        f(A.o_sunlit, B.o_sunlit), 
        f(A.o_shaded, B.o_shaded), 
        f(A.u_sunlit, B.u_sunlit),
        f(A.u_shaded, B.u_shaded));
}

template <class F>
Leaf apply(const Leaf &A, const double B, F f){
    return Leaf(
        f(A.o_sunlit, B), 
        f(A.o_shaded, B), 
        f(A.u_sunlit, B),
        f(A.u_shaded, B));
}

template <class F>
Leaf apply(const double A, const Leaf &B, F f){
    return Leaf(
        f(A, B.o_sunlit), 
        f(A, B.o_shaded), 
        f(A, B.u_sunlit),
        f(A, B.u_shaded));
}
// template <class F>
// Leaf apply(const Layer &A, F f){
//     return apply(0, A, f);
// }

/** TEMPLATE for Layer ------------------------------------------------------ */
template <class F>
Layer apply(const Layer &A, const Layer &B, F f){
    return Layer(f(A.o, B.o), f(A.u, B.u), f(A.g, B.g));
}

template <class F>
Layer apply(const Layer &A, const double B, F f){
    return Layer(f(A.o, B), f(A.u, B), f(A.g, B));
}

template <class F>
Layer apply(const double A, const Layer &B, F f){
    return Layer(f(A, B.o), f(A, B.u), f(A, B.g));
}


//  OVERLOAD OPERATOR ------------------------------------------------------
template <class T, class U>
auto operator+(const T &A, const U &B){
    return apply(A, B, [](double a, double b) { return a + b; });
}

template <class T, class U>
auto operator-(const T &A, const U &B){
    return apply(A, B, [](double a, double b) { return a - b; });
}

template <class T, class U>
auto operator*(const T &A, const U &B){
    return apply(A, B, [](double a, double b) { return a * b; });
}

template <class T, class U>
auto operator/(const T &A, const U &B){
    return apply(A, B, [](double a, double b) { return a / b; });
}

template <class T>
auto operator-(const T &A){
    return apply(0, A, [](double a, double b) { return a - b; });
}
