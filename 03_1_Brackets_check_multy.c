// Given a string of brackets,,(,[,{,},],) ,,find if its balanced or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int is_balanced(char *str){
    struct Stack st;
    create_stack(&st);
    for (int i = 0;str[i]!= '\0';i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(&st,(int)str[i]);
        }else{
            if (is_empty(&st)){
                return 0;
            }
            char temp = pop(&st);
            if (str[i] == ')' && temp != '('){
                return 0;
            }
            if (str[i] == ']' && temp != '['){
                return 0;
            }
            if (str[i] == '}' && temp != '{'){
                return 0;
            }
        }
    }
    return is_empty(&st);
}

int main(){
    char *str = "{[()]}";
    if (is_balanced(str)){
        printf("Balanced\n");
    }else{
        printf("Not Balanced\n");
    }
    return 0;
}
