#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertFront(struct Node **head, int element) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = element;
    node->next = *head;
    *head = node;
}

struct Node *selfAdjust(struct Node *head, int key) {
    struct Node *prev = NULL;
    struct Node *current = head;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
            current->next = head;
            head = current;
        }
    }

    return head;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("\nElement in the linked list: %d", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, element, key;
    while (1) {
        printf("\n1 -> Insert at Front\n2 -> Search and Self-Adjust\n3 -> Print List\n4 -> Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the element to be inserted at the front: ");
                scanf("%d", &element);
                insertFront(&head, element);
                break;
            case 2:
                printf("\nEnter the element to be searched and self-adjusted: ");
                scanf("%d", &key);
                head = selfAdjust(head, key);
                break;
            case 3:
                printf("\nLinked List Contents:\n");
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option\n");
        }
    }
    return 0;
}

