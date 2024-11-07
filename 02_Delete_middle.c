// Ques:Delete the middle element from the link list if the length of the link list is odd. If the length of the link list is even then delete the first middle element.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void deleteMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast ==NULL){
        prev->data = slow->data;
        prev->next = slow->next;
    }else{
        prev->next = slow->next;
    }
    free(slow);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;


    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    printList(head);
    printf("\n");

    deleteMiddle(head);

    printList(head);
    printf("\n");

    return 0;
}
