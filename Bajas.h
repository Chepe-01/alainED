#include <stdio.h>
#include <stdlib.h>

void Bajas1(struct Persona **ptr){
    struct Persona *ptraux;
    if(*ptr==NULL){
        printf("No existe registro\n");
        return;
    }else{
        ptraux=*ptr;
        *ptr = ptraux->ptrSig;
        if(ptraux->ptrAlum!=NULL){
            free(ptraux->ptrAlum);
        }
        free(ptraux->nombre);
        free(ptraux);
        printf("Baja realizada con exito.\n");
    }
}

void BajasVarias(struct Persona **ptr){
    int n;
    if (*ptr == NULL) {
        printf("No existen registros\n");
        return;
    }
    printf("¿Cuantas personas desea dar de baja?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (*ptr == NULL) {
            printf("\nSe detuvieron las bajas porque la lista esta vacia.\n");
            break;
        }
        Bajas1(ptr);
    }
}
