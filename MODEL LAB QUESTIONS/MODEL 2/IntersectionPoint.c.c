#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *create(int n)
{
    struct Node *head = NULL, *temp = NULL, *node = NULL;
     int i;
    for ( i = 0; i < n; i++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the element to add it: ");
        scanf("%d", &node->data);
        node->link = NULL;

        if (head == NULL)
        {
            head = node;
            temp = node;
        }
        else
        {
            temp->link = node;
            temp = temp->link;
        }
    }
    return head;
}

int intersection(struct Node *head1, struct Node *head2)
{
    struct Node *c1 = head1, *c2 = head2;

    while (c1 != NULL)
    {
        c2 = head2; // Reset c2 for each iteration of c1
        while (c2 != NULL)
        {
            if (c1 == c2)
            {
                return c1->data;
            }
            c2 = c2->link;
        }
        c1 = c1->link;
    }

    return 0;
}

int main()
{
    int n, n1, result, n3;
    struct Node *head1 = NULL, *head2 = NULL, *commonNode = NULL;

    printf("\n Enter the number of nodes for the first linked list: ");
    scanf("%d", &n);
    head1 = create(n);

    printf("\n Enter the number of nodes for the second linked list: ");
    scanf("%d", &n1);
    head2 = create(n1);

    printf("\n Enter the number of nodes for the common linked list: ");
    scanf("%d", &n3);
    commonNode = create(n3);

    struct Node *temp = head1;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = commonNode;

   struct Node *temp1 = head2;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = commonNode;
    result= intersection(head1, head2);
    if (result)
    {
    	printf("\n The intersection point is: %d", result);
    }
    else
    {
        printf("\n No such intersection point exists");
    }
}

