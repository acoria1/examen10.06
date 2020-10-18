#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "ac_getFunciones.h"
#include "menus.h"
#include "funciones_adicionales.h"
#include "razas.h"

int getEmptySlotRaza(e_Raza vec[],int size)
{
    int lugar = -1;
    int flag = 0;
    for (int i = 0; i<size && flag == 0; i++)
    {
        if (vec[i].isFull == 0)
        {
            lugar = i;
            flag = 1;
        }
    }
    return lugar;
}

int buscarRaza (int id,e_Raza vec[],int size)
{
    int lugar = -1;
    for (int i= 0; i<size; i++)
    {
        if (vec[i].id == id && vec[i].isFull == 1)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}



void mostrarTamanios (e_Tamanio vec[],int size){
printf("TAMANIOS DE MASCOTA:\n");
for (int i = 0;i<size; i++){
printf("%d.  %20s\n",i+1,vec[i].descripcion);
}
}

void mostrarRazas (e_Raza razas[],int size){
printf("RAZAS :\n");
for (int i = 0;i<size; i++){
if (razas[i].isFull == 1){
printf("%d.  %20s\n",i+1,razas[i].descripcion);
}
}
}



int conseguirIndiceTamanioPorRaza (e_Raza raza,e_Tamanio tamanios[],int sizeTam){
int indice;
for (int  i = 0; i<sizeTam;i++){
    if (raza.size == tamanios[i].size){
        indice = i;
         break;
    }
}
return indice;
}


void inicializarRazas (e_Raza vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}

