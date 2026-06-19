#include <stdio.h>
#include <stdlib.h>


int Altas(struct Persona **ptr);

void nuevaPersona(struct Persona *ptr){
    struct Persona *p= (struct Persona*)malloc(sizeof(struct Persona));
      if(P==NULL)
        printf("no se reservo memoria");
        
        
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
