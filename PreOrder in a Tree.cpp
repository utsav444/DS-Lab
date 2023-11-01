#include <stdio.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *CreateNode(int data){
	struct Node *n;
	n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

void  InOrder(struct Node *root){
	if(root != NULL){
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}





int main()
{
	struct Node *p = CreateNode(2);
	struct Node *p1 = CreateNode(1);
	struct Node *p2 = CreateNode(4);
	struct Node *p3 = CreateNode(6);
	struct Node *p4 = CreateNode(3);
	
	p->left = p1;
	p->right = p2;
	p2->left = p4;
	p2->right = p3;
	
	InOrder(p);
	return 0;
}
