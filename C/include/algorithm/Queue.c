#include "Queue.h"


int main() {
    Queue *p = (Queue *)malloc(sizeof(Queue)); 
    InitQueue(p);
    // if (IsEmpty(p)) printf("Initialized!\n");
    int N = 4;
    for (int i = 0; i < N; i++) {
        AddRear(p, i); // add to 
    }
    display(p);

    int y;
    GetFront(p, &y);
    GetRear(p, &y);

    for (int i = 0; i < 2; i++) {
        DelFront(p); 
    }

    display(p);
    GetFront(p, &y);
    GetRear(p, &y);

    Clear(p);
    
    return 0;
}
