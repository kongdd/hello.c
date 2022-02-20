#ifndef QUEUE_H
#define QUEUE_H

#include <string.h>

#include "DataStructure.h"

void InitQueue(Queue *p);
int IsEmpty(Queue *p);
int IsRight(int *i, int *j);
void AddRear(Queue *p, int x);
int DelFront(Queue *p);
int GetFront(Queue *p, int *y);
int GetRear(Queue *p, int *y);
void Clear(Queue *p);
void display(Queue *p);

/** IMPLEMENT ---------------------------------------------------------------- */

/*创建空队列： p为队列头结点*/
void InitQueue(Queue *p) {
    // front and rear share the same address
    p->front = p->rear = (Node *)malloc(sizeof(Node));

    p->front->pNext = NULL;
    p->rear->pNext = NULL;
    p->Length = 0;
}

int IsEmpty(Queue *p) {
    return (p->Length == 0);
}

// add to tail
/*新元素入队:即链式队列的尾结点指针，指向存放新元素的新结点*/
void AddRear(Queue *p, int x) {
    /*创建新结点,并申请内存*/
    Node *temp = (Node *)malloc(sizeof(Node));
    // if (!temp) printf("temp malloc error!\n");
    temp->Data = x;
    temp->pNext = NULL; /*队列只能从队尾插入所以下一个结点初始化为NULL*/

    // ! 此处是难点
    p->rear->pNext = temp; /* 将队尾结点的后继指针指向新结点, memory divergent here */
    // p->front->pNext = temp; // not work!
    p->rear = temp;        /*将队尾结点的指针指向新结点temp,temp变为最后一个结点*/
    p->Length++;
}

// del front
int DelFront(Queue *p) {
    /*如果队列为空,则返回Error*/
    if (IsEmpty(p)) {
        printf("Error! Queue Empty!\n");
        return 0;
    }

    Node *temp = p->front->pNext; /*初始化temp为要出队的结点的指针*/
    /*如果要出队的结点为最后一个结点,使q->rear指向头结点防止出现悬空的指针*/
    if (p->front->pNext == p->rear)
        p->rear = p->front;
    p->front->pNext = temp->pNext; /*使下一个结点成为队头,如果没有下一个结点则为NULL*/
    free(temp);                    /*删除要出队的结点*/
    p->Length--;
    return 1;
}

int GetFront(Queue *p, int *y) {
    if (IsEmpty(p)) {
        printf("Queue Empty!");
        return -1;
    }
    *y = p->front->pNext->Data;
    printf("Frond : %d\n", *y);
    return 1;
}

int GetRear(Queue *p, int *y) {
    if (IsEmpty(p)) {
        printf("\tQueue Empty!");
        return -1;
    }
    *y = p->rear->Data;
    printf("Rear : %d\n", *y);
    return 1;
}

/*清空队列*/
void Clear(Queue *p) {
    Node *temp = p->front->pNext;
    while (temp) {
        p->front->pNext = temp->pNext;
        free(temp);
        temp = p->front->pNext;
    }
    p->rear = p->front;
    p->Length = 0;
    free(p);
}

void display(Queue *p) {
    Node *temp = p->front;
    if (IsEmpty(p)) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Data of Node:\n");
    printf("-----------------------\n");
    printf("\tNode:\n");
    printf("\t");
    for (int i = 1; i <= p->Length; i++)
        printf("\t-> %d", i);

    printf("\n\tData:");
    while (temp != p->rear) {
        temp = temp->pNext;
        printf("\t   %d", temp->Data);
    }
    printf("\n\t\t   Front\n");
    printf("\t");
    for (int i = 1; i <= p->Length; i++)
        printf("\t");
    printf("   Rear\n");
}

/*文本颜色设置*/
// #include "Windows.h"
// void TextColor(int c) {
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); /*根据C的值设置字体颜色*/
//}

#endif /* QUEUE_H */
