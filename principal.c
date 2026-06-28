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
    char carrera[5];
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

int main(){
    int op,op2,op3;
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
                        /*case 2:
                            BajasVarias(&ptr);
                            break;
                        case 3:
                            BajasTodos(&ptr);
                            break;*/
                        case 4:
                            printf("Regresando...........\n");
                            break;
                        default:
                            printf("opcion invalida");
                    }
                }while(op3!=4);
                break;
            case 3:
                break;
            default:
                printf("opcion invalida");
                break;
        }

    }while(op!=5);
}

//construir base de datos,
//dar de alta a una persona o puede ser un alumno. una persona no necesariamente es un alumno
//
