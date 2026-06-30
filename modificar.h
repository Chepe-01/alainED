#include <stdio.h>
#include <string.h>


void modificarPorParcial(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    char matBuscar[20];
    printf("\nMatricula del alumno: ");
    scanf("%s", matBuscar);

    struct Persona *aux = ptr;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            break;
        }
        aux = aux->ptrSig;
    }

    if (encontrado == 1) {
        int parcial, tipo;
        printf("\nAlumno: %s\n", aux->nombre);
        printf("Elija que parcial desea modificar para TODAS las materias:\n[1] Parcial (1, 2 o 3)\n[2] Ordinario\nOpcion: ");
        scanf("%d", &tipo);

        if (tipo == 1) {
            printf("Numero de parcial (1, 2 o 3): ");
            scanf("%d", &parcial);
            parcial--;
        } else {
            parcial = 3;
        }

        for (int i = 0; i < 5; i++) {
            if (parcial < 3) {
                printf("Materia %d - Nuevo Parcial %d: ", i + 1, parcial + 1);
            } else {
                printf("Materia %d - Nuevo Ordinario: ", i + 1);
            }
            scanf("%f", &aux->ptrAlum->calif[i][parcial]);
        }
        printf("¡Calificaciones del parcial actualizadas en todas las materias!\n");
    } else {
        printf("No se encontro la matricula.\n");
    }
}


void modificarPorMateria(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    char matBuscar[20];
    printf("\nMatricula del alumno: ");
    scanf("%s", matBuscar);

    struct Persona *aux = ptr;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            break;
        }
        aux = aux->ptrSig;
    }

    if (encontrado == 1) {
        int materia;
        printf("\nAlumno: %s\n", aux->nombre);
        printf("Numero de materia a modificar (1 a 5): ");
        scanf("%d", &materia);
        materia--;

        for (int j = 0; j < 4; j++) {
            if (j < 3) {
                printf("Nueva calificacion Parcial %d: ", j + 1);
            } else {
                printf("Nueva calificacion Ordinario: ");
            }
            scanf("%f", &aux->ptrAlum->calif[materia][j]);
        }
        printf("¡Todos los parciales de la materia fueron actualizados!\n");
    } else {
        printf("No se encontro la matricula.\n");
    }
}



void modificarDatosPersona(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    char matBuscar[20];
    printf("\nMatricula del alumno a modificar (Persona): ");
    scanf("%s", matBuscar);

    struct Persona *aux = ptr;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            break;
        }
        aux = aux->ptrSig;
    }

    if (encontrado == 1) {
        char nombreTemporal[50];
        printf("\nAlumno encontrado: %s\n", aux->nombre);

        printf("Nuevo Nombre: \n");
        scanf(" ");
        fgets(nombreTemporal, 50, stdin);
        nombreTemporal[strcspn(nombreTemporal, "\n")] = '\0';
        strcpy(aux->nombre, nombreTemporal);

        printf("Nueva Edad: ");
        scanf("%d", &aux->edad);
        printf("Nuevo Genero (m/f): ");
        scanf(" %c", &aux->genero);
        printf("Nueva Fecha de nacimiento: ");
        scanf("%s", aux->fn);
        printf("¡Datos personales actualizados con exito!\n");
    } else {
        printf("\nError: No se encontro un alumno con la matricula '%s'.\n", matBuscar);
        printf("Nota: Si la persona no se registro como alumno, no cuenta con matricula.\n");
    }
}


void modificarDatosAlumno(struct Persona *ptr) {
    if (ptr == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    char matBuscar[20];
    printf("\nMatricula del alumno a modificar (Estudiante): ");
    scanf("%s", matBuscar);

    struct Persona *aux = ptr;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            break;
        }
        aux = aux->ptrSig;
    }

    if (encontrado == 1) {
        printf("\nAlumno encontrado: %s\n", aux->nombre);

        printf("Nueva Carrera: ");
        scanf("%s", aux->ptrAlum->carrera);
        printf("Nuevo Semestre: ");
        scanf(" %c", &aux->ptrAlum->semestre);
        printf("Nuevo Correo: ");
        scanf("%s", aux->ptrAlum->correo);
        printf("¡Datos de estudiante actualizados con exito!\n");
    } else {
        printf("\nNo se encontro ningun alumno con la matricula: %s\n", matBuscar);
    }
}
