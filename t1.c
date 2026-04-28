#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *Ptrsig;
};

int Menu(){
    int op;
    printf("[1]....Crear dato\n");
    printf("[2]....Mostrar datos\n");
    printf("[3]....Liberar\n");
    printf("[4]....Salir\n");
    scanf("%d",&op);
    return op;
}

void crearDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void Salir(struct Dato *ptr);

int main(void){
    int op;
    int cont = 0;
    struct Dato *ptr=NULL;

    do{
        op=Menu();
        switch (op){
        case 1:
            crearDato(&ptr);
            break;
        case 2:
            mostrarDato(ptr);
            break;
        case 3:
            liberarDato(&ptr);
            break;
        case 4:
            Salir(ptr);
            break;
        default:
            break;
        }

    }while (op!=4);

    return 0;
}

void crearDato(struct Dato **ptr){
    struct Dato *nuevo = (struct Dato*)malloc(sizeof(struct Dato));
    struct Dato *temp;
    if(nuevo==NULL){
        return;
    }
    printf("Ingrese un numero");
    scanf("%d",&nuevo->d);

    nuevo->Ptrsig=NULL;
    if(*ptr==NULL){
        *ptr=nuevo;
    }else{
        temp=*ptr;
        while(temp->Ptrsig != NULL){
            temp = temp->Ptrsig;
        }
        temp->Ptrsig=nuevo;
    }
}

void mostrarDato(struct Dato *ptr){
    if(ptr == NULL){
        printf("Lista vacia\n");
        return;
    }

    printf("Datos en la lista:\n");
    while(ptr != NULL){
        printf("%d -> ", ptr->d);
        ptr = ptr->Ptrsig;
    }
    printf("NULL\n");
}
void liberarDato(struct Dato **ptr){
    struct Dato *ptraux;
    struct Dato *anterior;

    if(*ptr==NULL){
        printf("Lista vacia\n");
        return;
    }
    if((*ptr)->Ptrsig == NULL){
        free(*ptr);
        *ptr=NULL;
        printf("se elimino el unico nodo\n");
        return;
    }
    ptraux=*ptr;

    while (ptraux->Ptrsig !=NULL){
        anterior = ptraux;
        ptraux=ptraux->Ptrsig;
    }
    anterior->Ptrsig=NULL;
    free(ptraux);
    printf("Se elimino el ultimo nodo\n");
}
void Salir(struct Dato *ptr){
    struct Dato *ptraux;

    while(ptr !=NULL){
        ptraux=ptr;
        ptr=(ptr)->Ptrsig;
        free(ptraux);
    }
    printf("Lista liberada");
}
