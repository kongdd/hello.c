#include <stdio.h>
#define max 5  //表示顺序表申请的空间大小

void enQueue(int *a, const int *front, int *rear, int data) {
    // int rear = *rear_addr;
    //添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if ((*rear + 1) % max == *front) {
        printf("空间已满");
        // return rear;
        return;
    }
    a[*rear % max] = data;
    (*rear)++;
    // return rear;
}

void deQueue(int *a, int *front, const int *rear) {
    // int front = *front_addr;
    //如果front==rear，表示队列为空
    if (*front == *rear % max) {
        printf("队列为空");
        // return front;
        return;
    }
    printf("out: %d \n", a[*front]);
    // front不再直接 +1，而是+1后同max进行比较，如果=max，则直接跳转到 a[0]
    // front = (front + 1) % max;
    *front = (*front + 1) % max;
    // return front;
}

int main() {
    int a[max];
    int front, rear;
    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    //入队
    enQueue(a, &front, &rear, 1);
    enQueue(a, &front, &rear, 2);
    enQueue(a, &front, &rear, 3);
    enQueue(a, &front, &rear, 4);
    //出队
    deQueue(a, &front, &rear);
    //再入队
    enQueue(a, &front, &rear, 5);
    //再出队
    deQueue(a, &front, &rear);
    //再入队
    enQueue(a, &front, &rear, 6);
    //再出队
    deQueue(a, &front, &rear);
    deQueue(a, &front, &rear);
    deQueue(a, &front, &rear);
    deQueue(a, &front, &rear);
    return 0;
}
