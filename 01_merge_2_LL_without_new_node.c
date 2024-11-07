// Merge a linked list (Given the 2 sorted linked list l1 &l2 write a program to merge the  linked list and then sort that linked list Note: Do not create any new link list). 
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
struct Snode * murge(struct Snode *l1,struct Snode *l2){
    struct Snode *head = NULL;
    struct Snode *tail = NULL;
    while (l1 != NULL && l2 != NULL){
        if (l1->data < l2->data){
            if (head == NULL){
                head = l1;
                tail = l1;
            }else{
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }else{
            if (head == NULL){
                head = l2;
                tail = l2;
            }else{
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }
    }
    if (l1 != NULL){
        tail->next = l1;
    }
    if (l2 != NULL){
        tail->next = l2;
    }
    return head;

}

void print_list(struct Snode *head){
    while (head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Snode *l1 = create_node(1);
    l1->next = create_node(3);
    l1->next->next = create_node(5);
    l1->next->next->next = create_node(7);
    l1->next->next->next->next = create_node(9);
    print_list(l1);
    struct Snode *l2 = create_node(2);
    l2->next = create_node(4);
    l2->next->next = create_node(6);
    l2->next->next->next = create_node(8);
    l2->next->next->next->next = create_node(10);
    print_list(l2);
    struct Snode *head = murge(l1,l2);
    print_list(head);
    return 0;
}
