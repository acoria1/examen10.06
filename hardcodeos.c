#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "menus.h"
#include "funciones_adicionales.h"
#include "mascotas.h"
#include "razas.h"
#include "hardcodeos.h"

void hardcodearRazas (e_Raza razas[],int size){
int ids[6] = {1000,1001,1002,1003,1004,1005};
char descripciones[6][20] = {"Siames","Doberman","Persa","Pastor Belga","Dogo Argentino","Pastor Aleman"};
char tamanio[6] = {'c','g','m','g','m','g'};
int idsPais[6] = {10451,10521,10651,10818,10000,10521};

for (int i = 0; i<size;i++){
    razas[i].id = ids[i];
    razas[i].size = tamanio[i];
    strcpy(razas[i].descripcion,descripciones[i]);
    razas[i].idPaisDeOrigen = idsPais[i];
    razas[i].isFull = 1;
}
}
void hardcodearTamanios(e_Tamanio vec[],int size){
char tamanios[3] = {'c','m','g'};
char descripcion[3][10] = {"Chico","Mediano","Grande"};

for (int i = 0; i<size;i++){
    vec[i].size = tamanios[i];
    strcpy(vec[i].descripcion,descripcion[i]);
}
}

void hardcodearTipos(e_Tipo vec[],int size){
int ids[3] = {100,101,102};
char descripciones[3][10] = {"Gato","Perro","Raro"};

for (int i = 0; i <size;i++){
    vec[i].id = ids[i];
    strcpy(vec[i].descripcion,descripciones[i]);
}
}

void hardcodearMascotas (e_Mascota mascotas[],int size)
{
    int edadesMascota[7] = {2,6,10,14,3,10,9};
    int idsMascotas[7] = {20391203,32791273,12966341,79213738,82361831,93102310,12341211};
    int idsRazasMascota[7] = {1000,1001,1002,1000,1000,1004,1005};
    char sexosMascotas[7] = {'m','f','f','f','m','f','m'};
    char nombresMascotas[7][10] = {"Pipo","Luli","Camila","Reina","Rambo","Berta","Coco"};
    int idsTipoMascota[7] = {100,101,101,100,100,101,101};
    float pesos[7] = {4.1,7.3,2.7,9.1,13.0,9.8,14.3};


    for (int i = 0; i<size; i++)
    {
        mascotas[i].id = idsMascotas[i];
        strcpy(mascotas[i].nombre,nombresMascotas[i]);
        mascotas[i].edad = edadesMascota[i];
        mascotas[i].sexo = sexosMascotas[i];
        mascotas[i].idTipo = idsTipoMascota[i];
        mascotas[i].idRaza = idsRazasMascota[i];
        mascotas[i].peso = pesos[i];
        mascotas[i].isFull = 1;
    }
}


