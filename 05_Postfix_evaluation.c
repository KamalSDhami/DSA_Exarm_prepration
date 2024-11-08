// Postfix evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int top;
    int *arr;
    int size;
};

void create_stack (struct Stack *st ){
    st->size = 100;
    
    //crete array 
    st->arr = (int *) malloc (sizeof(int) * st->size);
    st->top = -1;
}

int is_empty(struct Stack *st){
    return st->top == -1;
}

int is_full(struct Stack *st){
    return st->top == st->size -1;
}

void push (struct Stack *st,int item){
    if (is_full(st)){
        printf("Error : Stack is full ");
    }else{
        st->top = st->top +1 ;
        st->arr[st->top] = item;
    }
}

int pop(struct Stack *st){
    if (is_empty(st)){
        printf("Error : Underflow ");
    }else{
        return st->arr[st->top ] ;
        st->top --;
    }
}
//traverse

void display(struct Stack *st){
    for (int i = 0; i <= st->top; i++){
        printf("%d ",st->arr[i]);
    }printf("\n");
}

int postfix_evaluation(char*str){
    struct Stack st;
    create_stack(&st);
    for (int i = 0;str[i]!= '\0';i++){
        if (isdigit(str[i])){
            push(&st,str[i]-'0');
        }else{
            int op2 = pop(&st);
            int op1 = pop(&st);
            switch (str[i]){
                case '+':
                    push(&st, op1 + op2);
                    break;
                case '-':
                    push(&st, op1 - op2);
                    break;
                case '*':
                    push(&st, op1 * op2);
                    break;
                case '/':
                    push(&st, op1 / op2);
                    break;
                case '^':
                    push(&st, op1 ^ op2);
                    break;
            }
        }

    }
    return pop(&st);
}

int main(){
    char *str = "5 6 +";
    printf("Result : %d",postfix_evaluation(str));
    return 0;
}
