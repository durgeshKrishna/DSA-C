#include <stdio.h>
#include <limits.h>
#define capacity 10
int size = 0;
int arr[capacity];
void initializeArray ()
{
	int i;
  for ( i = 0; i < capacity; i++)
    {
      arr[i] = INT_MIN;
    }
}

int hashFunction (int data, int i)
{
  return ((data + i) % capacity);
}
void insert (int data)
{
  int index;
  int i = 0;
  do
    {
      index = hashFunction (data, i++);
    }
  while (arr[index] != INT_MIN);
  arr[index] = data;
  size++;
}
void delete (int data)
{
  int index;
  int i = 0;
  do
    {
      index = hashFunction (data, i++);
    }
  while (arr[index] != data);
  arr[index] = INT_MIN;
  size--;
}
void print ()
{
	
	int i;
  for ( i = 0; i < capacity; i++)
    {
      if (arr[i] != INT_MIN)
	printf ("key:%d - value:%d \n", i, arr[i]);
    }
}

int main ()
{
  int choice, data;
  initializeArray ();
  do
    {
      printf
	("\nHash Table Operations - Closed Hashing:\n1) Insert\n2) Delete"
	 "\n3) Display\n4) Exit\nEnter your choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter the element to be inserted: ");
	  scanf ("%d", &data);
	  insert (data);
	  break;
	case 2:
	  printf ("Enter the element to be deleted: ");
	  scanf ("%d", &data);
	  delete (data);
	  break;
	case 3:
	  print ();
	  break;
	}
    }
  while (choice != 4);
  return 0;
}

