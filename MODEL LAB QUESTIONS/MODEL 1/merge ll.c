#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->val > l2->val) {
        struct ListNode* temp = l1;
        l1 = l2;
        l2 = temp;
    }

    struct ListNode* res = l1;

    while (l1 != NULL && l2 != NULL)
  {
        struct ListNode* temp = NULL;

        while (l1 != NULL && l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        }

        temp->next = l2;
        struct ListNode* temp_swap = l1;
        l1 = l2;
        l2 = temp_swap;
    }

    return res;
}

int main() {
    int n1;
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);

    struct ListNode* l1 = NULL;
    struct ListNode* prev1 = NULL;
     int i;
    for ( i = 0; i < n1; i++) {
        int val;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;

        if (l1 == NULL) {
            l1 = newNode;
        } else {
            prev1->next = newNode;
        }

        prev1 = newNode;
    }
    int n2;
    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);

    struct ListNode* l2 = NULL;
    struct ListNode* prev2 = NULL;

    for (i = 0; i < n2; i++) {
        int val;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;

        if (l2 == NULL) {
            l2 = newNode;
        } else {
            prev2->next = newNode;
        }

        prev2 = newNode;
    }

    struct ListNode* mergedList = mergeTwoLists(l1, l2);
    printf("Merged list: ");
    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    printf("\n");

   
    return 0;
}
