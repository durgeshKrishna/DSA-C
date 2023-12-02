#include <stdio.h>
#include <stdlib.h>

struct snode
{
    int data;
    struct snode *next;
};

struct snode *create(struct snode *head, int n)
{
    struct snode *node, *temp;
    printf("\nEnter the element to be inserted in the singly linked list: ");
    for (int i = 0; i < n; i++)
    {
        node = (struct snode *)malloc(sizeof(struct snode));
        
        scanf("%d", &node->data);
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            temp = node;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }

    return head;
}

struct snode *rev(struct snode *head)
{
    struct snode *curr = head, *prev = NULL, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

int main()
{
    struct snode *head = NULL, *temp, *temp2;
    int n;

    printf("Enter the number of elements to be inserted in the singly linked list: ");
    scanf("%d", &n);

    temp = create(head, n);
    temp2 = rev(temp);
    printf("\n Reversed list");
    for (int i = 0; i < n; i++)
    {
        printf(" %d - >", temp2->data);
        temp2 = temp2->next;
    }
    printf("-> NULL\n");

    return 0;
}
