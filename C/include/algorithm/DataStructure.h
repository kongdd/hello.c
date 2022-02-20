// #include "DataStructure.h"

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

/* Node: 节点*/
typedef struct Node Node;

// C has no template
struct Node {
    int Data;
    /*后继结点,负责建立队列各结点之间的联系，前一个结点的pNext指向后一个结点，形成链式队列*/
    Node *pNext;
};

/* Queue: 链式队列结构*/
typedef struct {
    Node *front; /*链式队列的队头指针，总是指向队列的头结点(出队一次，第二个结点变为头结点)*/
    Node *rear;  /*链式队列的队尾指针，入队时指向新插入结点(总是指向队列的最后一个结点)*/
    int Length;
} Queue;


/* List: 列表*/
typedef struct {
    struct Node *pHead;
    int Length;
} List;


#endif /* DATASTRUCTURE_H */
