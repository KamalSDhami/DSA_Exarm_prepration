// conversion of infix expression to postfix.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int precedence(char ch){
    if (ch == '+' || ch == '-'){
        return 1;
    }else if (ch == '*' || ch == '/'){
        return 2;
    }else if (ch == '^'){
        return 3;
    }
    return -1;
}

int is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
        return 1;
    }
    return 0;
}

char * infix_to_postfix(char *str){
    struct Stack st;
    create_stack(&st);
    char *postfix = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;
    while (str[i] != '\0'){
        if (isalnum(str[i])){
            postfix[j++] = str[i];
        }else if (str[i] == '('){
            push(&st,str[i]);
        }else if (str[i] == ')'){
            while (!is_empty(&st) && st.arr[st.top] != '('){
                postfix[j++] = pop(&st);
            }
            if (!is_empty(&st)){
                pop(&st);
            }
        }else if (is_operator(str[i])){
            while (!is_empty(&st) && precedence(str[i]) <= precedence(st.arr[st.top])){
                postfix[j++] = pop(&st);
            }
            push(&st,str[i]);
        }
        i++;
    }
    while (!is_empty(&st)){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *str = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix expression : %s\n",str);
    printf("Postfix expression : %s\n",infix_to_postfix(str));
    return 0;
}
