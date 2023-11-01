#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListtraversal(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr->next != head)
    {
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
}
struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
{
    ptr->data = data;
    
    struct Node *p = data-> next;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr-next = head;
    ptr = head;
    return head;
}
int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;
    
    head = circular_insert(head, 80);
    linkedListtraversal(head);
    return 0;
}

