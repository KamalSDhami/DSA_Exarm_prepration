// stack using queue

#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front;
    int rear;
    int size;
    int *arr;
};

int is_empty(struct Queue *q){
    return q->front == -1;
}

int is_full(struct Queue *q){
    return q->rear == q->size -1;
}

void create_queue(struct Queue *q){
    q->size = 100;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int item){
    if (is_full(q)){
        printf("Error : Queue is full\n");
    }else{
        q->arr[++q->rear] = item;
    }
}

int dequeue(struct Queue *q){
    if (is_empty(q)){
        printf("Error : Queue is empty\n");
        return -1;
    }else{
        return q->arr[++q->front];
    }
}

int main(){
    struct Queue q;
    create_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}
