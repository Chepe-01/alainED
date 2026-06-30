#include <stdio.h>

int MenuFuncionesEspeciales(void){
    int opcion;
    printf("\n---MENU FUNCIONES ESPECIALES---\n");
    printf("[1].....Modificar\n");
    printf("[2].....Calificaciones\n");
    printf("[3].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}

int MenuModificar(void){
    int opcion;
    printf("\n---MENU MODIFICAR---\n");
    printf("[1].....Calificaciones de un alumno\n");
    printf("[2].....Datos\n");
    printf("[3].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}
int MenuModificarCalificaciones(void){
    int opcion;
    printf("\n---MENU MODIFICAR CALIFICACIONES---\n");
    printf("[1].....Parcial\n");
    printf("[2].....Materia\n");
    printf("[3].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}
int MenuModificarDatos(void){
    int opcion;
    printf("\n---MENU MODIFICAR CALIFICACIONES---\n");
    printf("[1].....Datos de la persona\n");
    printf("[2].....Datos del alumno\n");
    printf("[3].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}
