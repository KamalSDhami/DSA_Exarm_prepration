//queue using stack
#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int top;
    int size;
    int *arr;
};

int is_empty(struct Stack *st){
    return st->top == -1;
}

int is_full(struct Stack *st){
    return st->top == st->size -1;
}

void create_stack(struct Stack *st){
    st->size = 100;
    st->arr = (int *)malloc(sizeof(int) * st->size);
    st->top = -1;
}

void push(struct Stack *st, int item){
    if (is_full(st)){
        printf("Error : Stack is full\n");
    }else{
        st->arr[++st->top] = item;
    }
}

int pop(struct Stack *st){
    if (is_empty(st)){
        printf("Error : Stack is empty\n");
        return -1;
    }else{
        return st->arr[st->top--];
    }
}

void enqueue(struct Stack *st1, struct Stack *st2, int item){
    while (!is_empty(st1)){
        push(st2, pop(st1));
    }
    push(st1, item);
    while (!is_empty(st2)){
        push(st1, pop(st2));
    }
}

int dequeue(struct Stack *st1){
    return pop(st1);
}

int main(){
    struct Stack st1, st2;
    create_stack(&st1);
    create_stack(&st2);

    enqueue(&st1, &st2, 1);
    enqueue(&st1, &st2, 2);
    enqueue(&st1, &st2, 3);
    enqueue(&st1, &st2, 4);
    enqueue(&st1, &st2, 5);

    printf("%d\n", dequeue(&st1));
    printf("%d\n", dequeue(&st1));
    printf("%d\n", dequeue(&st1));
    printf("%d\n", dequeue(&st1));
    printf("%d\n", dequeue(&st1));

    return 0;
}
