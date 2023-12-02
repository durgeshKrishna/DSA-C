#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

char stack[MAX], postfix[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char c = stack[top];
    top--;
    return c;
}

int is_empty() {
    return (top == -1);
}

void display_postfix() {
    int k;
    for (k = 0; k < strlen(postfix); k++) {
        printf("%c", postfix[k]);
    }
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

void infix_to_postfix(char *expr) {
    char symbol, popped;
    int i = 0, j = 0;

    while (i < strlen(expr)) {
        symbol = expr[i];

        if (isalnum(symbol)) {
            while (isalnum(symbol)) {
                postfix[j++] = symbol;
                i++;
                symbol = expr[i];
            }
            postfix[j++] = ' ';
        } else if (symbol == '(') {
            push(symbol);
            i++;
        } else if (symbol == ')') {
            while ((popped = pop()) != '(') {
                postfix[j++] = popped;
                postfix[j++] = ' ';
            }
            i++;
        } else if (is_operator(symbol)) {
            while (!is_empty() && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(symbol);
            i++;
        }
    }

    while (!is_empty()) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }
}

int main() {
    char infix[MAX];
    printf("Enter the infix expression to convert to postfix: ");
    gets(infix);
    infix_to_postfix(infix);
    printf("Postfix expression: ");
    display_postfix();
    return 0;
}

