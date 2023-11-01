#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

void linkedListtraversal(struct Node *ptr)
{
	while(ptr !=NULL)
	{
		printf("%d -> ", ptr -> data);
		ptr = ptr -> next;
	}
	printf("NULL");
}


int main()
{
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	head = (struct Node *) malloc (sizeof(struct Node));
	second = (struct Node *) malloc (sizeof(struct Node));
	third = (struct Node *) malloc (sizeof(struct Node));
	fourth = (struct Node *) malloc (sizeof(struct Node));
	
	head -> data = 10;
	head -> next = second;
	
	second -> data = 20;
	second-> next = third;
	
	third -> data = 30;
	third -> next = fourth;
	
	fourth -> data = 40;
	fourth -> next = NULL;
	
	linkedListtraversal(head);	
	
	return 0;
}








