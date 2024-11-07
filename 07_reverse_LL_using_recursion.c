// reverse a single linklist using recursion.

#include <stdio.h>
#include <stdlib.h>

struct Snode {
    int data;
    struct Snode *next;
};

struct Snode * create_node(int data){
    struct Snode *node = (struct Snode *)malloc (sizeof(struct Snode));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Snode * reverse(struct Snode *head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    struct Snode *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void print_list(struct Snode *head){
    while (head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Snode *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);
    print_list(head);
    head = reverse(head);
    print_list(head);
    return 0;
}
