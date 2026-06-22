#include <stdio.h>
#include <stdlib.h>


int Altas(struct Persona **ptr);

struct Persona *nuevaPersona(){
    struct Persona *p =(struct Persona*)malloc(sizeof(struct Persona));
    if(p==NULL)
        printf("no se reservo memoria");

    else{
        char nombre[50];
        p->nombre=(char*)malloc(sizeof(strlen(nombre)+1));
        printf("Nombre: ");
        fgets(nombre,sizeof(50),stdin);

        printf("Edad: ");
        scanf("%d",&p->edad);

        printf("Genero: ");
        scanf(" %c",&p->genero);

        printf("Fecha de nacimiento: ");
        scanf("%s",p->fn);

    }
    return p;
}

int Altas(struct Persona **ptr){
    struct Persona *P = NULL;
    struct Alumno *A = NULL;
    int b=1;
    P=nuevaPersona();//crea nuevo nodo y retorna direccion de memoria
    if(P==NULL)
        b=0;
    else{

        A=nuevoAlumno();
        if(A==NULL){
            b=0;
            free(P);
            
            
        }
        else{
            P->ptrAlum=A;
            P->ptrSig=*ptr;
            *ptr=P;
        }
        return b;

    }

    //Doble apuntador en la primer llamada.
    //alta retorna un entero, 1 si se pudo hacer el alta y 0 si no se pudo hacer el alta.
    //en caso que retone muedtra que no se pudo crear y muestra el emu nuevamente.
    //
}
