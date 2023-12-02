#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};
struct Node* Insert(struct Node* p, int key) {
    if (p == NULL) {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) {
        p->lchild = Insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Insert(p->rchild, key);
    }
    return p;
}
void findMaxforN(struct Node* root, int N) {
    struct Node* result = NULL;
    while (root != NULL) {
        if (root->data <= N) {
            result = root;
            root = root->rchild;
        } else {
            root = root->lchild;
        }
    }
    if (result == NULL) {
        printf("-1\n");
    } else {
        printf("%d\n", result->data);
    }
}
int main() {
    int N = 0;
    struct Node* root = NULL;
    printf("Enter the number of elements: ");
    int numElements;
    scanf("%d", &numElements);
    int i;
    for (i = 0; i < numElements; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = Insert(root, data);
    }
    printf("Enter the value of N: ");
    scanf("%d", &N);
    findMaxforN(root, N);
    return 0;
}

