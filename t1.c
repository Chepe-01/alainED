#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *Ptrsig;
};

int Menu();
int menu2();
void crearDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
void Salir(struct Dato *ptr);
void Contar(struct Dato *ptr);
void BuscarDato(struct Dato *ptr);
void Reemplazar(struct Dato *ptr);

int main(void){
    int op;
    int opcion;
    int cont = 0;
    struct Dato *ptr=NULL;
    printf("Bienvenido a este programa\n");
    do{
        op=Menu();
        switch (op){
        case 1:
            crearDato(&ptr);
            break;
        case 2:
        do{
            opcion=menu2();
            switch (opcion){
            case 1:
                BuscarDato(ptr);
                break;
            case 2:
                Contar(ptr);
                break;
            case 3:
                Reemplazar(ptr);
                break;
            case 4:
                printf("\nRegresando... \n");
                break;
            default: printf("Esa opcion no existe\n");
            }
        }while(opcion!=4);
            break;
        case 3:
            mostrarDato(ptr);
            break;
        case 4:
            liberarDato(&ptr);
            break;
        case 5:
            Salir(ptr);
            printf("\nsaliendo.....\n");
            break;
        default: printf("opcion invalida!!\n");
            break;
        }
    }while (op!=5);
    return 0;
}

int Menu(){
    int op;
    printf("\n---MENU---\n");
    printf("[1]....Crear dato\n");
    printf("[2]....Funciones\n");
    printf("[3]....Mostrar datos\n");
    printf("[4]....Liberar\n");
    printf("[5]....Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}

void crearDato(struct Dato **ptr){
    struct Dato *nuevo = (struct Dato*)malloc(sizeof(struct Dato));
    struct Dato *temp;
    if(nuevo==NULL){
        return;
    }
    printf("Ingrese un numero: \n");
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
        printf("Lista vacia \n");
        return;
    }

    printf("Datos en la lista: \n");
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
int menu2(){
    int opcion;
    printf("\n---SUBMENU---\n");
    printf("[1]....Buscar\n");
    printf("[2]....Contar\n");
    printf("[3]....Reemplazar\n");
    printf("[4]....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}
void BuscarDato(struct Dato *ptr){
    int b, e=0, p=1;
    struct Dato *ptraux=ptr;

    if(ptr==NULL){
        printf("\nLa lista esta vacia");
    }else{
        printf("ingrese el dato que deasea buscar: ");
        scanf("%d",&b);
        while(ptraux!=NULL){
            if(ptraux->d==b){
                printf("el dato %d se encuentra en la posicion %d\n",b,p);
                e=1;
            }
            ptraux=ptraux->Ptrsig;
            p++;
        }
        if (!e){
            printf("el valor no existe");
        }
    }
}
void Contar(struct Dato *ptr){
    int cont=0;
    struct Dato *ptraux=ptr;
    while(ptraux!=NULL){
        cont++;
        ptraux=ptraux->Ptrsig;
    }
    printf("La cantidad de nodos es: %d\n",cont);
}

void Reemplazar(struct Dato *ptr){
    int b, n, e=0;
    struct Dato *ptraux = ptr;

    if(ptr == NULL){
        printf("\nLa lista esta vacia\n");
        return;
    }

    printf("Ingrese el dato que desea reemplazar: ");
    scanf("%d", &b);

    printf("Ingrese el nuevo valor: ");
    scanf("%d", &n);

    while(ptraux != NULL){
        if(ptraux->d == b){
            ptraux->d = n;
            e=1;
        }
        ptraux = ptraux->Ptrsig;
    }

    if(e){
        printf("Dato reemplazado correctamente\n");
    }else{
        printf("El dato no se encontro\n");
    }
}
