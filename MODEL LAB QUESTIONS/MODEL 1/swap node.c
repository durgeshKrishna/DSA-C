#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct Node* pairWiseSwap(struct Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    struct Node* newHead = root->next;
    struct Node* prev = root;
    struct Node* curr = root->next->next;

    newHead->next = prev;
    while (curr != NULL && curr->next != NULL) {
        prev->next = curr->next;
        prev = curr;
        struct Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;

    return newHead;
}

void append(struct Node* head, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = data;
    node->next = NULL;

    if (head == NULL) {
        return node;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

void print(struct Node* root) {
    while (root != NULL) {
        printf("%d ", root->key);
        root = root->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i, n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        if (head == NULL) {
            head = (struct Node*)malloc(sizeof(struct Node));
            head->key = data;
            head->next = NULL;
        } else {
            append(head, data);
        }
    }

    printf("\nLinked List before: ");
    print(head);

    head = pairWiseSwap(head);

    printf("\nLinked List after pairwise swap: ");
    print(head);

    return 0;
}

