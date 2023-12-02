#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct create
{
    int data;
    struct create* next;
};

int i1 = 0;
struct create* new1 = NULL;
struct create* create(struct create* head, int n)
{
    struct create* node, * temp;
    int i;
    for ( i = 0; i < n; i++)
    {
        node = (struct create*)malloc(sizeof(struct create));
        printf("\n Enter the data to be added in the linked list: ");
        scanf("%d", &node->data);
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            i1++;
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

struct create* mergetwo(struct create* l1, struct create* l2)
{
    struct create temp;
    struct create* run = &temp;
    temp.next = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            run->next = l1;
            l1 = l1->next;
        }
        else
        {
            run->next = l2;
            l2 = l2->next;
        }
        run = run->next;
    }
    if (l1 != NULL)
        run->next = l1;
    else
        run->next = l2;
    return temp.next;
}

struct create* mergesort(struct create* list[], int k)
{
    if (k == 0)
        return NULL;
    int b = 1;
    while (b < k)
    {
    	int i;
        for (i = 0; i < k - b; i += b * 2)
        {
            list[i] = mergetwo(list[i], list[i + b]);
        }
        b *= 2;
    }
    return list[0];
}

int main()
{
    int k, n,i;
    printf("\n Enter the number of linked lists to be created: ");
    scanf("%d", &k);
    struct create* head, * temp[k], * mergelist, * temp1[k];
    for (i = 0; i < k; i++)
    {
        printf("\n Enter the number of nodes to be inserted in linked list %d: ", i + 1);
        scanf("%d", &n);
        head = NULL;
        temp[i] = create(head, n);
        temp1[i] = temp[i];
    }
    printf("\n Entered linked lists in the array list:");
    for (i = 0; i < k; i++)
    {
        printf("\n Linked List %d:", i + 1);
        while (temp1[i] != NULL)
        {
            printf(" %d", temp1[i]->data);
            temp1[i] = temp1[i]->next;
        }
    }
    mergelist = mergesort(temp, k);
    printf("\n\n Merged linked list data: ");
    while (mergelist != NULL)
    {
        printf("%d ", mergelist->data);
        mergelist = mergelist->next;
    }
}

