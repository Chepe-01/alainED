#include <stdio.h>
#include <stdlib.h>

void Salir(struct Persona **ptr) {
    if (*ptr == NULL) {
        printf("\nSaliendo.\n");
        return;
    }

    struct Persona *aux = *ptr;
    struct Persona *siguiente = NULL;
    int contador = 0;

    while (aux != NULL) {
        siguiente = aux->ptrSig;

        if (aux->ptrAlum != NULL) {
            free(aux->ptrAlum);
            aux->ptrAlum = NULL;
        }
        free(aux->nombre);
        free(aux);
        aux = siguiente;
        contador++;
    }

    *ptr = NULL;
    printf("Saliendo.....\n");
}
