#include <stdio.h>
#include <stdlib.h>
#define t 11

struct node
{
    int data;
    struct node *next;
};

struct node *chain[t];

void insert(int x)
{
    int h;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    h = x % t;
    if (chain[h] == NULL)
    {
        chain[h] = newnode;
    }
    else
    {
        struct node *temp;
        temp = chain[h];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print()
{
    int i;
    for (i = 0; i < t; i++)
    {
        struct node *temp = chain[i];
        printf("Chain[%d]: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void search(int x)
{
    int h;
    h = x % t;
    struct node *temp = chain[h];
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

int main()
{
    int i, op, x;
    for (i = 0; i < t; i++)
    {
        chain[i] = NULL;
    }

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Print\n4. Exit\nEnter option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &x);
            search(x);
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

