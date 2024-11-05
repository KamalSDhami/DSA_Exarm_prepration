//murge 2 shorted linklist
#include<stdio.h>
#include<stdlib.h>

struct Snode
{
    int info;
    struct Snode * next;
};
struct Snode * new_node(int value){
    struct  Snode *temp ;
    temp = (struct Snode *) malloc(sizeof(struct Snode));
    if (temp == NULL){
        printf("Error : Memory Full");
        exit(1);
    }
    temp->info = value;
    temp ->next = NULL;
    return temp;
}
void traverce (struct Snode *head){
    if (head == NULL){
        printf("LL is empty ");
    }else{
        printf("Element of the LL are : ");
        while (head!=NULL){
            printf("%d ",head->info);
            head= head->next;
        }
    }
    printf("\n");
}
struct Snode * mearge(struct Snode *head1,struct Snode *head2){
    if (!head1){
        return head2;
    }
    if (!head2){
        return head1;
    }
    struct Snode *temp=NULL;

    if (head1->info <= head2->info){
        temp = head1;
        temp->next = mearge (head1->next, head2);
    }else {
        temp = head2;
        temp->next = mearge (head1, head2->next);
    }
    return temp;
}
int main(){
    //create the linklist 
    struct Snode *LL1, *LL2,*LL3;

    //ll 1
    LL1 = new_node(1);
    LL1->next = new_node(1);
    LL1->next->next = new_node(2);
    traverce(LL1);

    //LL2
    LL2 = new_node(1);
    LL2->next = new_node(2);
    LL2->next->next = new_node(3);
    LL2->next->next->next = new_node(4);

    traverce(LL2);


    LL3  =mearge(LL1,LL2);
    traverce(LL3);

    return 0;
}