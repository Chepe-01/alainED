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
