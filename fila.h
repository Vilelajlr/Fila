// fila.h
#ifndef FILA_H
#define FILA_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Funções para manipulação da fila
void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void freeQueue(Queue* q);

#endif
