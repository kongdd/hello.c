#include <stdio.h>
#include <stdlib.h>

// - `栈`: 后进先出（先进后出）
// - `队列`: 先进先出

//链表中的节点结构
typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

// stack为当前的链栈，a表示入栈元素，插入首部
Stack* push(Stack* p, int a) {
    //创建存储新元素的节点
    Stack* line = (Stack*)malloc(sizeof(Stack));
    line->data = a;
    //新节点与头节点建立逻辑关系
    line->next = p;
    //更新头指针的指向
    p = line; // address can't update
    return p; // must return
}

//栈顶元素出链栈的实现函数，吐出首部
Stack* pop(Stack* stack) {
    if (stack) {
        //声明一个新指针指向栈顶节点
        Stack* p = stack;
        //更新头指针
        stack = stack->next;
        printf("出栈元素：%d ", p->data);
        if (stack) {
            printf("新栈顶元素：%d\n", stack->data);
        } else {
            printf("栈已空\n");
        }
        free(p);
    } else {
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}

void display(Stack* p) {
    Stack* temp = p;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* p = NULL;
    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    p = push(p, 4);
    push2(p, 5);
    display(p);

    p = pop(p);
    p = pop(p);
    p = pop(p);
    display(p);

    p = pop(p);
    p = pop(p);
    return 0;
}
