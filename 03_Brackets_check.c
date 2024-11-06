#include<stdio.h>
#include<stdlib.h>
// Brackets balance or not
struct Stack {
    int top;
    char *arr;
    int size;
};
int is_empty(struct Stack *st){
    return st->top == -1;
}
int is_full(struct Stack *st){
    return st->top == st->size -1;
}
void create_stack (struct Stack *st ){
    st->size = 100;
    
    //crete array 
    st->arr = (char *) malloc (sizeof(char) * st->size);
    st->top = -1;
}
void push (struct Stack *st,int item ){
    if (st->top ==st->size -1){
        printf("Error : Stack is full ");
    }else{
        st->arr[++st->top] = item;
    }
}
void pop(struct Stack *st ){
    if (is_empty(st)){
        printf("Error : Underflow ");
    }else{
        st->top --;
    }
}

//valid paranthesis ()
int is_valid_paranthesis(char *str){
    struct Stack st;
    create_stack(&st);
    for (int i =0;str[i] != '\0';i++){
        if (str[i] == '('){
            push(&st,str[i]);
        }else if (str[i] == ')'){
            if (is_empty(&st)){
                return 0;
            }else{
                pop(&st);
            }
        }
    }
    return is_empty(&st);
}

#include <stdio.h>

int main(){

    struct Stack st;
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]s",&str);
    if (is_valid_paranthesis(str)){
        printf("Valid paranthesis ");
    }else{
        printf("Invalid paranthesis ");
    }

    return 0;
}