#include <stdio.h>
#include "fila.c"

int main() {
    Queue F, F2, F3, F4;

    // Inicializa as filas
    initQueue(&F);
    initQueue(&F2);
    initQueue(&F3);
    initQueue(&F4);

    int value;
    printf("Digite uma sequencia de numeros inteiros (0 para terminar):\n");
    
    // Leitura da fila F
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        enqueue(&F, value);
    }

    // Separação dos números nas filas F2, F3 e F4
    Node* current = F.front;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            enqueue(&F2, current->data);
        }
        if (current->data % 3 == 0) {
            enqueue(&F3, current->data);
        }
        if (current->data % 2 != 0 && current->data % 3 != 0) {
            enqueue(&F4, current->data);
        }
        current = current->next;
    }

    // Exibe as filas
    printf("Fila Original F: ");
    displayQueue(&F);

    printf("Fila F2 (multiplos de 2): ");
    displayQueue(&F2);

    printf("Fila F3 (multiplos de 3): ");
    displayQueue(&F3);

    printf("Fila F4 (não multiplos de 2 ou 3): ");
    displayQueue(&F4);

    // Libera a memória das filas
    freeQueue(&F);
    freeQueue(&F2);
    freeQueue(&F3);
    freeQueue(&F4);

    return 0;
}
