#include <stdio.h>
#include <math.h>
#define t 11
#define r 7
int l[t];

void insert(int x)
{
    int h, i, hi, f, h2;
    i = 0;
    h = x % t;
    h2 = r - (x % r);
    f = i * h2;
    hi = (h + f) % t;
    if (l[hi] == 0)
    {
        l[h] = x;
    }
    else
    {
        while (l[hi] != 0)
        {
            i++;
            h2 = r - (x % r);
            f = i * h2;
            hi = (h + f) % t;
        }
        l[hi] = x;
    }
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
    int i, h, hi, h2, f;
    h = x % t;
    for (i = 0; i < t; i++)
    {
        h2 = r - (x % r);
        f = i * h2;
        hi = (h + f) % t;
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
        l[i] = 0;
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
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

