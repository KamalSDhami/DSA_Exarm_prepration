// middle of link list
#include<stdio.h>
#include<stdlib.h>
typedef struct LL
{
    int data ;
    struct LL * next ;
}Snode;

Snode * newNode (int value){
    Snode *temp = (Snode*) malloc(sizeof(Snode));
    if (temp== NULL){
        printf("Error : Memory full ");
        exit(1);
    }else{
        temp->data = value;
        temp ->next = NULL;
    }
    return temp;
}

int find_middle(Snode *head ){
    if (head == NULL){
        printf("Error : Head is empty ");
    }
    else{
        Snode *slow,*fast ;
        slow = fast = head;
        int flag = 0,count =0;
        while (fast!= NULL&&fast->next!=NULL){
            slow = slow ->next;
            fast = fast->next->next;
            count ++;
            if (fast == slow){
                flag = 1;
                break;
            }
        }
        printf("i");
        if (flag){
            printf("Error : lsit is circular \n");
            return -1;
        }else {
            printf("The middle number is %d\n",slow->data);
            printf("Then middle position is %d",count);
            return count ;
        }
    }
    
}
int main(){
    Snode * LL;
    LL = newNode(0);
    LL->next = newNode(1);
    LL->next->next = newNode(2);
    LL->next->next->next= newNode(3);
    LL->next->next->next->next= newNode(4);

    find_middle(LL);
    return 0;
}
