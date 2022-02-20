#include <stdio.h>
#include <stdlib.h>

/**
 * @brief algorithm_Queue
 *
 * 实现方式二：浪费一个存储空间
 * 循环队列
 *
 * @authors Kong Dongdong and Kong Bobo
 * @date 19 Feb, 2022
 */
#define MAX_LEN 8

/** second solution */
typedef struct {
    int Q[MAX_LEN];
    int Front, Rear;
} QUEUE;

/*数组下标与元素个数不对应；数组元素下标=元素个数-1*/
/*初始化队列：创建一空队列*/
void InitQueue(QUEUE *Queue) {
    Queue->Front = MAX_LEN - 1;
    Queue->Rear = MAX_LEN - 1;
}

/*队列判空*/
int IsEmpty(QUEUE *Queue) {
    return (Queue->Front == Queue->Rear);
}

/*队列判满*/
int IsFull(QUEUE *Queue) {
    return (Queue->Front == Queue->Rear + 1);
}

/*清空队列*/
void Clear(QUEUE *Queue) {
    Queue->Front = MAX_LEN - 1;
    Queue->Rear = MAX_LEN - 1;
}

/*入队操作：在队尾增加一个新元素x */
void Add(QUEUE *Queue, int y) {
    if (IsFull(Queue)) {
        printf("Queue Full!\n");
        return;
    }
    Queue->Rear = (Queue->Rear + 1) % MAX_LEN;
    Queue->Q[Queue->Rear] = y;
}

/*出队操作：删除队首元素，队首元素值存放至y中*/
void Del(QUEUE *Queue, int *y) {
    if (IsEmpty(Queue)) {
        printf("Queue Empty!\n");
        return;
    }
    Queue->Front = (Queue->Front + 1) % MAX_LEN;
    *y = Queue->Q[Queue->Front];
}

/*取队首*/
int GetFront(QUEUE *Queue, int *y) {
    if (IsEmpty(Queue)) {
        printf("\tQueue Empty!");
        return 0;
    }
    *y = Queue->Q[(Queue->Front + 1) % MAX_LEN];
    return 1;
}

/*取队尾*/
int GetRear(QUEUE *Queue, int *y) {
    if (IsEmpty(Queue)) {
        printf("\tQueue Empty!");
        return 0;
    }
    *y = Queue->Q[Queue->Rear];
    return 1;
}

/*打印循环队列：基于数组结构*/
void PrintNode(QUEUE *Queue) {
    int i;

    printf("\n\tNode:");
    for (i = 0; i < MAX_LEN; i++) {
        printf("\t %d", i);
    }

    printf("\n\tData:");
    for (i = 0; i < MAX_LEN; i++) {
        printf("\t %d", Queue->Q[i]);
    }

    printf("\n\t");
    for (i = 0; i < MAX_LEN; i++) {
        printf("\t");
        if (i == Queue->Front)
            printf("Front");
    }

    printf("\n\t");
    for (i = 0; i < MAX_LEN; i++) {
        printf("\t");
        if (i == Queue->Rear)
            printf("Rear");
    }
    printf("\n");
}

/*打印循环队列：基于队列结构*/
void PrintNode_1(QUEUE *Queue) {
    if (IsEmpty(Queue)) {
        printf("Queue Empty!");
        return;
    }
    /* printf("\nThe node in the QUEUE is:\n");*/
    printf("\n\tNode:");
    int i = (Queue->Front + 1) % MAX_LEN;
    while (i <= Queue->Rear) {
        printf("\t %d", i);
        i = (i + 1) % MAX_LEN;
    }

    printf("\n\tData:");
    i = (Queue->Front + 1) % MAX_LEN;
    while (i <= Queue->Rear) {
        printf("\t %d", Queue->Q[i]);
        i = (i + 1) % MAX_LEN;
    }
    printf("\n\t\tFront\n");

    printf("\t");
    i = (Queue->Front + 1) % MAX_LEN;
    while (i <= Queue->Rear) {
        printf("\t");
        i = (i + 1) % MAX_LEN;
    }
    printf("Rear\n");
    /* printf("That's all!");*/
}
