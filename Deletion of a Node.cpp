#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListtraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* delete_beg(struct Node* head) {
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* delete_index(struct Node* head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0; i<index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node* delete_end(struct Node* head) {
    struct Node* p = head;
    struct Node *q = head->next;
    
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
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
    fourth->next = NULL;

    head = delete_index(head);
    linkedListtraversal(head);

    return 0;
}

