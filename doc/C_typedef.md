
```C
// solution 1; the best
typedef struct Node Node;
struct Node {
    int value;
    Node *next;
    Node *prev;
};

// solution2
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;
```
