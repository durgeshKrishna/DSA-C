
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
int a = 0, size;
struct node *getnode ()
{
  struct node *p = (struct node *) malloc (sizeof (struct node));
  ++a;
  p->data = a;
  p->next;
  return p;
}
struct node *createlist ()
{
  int val, i;
  struct node *temp, *ptr, *head = NULL;
  printf ("\n ENTER THE VALUE OF N : ");
  scanf ("%d", &val);
  size = val;
  for (i = 0; i < val; i++)
    {
      temp = getnode ();
      if (head == NULL)
	{
	  head = temp;
	  ptr = temp;
	}
      else
	{
	  ptr->next = temp;
	  ptr = temp;
	  ptr->next = head;
	}
    }
  return head;
}

void dis (struct node *head)
{
  struct node *temp = head;
  do
    {
      printf ("%d ->", temp->data);
      temp = temp->next;
    }
  while (temp != head);
}

int josephus (struct node *head, int k)
{ 
   int i;
  struct node *curr = head, *prev = NULL;
  while (curr->next != curr)
    {
      for (i = 1; i < k; i++)
	{
	  prev = curr;
	  curr = curr->next;
	}
      prev->next = curr->next;
      printf ("\n%d : KILLED", curr->data);
      free (curr);
      curr = prev->next;
    }
  return curr->data;
}

int main ()
{
  struct node *head = createlist ();
  dis (head);
  int k;
  printf ("Enter the k value: ");
  scanf ("%d", &k);
  printf ("\nStarting Josephus Problem Elimination...");
  int winner = josephus (head, k);
  printf ("\nWINNER : %d\n", winner);
  return 0;
}

