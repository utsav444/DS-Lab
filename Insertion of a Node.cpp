#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

struct Node *insert_beg(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 16;
    third->next = fourth;

    fourth->data = 22;
    fourth->next = NULL;

    printf("Insertion at Beginning : ");
    head = insert_beg(head, 60);  // Update the head with the new head returned by insert_beg
    linkedListTraversal(head);

    return 0;
}

