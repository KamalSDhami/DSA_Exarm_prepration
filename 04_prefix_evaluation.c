//prefix evaluation


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int top;
    char *arr;
    int size;
};

void create_stack (struct Stack *st ){
    st->size = 100;
    
    //crete array 
    st->arr = (char *) malloc (sizeof(char) * st->size);
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
        st->arr[++st->top] = item;
    }
}

int pop(struct Stack *st){
    if (is_empty(st)){
        printf("Error : Underflow ");
    }else{
        return st->arr[st->top --] ;
    }
}

int postfix_evaluation(char*str){
    struct Stack st;
    create_stack(&st);
    for (int i = 0;str[i]!= '\0';i++){
        if (isdigit(str[i])){
            push(&st,(int)str[i]);
            printf("%d",str[i]);
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
                case '%':
                    push(&st, op1 % op2);
                    break;
            }
        }
    }
    return pop(&st);
}

int main(){
    char *str = "231*+9-";
    printf("Result : %d",postfix_evaluation(str));
    return 0;
}
