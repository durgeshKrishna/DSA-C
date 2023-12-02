#include<stdio.h>
#include<stdlib.h>
struct cnode
{
	int data;
	struct cnode *next;
};
struct cnode *create(struct cnode *head)
{
	struct cnode *node,*temp;
	int n;
	printf("\n enter the number of the node to be inserted in circular link list:");
	scanf("\n%d",&n);
	for(int i=0;i<n;i++)
	{
		node=(struct cnode*)malloc(sizeof(struct cnode));
		printf("\n enter the data for the circular link list:");
		scanf("\n%d",&node->data);
		node->next=NULL;
		if(head==NULL)
		{
			head=node;
			temp=node;	
		}
		else
		{
			temp->next=node;
			temp=temp->next;
		}
	}
	temp->next=head;
	return head;
}
int josephus(struct cnode *head,int k)
{
	struct cnode *prev,*curr,*temp;
	curr=head;
	if(k==0)
	{
		while(curr->next!=curr)
		{
			temp=curr->next;
			curr->data=curr->next->data;
			curr->next=curr->next->next;
			free(temp);
		}
	}
	else
	{
		while(curr->next!=curr)
		{
		for(int i=1;i<=k;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		printf("\n the kth person killed by game:%d",curr->data);
		free(curr);
		curr=prev->next;
		}
	}
	
	return curr->data;
}
int main()
{
	struct cnode *head=NULL,*temp;
	int temp1,k;
	temp=create(head);
	printf("\n enter the skip value to play the josephus game:");
	scanf("\n%d",&k);
	temp1=josephus(temp,k);
	printf("\n the WINNER of the JOSEPHUS GAME :%d",temp1);
}