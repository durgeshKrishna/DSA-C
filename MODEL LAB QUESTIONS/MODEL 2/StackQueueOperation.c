#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
int stack_size, queue_size, top = -1, front = -1, rear = -1;
bool isEmptyStack() {
    return top == -1;
}
bool isEmptyQueue() {
    return (front == -1 && rear == -1);
}
int Pop(int stack[]) {
    if (isEmptyStack())
        return 0;
    else
        return stack[top--];
}
int Dequeue(int queue[]) {
    int deleted_element;
    if (isEmptyQueue())
        return 0;
    else if (front == rear) {
        deleted_element = queue[front];
        rear = -1;
        front = -1;
    } else
        deleted_element = queue[front++];
    return deleted_element;
}
void Push(int stack[], int element) {
    if (top == stack_size - 1)
        printf("\nStack Overflow!..\n");
    else
        stack[++top] = element;
}
void Enqueue(int queue[], int element) {
    if (isEmptyQueue()) {
        front++;
        queue[++rear] = element;
    } else if (front == rear + 1) {
        printf("\nQueue Overflow!..\n");
    } else {
        queue[++rear] = element;
    }
}
void performOperation(int stack[], int queue[], char operation) {
    int num1, num2;
    while (!isEmptyStack() || !isEmptyQueue()) {
        num1 = Pop(stack);
        num2 = Dequeue(queue);
        switch (operation) {
            case '+':
                printf("%d ", num1 + num2);
                break;
            case '-':
                printf("%d ", num1 - num2);
                break;
            case '*':
                printf("%d ", num1 * num2);
                break;
            case '/':
                if (num2 != 0) {
                    printf("%d ", num1 / num2);
                } else {
                    printf("Division by zero is not allowed. ");
                }
                break;
            default:
                printf("Invalid operator.");
                break;
        }
    }
}

int main() {
    int element;
    char operator;

    printf("\nEnter Stack Size and Queue Size : ");
    scanf("%d %d", &stack_size, &queue_size);
    int i;
    int stack[stack_size];
    int queue[queue_size];

    printf("Enter Stack Elements : ");
    for (i = 0; i < stack_size; i++) {
        scanf("%d", &element);
        Push(stack, element);
    }

    printf("Enter Queue Elements : ");
    for (i = 0; i < queue_size; i++) {
        scanf("%d", &element);
        Enqueue(queue, element);
    }

    printf("\nEnter Operator (+, -, *, /) : ");
    fflush(stdin);
    scanf(" %c", &operator);

    performOperation(stack, queue, operator);

    return 0;
}


