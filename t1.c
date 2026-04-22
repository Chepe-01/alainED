#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrsing;
};

int menu(){
    printf("1. Crear dato\n");
    printf("2. Mostrar dato\n");
    printf("3. Liberar\n");
    printf("4. Salir\n");
    printf("seleccione una opcion");
    scanf("%d",&op);
    return op;
}
struct Dato * reservarmemoria(){
    struct Dato *ptrtemp;
    ptrtemp=(struct Dato*)malloc(sizeof(struct Dato));
    if(ptrtemp==NULL){
        return NULL;
    }else{
        
    }
}
int main (void){
    int op;
    struct Dato *ptr=NULL;
    
    do{
        op=menu();
        switch (op){
    case 1:
        creardato()
        }
    }
}
