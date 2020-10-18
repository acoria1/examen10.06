#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "mascotas.h"
#include "razas.h"
#include "funciones_adicionales.h"
#include "hardcodeos.h"

void mostrarEncabezados(){
printf("****LISTA DE MASCOTAS****\n\n");
                printf("ID                NOMBRE       EDAD        SEXO           TIPO             RAZA            TAMANIO    PESO        PAIS DE ORIGEN\n");
}

void mostrarTipos (e_Tipo tipos[],int size){
printf("TIPO DE MASCOTA:\n");
for (int i = 0;i<size; i++){
printf("%d.  %20s\n",i+1,tipos[i].descripcion);
}
}

void inicializarMascotas (e_Mascota vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}


int conseguirIndiceRaza (e_Mascota x,e_Raza razas[], int sizeR){
int indice;
for (int i = 0; i<sizeR; i++){
if (x.idRaza == razas[i].id){
indice = i;
break;
}
}
return indice;
}


int conseguirIndiceTipo (e_Mascota mascota,e_Tipo tipos[],int sizeT){
int indice;
for (int  i = 0; i<sizeT;i++){
    if (mascota.idTipo == tipos[i].id){
        indice = i;
        break;
    }
}
return indice;
}








int hayMascotas (e_Mascota mascotas[],int size)
{
    int hay = 0;
    for (int i = 0; i<size; i++)
    {
        if (mascotas[i].isFull == 1)
        {
            hay++;
        }
    }
    return hay;
}


void mostrarMascotasPorRaza(e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,int idRazaMostrar)
{
    int flag = 0;

    for (int i = 0; i<size; i++)
    {
        if (mascotas[i].isFull == 1 && mascotas[i].idRaza == idRazaMostrar)
        {
            flag = 1;
            mostrarMascotaSinRaza(mascotas[i]);
        }
    }

    if (flag == 0)
    {
        printf("No hay mascotas que mostrar\n");
    }
}





void mostrarMascotaSinRaza (e_Mascota x)
{
    printf("%10d     %10s        %2d          %c    %.1f\n",x.id,x.nombre,x.edad,x.sexo,x.peso);
}





int getEmptySlotMascota (e_Mascota vec[],int size)
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


int buscarMascota (int id,e_Mascota vec[],int size)
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


int getMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR)
{
    system("cls");
    int i = getEmptySlotMascota(vec,size);
    int todoBien = 0;
    int aux;
    int auxEdad;
    char auxSexo;

    int auxTipo;
    int auxRaza;
    float auxPeso;

    if (i != -1)
    {
        printf("****ALTA DE MASCOTA****\n");
        do
        {
            if (ac_getInt(&aux,0,99999999,"Ingese ID de mascota: (xxxx xxxx)",3)== -1)
            {
                break;
            }
            else if (buscarMascota(aux,vec,size)== -1)
            {
                vec[i].id = aux;
                if (ac_getString(vec[i].nombre,20,1,"\nIngrese nombre de la mascota: ") == -1)
                {
                    break;
                }
                normalizeString( vec[i].nombre);

                if (ac_getInt(&auxEdad,0,100,"\nIngrese edad de la mascota: ",3)==-1)
                {
                    break;
                }
                vec[i].edad = auxEdad;

                if (ac_getChar(&auxSexo,"\nIngrese sexo de la mascota: (m , f) ",'f','m','m','m','m',2) == -1)
                {
                    break;
                }
                vec[i].sexo = auxSexo;
                if (ac_getFloat(&auxPeso,0,1000,"\nIngrese peso: ",2) == -1 ){
                    break;
                }
                vec[i].peso = auxPeso;
                printf("\n");
                mostrarTipos(tipos,sizeTipos);
                if (ac_getInt(&auxTipo,1,sizeTipos,"\nIngrese tipo : ",3)==-1)
                {
                    break;
                }
                switch (auxTipo)
                {
                case 1:
                    vec[i].idTipo = 100;
                    break;
                case 2:
                    vec[i].idTipo = 101;
                    break;
                case 3:
                    vec[i].idTipo = 102;
                    break;
                }
                printf("\n");
                mostrarRazas(razas,sizeR);
                if (ac_getInt(&auxRaza,1,sizeR,"\nIngrese raza de la mascota : ",3)==-1)
                {
                    break;
                }
                vec[i].idRaza = razas[auxRaza-1].id;
            }
            else
            {
                printf("\nEl ID que ha ingresado ya corresponde a una mascota en el sistema.\n");
                system("pause");
                break;
            }
            vec[i].isFull = 1;
            printf("\nAlta de mascota realizada con exito. \n\n\n");
            todoBien = 1;
            system("pause");
        }
        while (todoBien == 0);
    }
    else
    {
        printf("No hay lugar disponible.\n");
        system("pause");
    }
    return todoBien;
}


void swapMascotas (e_Mascota* x,e_Mascota* y){
e_Mascota aux;
aux = *x;
*x = *y;
*y = aux;
}


void modificarMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam){
    int aux;
    int indiceMascotaBaja;
    int opcion = 7;
    int auxTipo;
    int auxRaza;
    system("cls");
    printf("****MODIFICACION DE MASCOTA****\n");
    ac_getInt(&aux,0,99999999,"Ingrese ID de mascota a modificar (xxxx xxxx)",3);
    indiceMascotaBaja = buscarMascotaPorID(aux,vec,size);
    if ( indiceMascotaBaja == -1)
    {
        printf("La mascota que desea modificar no existe.\n");
        system("pause");
    }
    else
    {
        do
        {
            system("cls");
            printf("Datos de la mascota: \n");
            mostrarMascotaConEncabezados(vec[indiceMascotaBaja],tipos,sizeTipos,razas,sizeR,tamanios,sizeTam);
            printf("\nDato a modificar:\n");
            printf("1-Nombre\n");
            printf("2-Edad\n");
            printf("3-Peso\n");
            printf("4-Sexo\n");
            printf("5-Raza\n");
            printf("6-Tipo\n");
            printf("7-Volver a menu principal\n");
            ac_getInt(&opcion,1,7,"\nIngrese opcion: ",3);

            switch (opcion)
            {
            case 1:
                if (ac_getString(vec[indiceMascotaBaja].nombre,20,3,"\nIngrese nuevo nombre: ") == -1)
                {
                    break;
                }
                normalizeString( vec[indiceMascotaBaja].nombre);
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 2:
                if (ac_getInt(&vec[indiceMascotaBaja].edad,0,100,"\nIngrese nueva edad de mascota: ",3)==-1)
                {
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 3:
                if (ac_getFloat(&vec[indiceMascotaBaja].peso,0,1000,"\nIngrese nuevo peso de mascota: ",3) == -1)
                {
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");

                break;
            case 4:
                if (ac_getChar(&vec[indiceMascotaBaja].sexo,"\nIngrese nuevo sexo de mascota: ",'m','f','m','m','m',3) == -1)
                {
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 5:
                mostrarRazas(razas,sizeR);
                if (ac_getInt(&auxRaza,1,sizeR,"\nIngrese nueva raza de mascota: ",3)==-1)
                {
                    break;
                }
                switch (auxRaza)
                {
                case 1:
                    vec[indiceMascotaBaja].idRaza = razas[0].id;
                    break;
                case 2:
                    vec[indiceMascotaBaja].idRaza = razas[1].id;
                    break;
                case 3:
                    vec[indiceMascotaBaja].idRaza = razas[2].id;
                    break;
                case 4:
                    vec[indiceMascotaBaja].idRaza = razas[3].id;
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 6:
                mostrarTipos(tipos,sizeTipos);
                if (ac_getInt(&auxTipo,1,sizeTipos,"\nIngrese nuevo tipo de mascota: ",3)==-1)
                {
                    break;
                }
                switch (auxTipo)
                {
                case 1:
                    vec[indiceMascotaBaja].idTipo = tipos[0].id;
                    break;
                case 2:
                    vec[indiceMascotaBaja].idTipo = tipos[1].id;
                    break;
                case 3:
                    vec[indiceMascotaBaja].idTipo = tipos[2].id;
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            }
        }
        while (opcion != 7);
    }

}


int buscarMascotaPorID (int id,e_Mascota vec[],int size)
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


void eliminarMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam){
    int aux;
    int indiceMascotaBaja;
    char confirmar;
    system("cls");
    printf("****BAJA DE MASCOTA****\n");
    ac_getInt(&aux,0,99999999,"Ingrese ID de mascota a dar de baja (xxxx xxxx) :",3);
    indiceMascotaBaja = buscarMascotaPorID(aux,vec,size);
    if ( indiceMascotaBaja == -1)
    {
        printf("La mascota que desea dar de baja no existe.\n");
        system("pause");
    }
    else
    {
            system("cls");
            printf("Datos de la mascota: \n");
            mostrarMascotaConEncabezados(vec[indiceMascotaBaja],tipos,sizeTipos,razas,sizeR,tamanios,sizeTam);
            printf("\nSeguro que desea continuar? Se perderan todos los datos. (y/n)\n");
        fflush(stdin);
        scanf("%c",&confirmar);
        if (confirmar == 'y')
        {
            vec[indiceMascotaBaja].isFull = 0;
            printf("\nBaja de mascota realizada con exito. \n");
            system("pause");
        }
        else
        {
            printf("\nBaja cancelada\n");
            system("pause");
        }
    }

}


void ordenarMascotasPorPeso (e_Mascota mascotas[],int size){

for (int i = 0; i<size-1;i++){

    for (int j = i+1; j<size;j++){

        if (mascotas[j].peso > mascotas[i].peso && mascotas[i].isFull == 1 && mascotas[j].isFull == 1){
        swapMascotas(&mascotas[i],&mascotas[j]);
        }
    }
}
}






