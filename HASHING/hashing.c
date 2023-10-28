#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

#define CAPACITY 10

int size = 0;
struct node *arr[CAPACITY];
struct node* p;

int hashFunction(int data)
{
  return (data % CAPACITY);
}

void insert(int data)
{
  int index = hashFunction(data);
  struct node *newNode = (struct node *) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (arr[index] == NULL)
  {
    arr[index] = newNode;
  }
  else
  {
    p = arr[index];
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = newNode;
  }
  size++;
}

void delete(int data)
{
  int index = hashFunction(data);
  if (arr[index] == NULL)
  {
    printf("No Elements at index\n");
  }
  else
  {
    p = arr[index];
    if (p->next == NULL && p->data == data)
    {
      free(p);
      arr[index] = NULL;
      p = p->next;
    }
    else
    {
      struct node *prev = NULL;
      while (p != NULL)
      {
        if (p->data == data)
        {
          prev->next = p->next;
          free(p);
        }
        prev = p;
        p = p->next;
      }
    }
  }
  size--;
}

void print()
{
	 int i;
  for (i = 0; i < CAPACITY; i++)
  {
    if (arr[i] != NULL)
    {
      printf("Index:%d\n", i);
      for (p = arr[i]; p != NULL; p = p->next)
      {
        printf("%d->", p->data);
      }
      printf("\n");
    }
  }
}

int main()
{
  int choice, data;
  do
  {
    printf("\nHash Table Operations - Open Hashing:\n1) Insert\n2) Delete"
           "\n3) Display\n4) Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element to be inserted: ");
      scanf("%d", &data);
      insert(data);
      break;
    case 2:
      printf("Enter the element to be deleted: ");
      scanf("%d", &data);
      delete(data);
      break;
    case 3:
      print();
      break;
    }
  } while (choice != 4);
  return 0;
}

