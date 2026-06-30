#include <stdio.h>
#include <string.h>

void Mostrar(struct Persona *ptr){
    struct Persona *ptraux = ptr;

    if(ptraux == NULL){
        printf("No hay registros.\n");
        return;
    }

    printf("\n--- Personas registradas ---\n");
    while(ptraux != NULL){
        printf("\nNombre: %s\n", ptraux->nombre);
        printf("Edad: %d\n", ptraux->edad);
        printf("Genero: %c\n", ptraux->genero);
        printf("Fecha de nacimiento: %s\n", ptraux->fn);

        if(ptraux->ptrAlum != NULL){
            printf("Matricula: %s\n", ptraux->ptrAlum->matricula);
            printf("Carrera: %s\n", ptraux->ptrAlum->carrera);
            printf("Semestre: %c\n", ptraux->ptrAlum->semestre);
            printf("Correo: %s\n", ptraux->ptrAlum->correo);
        }
        printf("-----------------------------\n");
        ptraux = ptraux->ptrSig;
    }
}

// 2. CARRERA: Filtra y muestra solo los alumnos de la carrera ingresada
void mostrarCarreras(struct Persona *ptr){
    if(ptr == NULL){
        printf("No hay registros.\n");
        return;
    }

    char carreraBusqueda[50];
    int encontrado = 0;
    printf("\nIngrese la carrera a buscar: ");
    scanf("%s", carreraBusqueda);

    printf("\nAlumnos en la carrera %s:\n", carreraBusqueda);
    while(ptr != NULL){
        if(ptr->ptrAlum != NULL && strcmp(ptr->ptrAlum->carrera, carreraBusqueda) == 0){
            printf("- %s (Matricula: %s)\n", ptr->nombre, ptr->ptrAlum->matricula);
            encontrado = 1;
        }
        ptr = ptr->ptrSig;
    }
    if(!encontrado) printf("No se encontraron alumnos en esa carrera.\n");
}

// 3. SEMESTRE: Filtra y muestra los alumnos de un semestre específico
void mostrarSemestres(struct Persona *ptr){
    if(ptr == NULL){
        printf("No hay registros.\n");
        return;
    }

    char semestreBusqueda;
    int encontrado = 0;
    printf("\nIngrese el semestre a buscar (un caracter): ");
    scanf(" %c", &semestreBusqueda);

    printf("\nAlumnos del semestre %c:\n", semestreBusqueda);
    while(ptr != NULL){
        if(ptr->ptrAlum != NULL && ptr->ptrAlum->semestre == semestreBusqueda){
            printf("- %s (Carrera: %s)\n", ptr->nombre, ptr->ptrAlum->carrera);
            encontrado = 1;
        }
        ptr = ptr->ptrSig;
    }
    if(!encontrado) printf("No se encontraron alumnos en ese semestre.\n");
}

// 4. CARRERA Y SEMESTRE: Filtro combinado doble
void mostrarCarreraSemestre(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("No hay registros.\n");
        return;
    }

    char carreraBusqueda[50];
    char semestreBusqueda;
    int encontrado = 0;

    printf("\nIngrese la carrera: ");
    scanf("%s", carreraBusqueda);
    printf("Ingrese el semestre: ");
    scanf(" %c", &semestreBusqueda);

    printf("\nAlumnos de %s (Semestre %c):\n", carreraBusqueda, semestreBusqueda);
    while (ptr != NULL) {
        if (ptr->ptrAlum != NULL && strcmp(ptr->ptrAlum->carrera, carreraBusqueda) == 0 && ptr->ptrAlum->semestre == semestreBusqueda) {
            printf("- %s (Matricula: %s)\n", ptr->nombre, ptr->ptrAlum->matricula);
            encontrado = 1;
        }
        ptr = ptr->ptrSig;
    }
    if(!encontrado) printf("No hay alumnos que coincidan con ambos filtros.\n");
}

// 5. NOMBRE: Busca a una persona por coincidencia exacta
void mostrarPorNombre(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("No hay registros.\n");
        return;
    }

    char nombreBusqueda[50];
    int encontrado = 0;

    printf("\nIngrese el nombre a buscar: ");
    scanf("%s", nombreBusqueda); // Lee directo sin llamadas raras a sí misma

    while (ptr != NULL){
        if (strcmp(ptr->nombre, nombreBusqueda) == 0) {
            printf("\n--- Registro Encontrado ---\n");
            printf("Nombre: %s\n", ptr->nombre);
            printf("Edad: %d\n", ptr->edad);
            printf("Genero: %c\n", ptr->genero);
            printf("Fecha de nacimiento: %s\n", ptr->fn);
            if (ptr->ptrAlum != NULL) {
                printf("Matricula: %s\n", ptr->ptrAlum->matricula);
                printf("Carrera: %s\n", ptr->ptrAlum->carrera);
                printf("Semestre: %c\n", ptr->ptrAlum->semestre);
                printf("Correo: %s\n", ptr->ptrAlum->correo);
            }
            encontrado = 1;
        }
        ptr = ptr->ptrSig;
    }

    if (!encontrado) {
        printf("Persona no encontrada.\n");
    }
}

// 6. MATRICULA: Busca un alumno por su matrícula
void buscarMatricula(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("No hay registros.\n");
        return;
    }

    char matriculaBusqueda[20];
    int encontrado = 0;

    printf("\nIngrese la matricula a buscar: ");
    scanf("%s", matriculaBusqueda);

    while (ptr != NULL) {
        if (ptr->ptrAlum != NULL && strcmp(ptr->ptrAlum->matricula, matriculaBusqueda) == 0) {
            printf("\n--- Alumno Encontrado ---\n");
            printf("Nombre: %s\n", ptr->nombre);
            printf("Matricula: %s\n", ptr->ptrAlum->matricula);
            printf("Carrera: %s\n", ptr->ptrAlum->carrera);
            printf("Semestre: %c\n", ptr->ptrAlum->semestre);
            printf("Correo: %s\n", ptr->ptrAlum->correo);
            encontrado = 1;
            break;
        }
        ptr = ptr->ptrSig;
    }

    if (!encontrado) {
        printf("Matricula no encontrada.\n");
    }
}
