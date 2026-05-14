#include <stdio.h>
#include <stdlib.h>
struct Dato{
    int n;
    struct Dato *ant;
    struct Dato *sig;
};
int Menu(){
    int op;
    printf("\n---MENU---\n");
    printf("[1]....Insertar nuevo dato\n");
    printf("[2]....Eliminar\n");
    printf("[3]....Mostrar datos\n");
    printf("[4]....Salir\n");;
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}

int main (void){
    int op;
    do{
        op=Menu();
        switch (op) {
        case 1:
            struct Dato *nuevo=(struct Dato*)malloc(sizeof(struct Dato));
            struct Dato *temp;
            struct Dato *ptr;
            if(nuevo==NULL){
                printf("No se reservo memoria");
            }else {
            printf("Ingrese el valor: ");
            scanf("%d", &nuevo->n);
            }
            if (ptr == NULL) {
                nuevo->sig = nuevo;
                nuevo->ant = nuevo;
                ptr = nuevo;
            } else {
                struct Dato *ultimo = ptr->ant;
                nuevo->sig = ptr;
                nuevo->ant = ultimo;
                ultimo->sig = nuevo;
                ptr->ant = nuevo;
                ptr = nuevo;
            }
            printf("Elemento insertado\n");
            break;

        case 2:
            if (ptr == NULL) {
                printf("Lista vacia\n");
            } else {
                struct Dato *ultimo = ptr->ant;
                if (ultimo == ptr) {
                free(ptr);
                ptr = NULL;
                printf("se elimino el unico nodo\n");
            } else {
                struct Dato *penultimo = ultimo->ant;

                penultimo->sig = ptr;
                ptr->ant = penultimo;

                free(ultimo);
                printf("Se elimino el ultimo nodo\n");
            }
        }
            break;
        case 3:
            if (ptr == NULL) {
                printf("La lista está vacía.\n");
            } else {
                struct Dato*temp = ptr;
                printf("Elementos de la lista: ");
                do {
                    printf("%d -> ", temp->n);
                    temp = temp->sig;
                } while (temp != ptr);
                printf("(circular)\n");
            }
            break;
        case 4:
            if (ptr == NULL){
            } else {
                struct Dato *actual = ptr->sig;
                struct Dato *temp;

                while (actual != ptr) {
                temp = actual;
                actual = actual->sig;
                free(temp);
            }
            free(ptr);
            ptr = NULL;
            }
            printf("Lista liberada\n");
            printf("Saliendo...\n");
            break;
        default: printf("opcion invalida!!\n");
            break;
        }
    }while(op!=4);
}
