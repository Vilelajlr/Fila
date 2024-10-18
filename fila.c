// fila.c
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Inicializa a fila
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Verifica se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enfileira um elemento na fila
void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Desenfileira um elemento da fila
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Fila vazia
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Exibe os elementos da fila
void displayQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Libera a memória alocada para a fila
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}
