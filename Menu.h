#include <stdio.h>

int menuPrincipal(void){
    int op;
    printf("\n---MENU---\n");
    printf("[1].....Dar de alta\n");
    printf("[2].....Dar de baja\n");
    printf("[3].....Mostrar\n");
    printf("[4].....Funciones Especiales\n");
    printf("[5].....salir");
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}

int menuAltas(void){
    int opc;
    printf("\n---MENU ALTAS---\n");
    printf("[1].....Dar de alta a una persona\n");
    printf("[2].....Dar de alta varias personas\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opc);
    return opc;
}

int menuBajas(void){
    int op;
    printf("\n---MENU BAJAS---\n");
    printf("[1].....Dar de baja a una persona\n");
    printf("[2].....Dar de baja a varias personas\n");
    printf("[3].....Dar de baja a todos\n");
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}
int menuMostrar(void){
    int op;
    printf("\n---MENU MOSTRAR---\n");
    printf("[1].....Todas las personas\n");
    printf("[2].....Por carrera\n");
    printf("[3].....Por semestre\n");
    printf("[4].....Por Carrera y semestre\n");
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}
