#ifndef STRUCTS_H
#define STRUCTS_H

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[8];
    struct Alumno *ptrAlum;
    struct Persona *ptrSig;
};

struct Alumno{
    char matricula[10];
    char carrera[6];
    char semestre;
    char correo[23];
    float calif [5][5];
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "alta.h"
#include "Bajas.h"
#include "mostrar.h"
#include "FuncionesEspeciales.h"
#include "modificar.h"
#include "Salir.h"

int main(){
    int op,op2,op3,op4,op5,op6,op7;
    struct Persona *ptr=NULL;

    do{
        op=menuPrincipal();
        switch (op){
            case 1:
            do{
                op2=menuAltas();
                switch (op2){
                    case 1:
                        Altas(&ptr);
                        break;
                    case 2:
                        AltasVarias(&ptr);
                        break;
                    case 3:
                        printf("\nRegresando... \n");
                        break;
                    default:
                        printf("opcion invalida");
                }
            }while(op2!=3);
                break;

            case 2:
            do{
               op3=menuBajas();
                    switch (op3){
                        case 1:
                            Bajas1(&ptr);
                            break;
                        case 2:
                            BajasVarias(&ptr);
                            break;
                        case 3:
                            BajasTodos(&ptr);
                            break;
                        case 4:
                            printf("Regresando...........\n");
                            break;
                        default:
                            printf("opcion invalida");
                    }
                }while(op3!=4);
                break;
            case 3:
                do{
                op4=menuMostrar();
                switch(op4) {
                    case 1:
                        Mostrar(ptr);
                    break;
                    case 2:
                        mostrarCarreras(ptr);
                    break;
                    case 3:
                        mostrarSemestres(ptr);
                    break;
                    case 4:
                        mostrarCarreraSemestre(ptr);
                    break;
                    case 5:
                        mostrarPorNombre(ptr);
                    break;
                    case 6:
                        buscarMatricula(ptr);
                    break;
                    case 7:
                        printf("Regresando...\n");
                    break;
                    default:
                        printf("Opcion invalida.\n");
                    }
                } while(op4 != 7);
            break;
           case 4:
            do {
            op5 = MenuFuncionesEspeciales();
            switch (op5) {
                case 1:
                    do {
                        op6 = MenuModificar();
                        switch (op6) {
                            case 1:
                                do {
                                    op7 = MenuModificarCalificaciones();
                                    switch (op7) {
                                        case 1:
                                            modificarPorParcial(ptr);
                                            break;
                                        case 2:
                                            modificarPorMateria(ptr);
                                            break;
                                        case 3:
                                            printf("\nRegresando...\n");
                                            break;
                                    }
                                } while(op7 != 3);
                                break;

                            case 2:
                                do {
                                    op7 = MenuModificarDatos();
                                    switch (op7) {
                                        case 1:
                                            modificarDatosPersona(ptr);
                                            break;
                                        case 2:
                                            modificarDatosAlumno(ptr);
                                            break;
                                        case 3:
                                            printf("\nRegresando...\n");
                                            break;
                                    }
                                } while(op7 != 3);
                                break;

                            case 3:
                                printf("\nRegresando...\n");
                                break;
                        }
                    } while(op6 != 3);
                    break;

                case 2:
                    printf("\nApartado no disponibles.\n");
                    break;

                case 3:
                    printf("\nRegresando...\n");
                    break;
                }
            } while(op5 != 3);
            break;
            case 5:
                Salir(&ptr);
            break;
            default:
                printf("opcion invalida");
                break;
        }

    }while(op!=5);
}
