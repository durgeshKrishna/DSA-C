#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front,*rear;
void insert()
{
    struct Node *temp;
    int item;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        temp->data = item;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
        }
    }
}
void delete_element()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        temp = front;
        printf("\n Deleted element -->  %d",temp->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct Node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\n THE ELEMENTS IN THE QUEUE");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Display the queue\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_element();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice\n");
        }
    }
    return 0;
}


