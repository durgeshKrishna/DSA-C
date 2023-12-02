#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int val;
    struct Node* next;
};

bool isPalindrome(struct Node *head) {
    struct Node *first = head;
    struct Node *sec = head;
    struct Node *cen = NULL;

    while (sec != NULL && sec->next != NULL) {
        first = first->next;
        sec = sec->next->next;
    }

    if (sec != NULL) {
        first = first->next;
        cen = first;
    } else {
        cen = first;
    }

    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *curr = cen;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    while (prev != NULL) {
        if (prev->val != head->val) // Corrected from prev->data to prev->val
            return false;
        prev = prev->next;
        head = head->next;
    }

    return true;
}

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, val;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* current = NULL;
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &val);

        struct Node* newNode = createNode(val);
        if (current == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}

