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
#include "Altas.h"

int main(){
    int op,op2;
    struct Persona *ptr;

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
                        AltasVarias(ptr);
                        break;
                    default:
                        printf("opcion invalida");
                }
            }while(op2!=3);
                break;

            case 2:
                break;
            case 3:
                break;
            default:
                printf("opcion invalidad");
                break;
        }

    }while(op!=5);
}

//construir base de datos, 
//dar de alta a una persona o puede ser un alumno. una persona no necesariamente es un alumno
// 
