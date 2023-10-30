#include <stdio.h>
#include <math.h>
#define t 10

int l[t];
int arr[t];

void insert(int x)
{
    int h, i, hi;
    i = 0;
    h = x % t;
    hi = h;
    while (l[hi] != -1)
    {
        i++;
        hi = (h + i) % t;
    }
    l[hi] = x;
}

void delete(int data)
{
    int i;
    for (i = 0; i < t; i++)
    {
        int index = (data + i) % t;
        if (l[index] == data)
        {
            l[index] = 0;
            printf("Deleted from index %d\n", index);
            return;
        }
    }
    printf("Element not found\n");
}

void print()
{
    int i;
    printf("INDEX\t\tVALUE\n");
    for (i = 0; i < t; i++)
    {
        printf("%d\t\t%d\n", i, l[i]);
    }
}

void search(int x)
{
    int i, h, hi;
    h = x % t;
    for (i = 0; i < t; i++)
    {
        hi = (h + i) % t;
        if (l[hi] == x)
        {
            printf("Found in index %d\n", hi);
            return;
        }
    }
    printf("Not found\n");
}

int main()
{
    int i, op, x;
    for (i = 0; i < t; i++)
    {
        l[i] = -1;
        arr[i] = -1;
    }

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Print\n5. Exit\nEnter option: ");
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
            printf("Enter value to delete: ");
            scanf("%d", &x);
            delete(x);
            break;
        case 4:
            print();
            break;
        case 5:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }
}

