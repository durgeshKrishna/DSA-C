#include<stdio.h>
#include<stdlib.h>
struct cnode
{
  int data;
  struct cnode *next;
};
struct cnode* head1,*head2;
struct cnode * create (struct cnode *head, int n)
{
  struct cnode *node, *temp;
  int i;
  for (i = 0; i < n; i++)
    {
      node = (struct cnode *) malloc (sizeof (struct cnode));
      printf ("\nEnter the data:");
      scanf ("\n%d", &node->data);
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
  temp->next = head;
  return head;
}
void splitlist(struct cnode* head)
{
	struct cnode* slow,*fast,*cur;
	slow=head;
	fast=head->next;
	while(fast!=head && fast->next!=head){
		slow=slow->next;
		fast=fast->next->next;
	}
	head1=head;
	head2=slow->next;
	slow->next= head1;
	cur=head2;
	while(cur->next!=head){
		cur=cur->next;
	}
	cur->next=head2;
}
void display(struct cnode* head){
	struct cnode* temp=head;
	while(temp->next!=head){
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
	printf("\n");
}
int main ()
{
  struct cnode *head = NULL, *temp;
  int temp1, n;
  printf ("\n Enter the number of elements :");
  scanf ("\n%d", &n);
  temp = create (head, n);
  splitlist(temp);
  printf("\n The Splitted list :");
  printf("\n The List 1:  ");
  display(head1);
  printf("\n The List 2: ");
  display(head2);
}
