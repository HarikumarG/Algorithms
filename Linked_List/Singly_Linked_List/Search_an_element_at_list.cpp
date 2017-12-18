#include<iostream>
#include<stdlib.h>
using namespace std;
//declaring of structure
struct node
{
	int data;
	struct node *next;
};
//searching a element in a list (iterative search)
void search(struct node *head_f)
{
	int element=5,flag=1;
	while(head_f!=NULL)
	{
		if(head_f->data==element)
		{
			cout<<"\nElement is found";
			flag=0;
			break;
		}
		else
		{
			head_f=head_f->next;
		}
	}
	if (flag==1)
	{
		cout<<"\nThe element is not found";
	}
}
//Recursive search
int search_R(struct node *head, int x)
{
    // Base case
    if (head == NULL)
        return 0;
     
    // If key is present in current node, return true
    if (head->data == x)
        return 1;
 
    // Recur for remaining list
    return search_R(head->next, x);
}
void push(struct node **head_r,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head_r);
	(*head_r)=newnode;
}
int main()
{
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	search(head); // function is called here
	search_R(head,5)?cout<<"YES":cout<<"NO"; //For recursive call 
	//using ternary operator
	return 0;
}