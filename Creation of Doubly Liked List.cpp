#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};


void linkedListtraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("%d <-> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}

int main()
{
	
	printf("Creation Of Doubly Linked List");
	printf("\n");

	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 15;
	head->prev = NULL;
	head->next = second;
	
	second->data = 16;
	second->prev = head;
	second->next = third;
	
	third->data = 17;
	third->prev = second;
	third->next = fourth;
	
	fourth->data = 18;
	fourth->prev = third;
	fourth->next = NULL;
	
	linkedListtraversal(head);
	
	return 0;
}






