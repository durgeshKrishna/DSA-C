#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* push(struct Node* head, int data)
{
    struct Node* node = newNode(data);
    node->next = head;
    return node;
}

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d ", ptr->data);
        printf("-> ");
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}

struct Node* reverse(struct Node* head)
{
    struct Node* out = NULL;
    struct Node* current = head;

    while (current)
    {
        struct Node* next = current->next;
        current->next = out;
        out = current;
        current = next;
    }

    return out;
}

struct Node* add(struct Node* X, struct Node* Y)
{
    struct Node* result = NULL;
    struct Node* prevNode = NULL;
    int carry = 0;

    while (X || Y)
    {
        int sum = 0;
        if (X) {
            sum += X->data;
            X = X->next;
        }
        if (Y) {
            sum += Y->data;
            Y = Y->next;
        }
        sum += carry;

        carry = sum / 10;
        sum = sum % 10;

        result = push(result, sum);
    }

    if (carry != 0) {
        result = push(result, carry);
    }

    return result;
}

struct Node* addLists()
{
    int x, y;

    printf("Enter the first number: ");
    scanf("%d", &x);

    printf("Enter the second number: ");
    scanf("%d", &y);

    struct Node* X = NULL;
    while (x)
    {
        X = push(X, x % 10);
        x = x / 10;
    }

    struct Node* Y = NULL;
    while (y)
    {
        Y = push(Y, y % 10);
        y = y / 10;
    }
    printf("\n THE FIRST LINKED LIST \n");
    printList(X);
    printf("\n THE SECOND LINKED LIST \n");
	printList(Y);
    

    struct Node* result = add(X, Y);
    return result;
}

int main(void)
{
    struct Node* result = addLists();
    printf("\n THE ADDITION OF THE TWO LIST  \n");
    printList(result);

    return 0;
}

