#include <stdio.h>

// 栈：先进先出

//元素elem进栈
void push(int* a, int* top, int elem) {
    (*top)++;  // *top = *top + 1;
    a[*top] = elem;
    // return top;
}

//数据元素出栈
void pop(int* a, int* top) {
    if (*top == -1) {
        printf("空栈");
        return;
    }
    printf("弹栈元素：%d\n", a[*top]);
    (*top)--;
    // return top;
}

int main() {
    int a[100];
    int top = -1;
    push(a, &top, 1);
    push(a, &top, 2);
    push(a, &top, 3);
    push(a, &top, 4);

    pop(a, &top);
    pop(a, &top);
    pop(a, &top);
    pop(a, &top);
    pop(a, &top);
    return 0;
}
