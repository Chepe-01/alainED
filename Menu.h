#include <stdio.h>

int menuPrincipal(void){
    int op;
    printf("\n---MENU---\n");
    printf("[1].....Crear un nuevo dato\n");
    printf("[2].....Mostrar los datos creados\n");
    printf("[3].....Liberar el ultimo nodo\n");
    printf("[4].....Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d,&op");
    return op;
}
