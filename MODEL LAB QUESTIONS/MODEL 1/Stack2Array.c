#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int arr[MAX_SIZE];
int top1 = -1;
int top2 = MAX_SIZE;
void push1(int x) {
    if (top1 < top2 - 1) {
        top1++;
        arr[top1] = x;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}
void push2(int x) {
    if (top1 < top2 - 1) {
        top2--;
        arr[top2] = x;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}
int pop1() {
    if (top1 >= 0) {
        int x = arr[top1];
        top1--;
        return x;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}
int pop2() {
    if (top2 < MAX_SIZE) {
        int x = arr[top2];
        top2++;
        return x;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}
int main() {
    int choice,data;
    
  while(1){ 
     printf("\n1.PUSH1 \n2.PUSH2 \n3.POP1   \n4.POP2 \n");
    scanf("%d",&choice);
    switch(choice)
    {
   
case 1:
    printf("\n DATA PUSH 1 :");
    scanf("%d",&data);
    push1(data);
    break;
case 2:
    printf("\n DATA PUSH 2 :");
    scanf("%d",&data);
    push2(data);
    break;
case 3:
    printf("\n THE POPPED ELEMENT FROM THE STACK1 %d",pop1());
    break;
case 4:
    printf("\n THE POPPED ELEMENT FROM THE STACK2 %d",pop2());
    break;
default:
    exit(1);
    break;


}}
    return 0;
}