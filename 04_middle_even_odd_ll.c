// Find mid element of sorted /unsorted linked list the no. Of nodes could be even or odd.

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
    l1->next->next->next->next->next = create_node(11);
    l1->next->next->next->next->next->next = create_node(13);
    l1->next->next->next->next->next->next->next = create_node(15);
    l1->next->next->next->next->next->next->next->next = create_node(17);
    l1->next->next->next->next->next->next->next->next->next = create_node(19);
    l1->next->next->next->next->next->next->next->next->next->next = create_node(21);
    l1->next->next->next->next->next->next->next->next->next->next->next = create_node(23);
    l1->next->next->next->next->next->next->next->next->next->next->next->next = create_node(25);
    l1->next->next->next->next->next->next->next->next->next->next->next->next->next = create_node(27);
    l1->next->next->next->next->next->next->next->next->next->next->next->next->next->next = create_node(29);
    l1->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = create_node(31);
    l1->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = create_node(33);
    print_list(l1);
    return 0;
}
// Output: 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
