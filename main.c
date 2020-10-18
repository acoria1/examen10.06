/*Coria,Agustin
7ma parte
 */

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

#define TAMRAZAS 7
#define TAMTAMANIOS 3
#define TAMTIPOS 3
#define TAMMASCOTAS 10
#define TAMPAISES 5

typedef struct {
char nombreDePais [30];
char continente[15];
int codigoTelefonico;
int idPais;
int isFull;

} e_pais;


char menu(void);
int menuInformes(void);

float sacarPesoPromedioPorTipo (int idTipo,e_Mascota mascotas[],int size);
float sacarPesoPromedioPorTamanio (char sizeTamanio,e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR);
void mostrarPesoPromedioPorCadaTamanio (e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR);
void mostrarCantidadDeXTipoPorRaza ( e_Raza razas[],int sizeR,e_Mascota mascotas[],int sizeM,e_Tipo tipos[],int sizeT);
int calcularCantidadDeMachosPorTamanio (char tamanio,e_Tamanio tamanios[],int sizeT,e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR);
void mostrarMayorPesoPorPais (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR);
void ordenarMascotasPorEdadyNombre (e_Mascota mascotas[],int size);
float calcularPromedioEdadPorRaza (int idRaza,e_Mascota mascotas[],int sizeM);
int conseguirIndicePaisPorId (int id, e_pais paises[],int sizeP);

void mostrarEncabezados();
void mostrarTipos (e_Tipo tipos[],int size);
void inicializarMascotas (e_Mascota vec[],int size);
int conseguirIndiceRaza (e_Mascota x,e_Raza razas[], int sizeR);
int conseguirIndiceTipo (e_Mascota mascota,e_Tipo tipos[],int sizeT);
void mostrarMascota (e_Mascota x,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP);
void mostrarMascotas(e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP);
int hayMascotas (e_Mascota mascotas[],int size);
void mostrarMascotasPorRaza(e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,int idRazaMostrar);
void mostrarTodasMascotasPorRaza (e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP);
void mostrarMascotaSinRaza (e_Mascota x);
void mostrarMascotaConEncabezados (e_Mascota x,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP);
int getEmptySlotMascota (e_Mascota vec[],int size);
int buscarMascota (int id,e_Mascota vec[],int size);
int getMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR);
void swapMascotas (e_Mascota* x,e_Mascota* y);
void modificarMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam);
int buscarMascotaPorID (int id,e_Mascota vec[],int size);
void eliminarMascota (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam);
void ordenarMascotasPorPeso (e_Mascota mascotas[],int size);
void mostrarPaisesConMasMascotas (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR,e_pais paises[],int sizeP);

int getEmptySlotRaza(e_Raza vec[],int size);
int buscarRaza (int id,e_Raza vec[],int size);
int getRaza (e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP);
void mostrarTamanios (e_Tamanio vec[],int size);
void mostrarRazas (e_Raza razas[],int size);
void mostrarRazasCompletas (e_Raza razas[],int size,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP);
int conseguirIndiceTamanioPorRaza (e_Raza raza,e_Tamanio tamanios[],int sizeTam);
void inicializarRazas (e_Raza vec[],int size);
void inicializarPaises (e_pais vec[],int size);
void hardcodearPaises (e_pais paises[],int size);
void ordenarMascotasPorCodigoTelefonico (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR,e_pais paises[],int sizeP);
void mostrarPesosYCantidadesDeCadaTipo (e_Mascota mascotas[],int sizeM,e_Tipo tipos[],int sizeT);
int sacarCantidadDeMascotasPorTipo (int idTipo,e_Mascota mascotas[],int size);
float sacarPesoTotalPorTipo (int idTipo,e_Mascota mascotas[],int size);
float sacarPesoPromedioPorTipo (int idTipo,e_Mascota mascotas[],int size);
void eliminarRaza (e_Mascota vec[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP);
void listarMascotasPorTamanioAElejir (e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR,e_Tipo tipos[],int sizeT,e_pais paises[],int sizeP);
float sacarPesoTotalPorTamanio (char tamanioElejido,e_Mascota mascotas[],int size,e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam);

int main()
{
    char opcion;
    int opcionInformes;

    e_Mascota mascotas[TAMMASCOTAS];
    e_Raza razas[TAMRAZAS];
    e_Tamanio tamanios[TAMTAMANIOS];
    e_Tipo tipos[TAMTIPOS];
    e_pais paises[TAMPAISES];

    inicializarMascotas(mascotas,TAMMASCOTAS);
    inicializarRazas(razas,TAMRAZAS);
    inicializarPaises(paises,TAMPAISES);

    hardcodearRazas(razas,6);
    hardcodearTamanios(tamanios,3);
    hardcodearTipos(tipos,3);
    hardcodearMascotas(mascotas,5);
    hardcodearPaises(paises,5);

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 'a':
            getMascota(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS);
            break;
        case 'b':
            if (hayMascotas(mascotas,TAMMASCOTAS)>0)
            {
                modificarMascota(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS);
            }
            else
            {
                printf("\nNo hay mascotas cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'c':
            if (hayMascotas(mascotas,TAMMASCOTAS)>0)
            {
                eliminarMascota(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS);
            }
            else
            {
                printf("\nNo hay mascotas cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'd':
            if (hayMascotas(mascotas,TAMMASCOTAS)>0)
            {
                system("cls");
                mostrarEncabezados();
                mostrarMascotas(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
                system("pause");
            }
            else
            {
                printf("\nNo hay mascotas cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'e':
            system("cls");
            printf("**LISTADO DE RAZAS**\n");
            mostrarTodasMascotasPorRaza(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
            system("pause");

            break;
        case 'f':
            system("cls");
            ordenarMascotasPorPeso(mascotas,TAMMASCOTAS);
            mostrarEncabezados();
            mostrarMascotas(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
            system("pause");
            break;
        case 'g':
            system("cls");
            mostrarPaisesConMasMascotas(mascotas,TAMMASCOTAS,razas,TAMRAZAS,paises,TAMPAISES);
            system("pause");
            break;
        case 'h':
            system("cls");
            getRaza(razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
            break;
        case 'i':
            system("cls");
            mostrarRazasCompletas(razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
            system("pause");
            break;
        case 'j':
            if (hayMascotas(mascotas,TAMMASCOTAS)>0)
            {
                do
                {
                    opcionInformes = menuInformes();
                    switch(opcionInformes)
                    {
                    case 1:
                        system("cls");
                        ordenarMascotasPorCodigoTelefonico(mascotas,TAMMASCOTAS,razas,TAMRAZAS,paises,TAMPAISES);
                        mostrarEncabezados();
                        mostrarMascotas(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
                        break;
                    case 2:
                        system("cls");
                        mostrarPesosYCantidadesDeCadaTipo(mascotas,TAMMASCOTAS,tipos,TAMTIPOS);
                        break;
                    case 3:
                        system("cls");
                        listarMascotasPorTamanioAElejir(mascotas,TAMMASCOTAS,tamanios,TAMTAMANIOS,razas,TAMRAZAS,tipos,TAMTIPOS,paises,TAMPAISES);
                        break;
                    case 4:
                        system("cls");
//                        mostrarCantidadDeXTipoPorRaza(razas,TAMRAZAS,mascotas,TAMMASCOTAS,tipos,TAMTIPOS);
                        break;
                    case 5:
                        system("cls");
//                        printf("Cantidad de machos por tamanios:\n");
//                        printf("Chico: %d\n",calcularCantidadDeMachosPorTamanio('c',tamanios,TAMTAMANIOS,mascotas,TAMMASCOTAS,razas,TAMRAZAS));
//                        printf("Mediano: %d\n",calcularCantidadDeMachosPorTamanio('m',tamanios,TAMTAMANIOS,mascotas,TAMMASCOTAS,razas,TAMRAZAS));
//                        printf("Grande: %d\n",calcularCantidadDeMachosPorTamanio('g',tamanios,TAMTAMANIOS,mascotas,TAMMASCOTAS,razas,TAMRAZAS));
                        break;
                    case 6:
//                        system("cls");
//                        mostrarMayorPesoPorPais(mascotas,TAMMASCOTAS,razas,TAMRAZAS);
                        break;
                    case 7:
//                        mostrarMascotaMasLivianaPorRaza(mascotas,TAMMASCOTAS,razas,TAMRAZAS);
                        break;
                    case 8:
                        system("cls");
//                        printf("Promedio de edad de %s :  %.2f",razas[0].descripcion,calcularPromedioEdadPorRaza(1000,mascotas,TAMMASCOTAS));
                        break;
                    case 9:
                        system("cls");
                        printf("9");
                        break;
                    case 10:
                        system("cls");
                        printf("10");
                        break;
                    }
                    if (opcionInformes != 11)
                    {
                        system("pause");
                    }
                }
                while (opcionInformes != 11);
            }
            else
            {
                printf("\nNo hay mascotas cargadas en el sistema. \n");
                system("pause");
            }
            break;
                    case 'k':
                        eliminarRaza(mascotas,TAMMASCOTAS,tipos,TAMTIPOS,razas,TAMRAZAS,tamanios,TAMTAMANIOS,paises,TAMPAISES);
                        break;
        }
    }
    while (opcion != 'l');

    return 0;
}



char menu(void)
{
    char opcion;
    system("cls");
    printf("****MENU DE OPCIONES****\n\n");
    printf("A-  ALTA DE MASCOTA\n");
    printf("B-  MODIFICACION DE MASCOTA\n");
    printf("C-  BAJA DE MASCOTA\n");
    printf("D-  LISTAR MASCOTAS \n");
    printf("E-  LISTADO DE MASCOTAS POR RAZA \n");
    printf("F-  LISTADO DE MASCOTAS ORDENADAS POR PESO\n");
    printf("G-  MOSTRAR PAISES CON MAYOR CANTIDAD DE MASCOTAS\n");
    printf("H-  ALTA DE RAZA\n");
    printf("I-  MOSTRAR RAZAS\n");
    printf("J-  INFORMES (2da parte)\n");
    printf("K-  BORRAR RAZA\n");
    printf("L- SALIR\n");

    ac_getChar(&opcion,"Ingrese opcion: ",'0','0','0','0','0',3);
    opcion = tolower(opcion);
    while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd' && opcion != 'e' && opcion != 'f' && opcion != 'g' && opcion != 'h' && opcion != 'i' && opcion != 'j' && opcion != 'k')
    {
        ac_getChar(&opcion,"Error. Ingrese opcion: ",'0','0','0','0','0',3);
    }
    return opcion;
}


int menuInformes(void)
{
    int opcion = 11;
    system("cls");
    printf("**** MENU DE INFORMES ****\n\n");
    printf("1-  Ordenar Mascotas por Codigo Telefonico y mostrar\n");
    printf("2-  Listar por tipo y peso\n");
    printf("3-  Listar Mascotas por tamanio a elejir\n");
    printf("4-  \n");
    printf("5-  \n");
    printf("6-  \n");
    printf("7-  \n");
    printf("8-  \n");
    printf("9- \n");
    printf("10- \n");
    printf("11- VOLVER A MENU PRINCIPAL \n");

    ac_getInt(&opcion,1,11,"Ingrese opcion: ",3);
    return opcion;
}

float sacarPesoPromedioPorTipo (int idTipo,e_Mascota mascotas[],int size){
float suma = 0;
float promedio;
int contador = 0;

for (int i = 0; i<size; i++){
    if (mascotas[i].idTipo == idTipo && mascotas[i].isFull){
        suma+= mascotas[i].peso;
        contador++;
    }
}
if (contador != 0){
promedio =  suma / contador;
}
return promedio;
}

float sacarPesoTotalPorTipo (int idTipo,e_Mascota mascotas[],int size){
float suma = 0;


for (int i = 0; i<size; i++){
    if (mascotas[i].idTipo == idTipo && mascotas[i].isFull){
        suma+= mascotas[i].peso;
    }
}
return suma;
}

int sacarCantidadDeMascotasPorTipo (int idTipo,e_Mascota mascotas[],int size){
int contador = 0;

for (int i = 0; i <size ; i++){
    if (mascotas[i].idTipo == idTipo && mascotas[i].isFull){
        contador++;
    }
}
return contador;
}

void mostrarPesosYCantidadesDeCadaTipo (e_Mascota mascotas[],int sizeM,e_Tipo tipos[],int sizeT){
float pesosTotales [sizeT];
float promediosPesos [sizeT];
int cantidadesDeMascotas [sizeT];

for (int i = 0 ; i<sizeT ; i++){
        pesosTotales[i] = sacarPesoTotalPorTipo(tipos[i].id,mascotas,sizeM);
        promediosPesos[i] = sacarPesoPromedioPorTipo(tipos[i].id,mascotas,sizeM);
        cantidadesDeMascotas[i] = sacarCantidadDeMascotasPorTipo(tipos[i].id,mascotas,sizeM);
}
printf("     TIPOS          PESO TOTAL            PROMEDIO DE PESO             CANTIDAD DE MASCOTAS\n");
for (int i = 0; i<sizeT; i++){
    printf("%10s      %10.2f             %10.2f                   %10d\n",tipos[i].descripcion,pesosTotales[i],promediosPesos[i],cantidadesDeMascotas[i]);
}
}


//float sacarPesoPromedioPorTamanio (char sizeTamanio,e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR){
//float promedio;
//int indiceT,indiceR;
//float suma = 0;
//int contador = 0;
//
//for (int i = 0; i<sizeM; i++){
//        indiceR = conseguirIndiceRaza(mascotas[i],razas,sizeR);
//        indiceT = conseguirIndiceTamanioPorRaza(razas[indiceR],tamanios,sizeTam);
//    if (tamanios[indiceT].size == sizeTamanio && mascotas[i].isFull){
//        suma+= mascotas[i].peso;
//        contador++;
//    }
//}
//promedio = suma / contador;
//return promedio;
//}
//
//void ordenarMascotasPorEdadyNombre (e_Mascota mascotas[],int size){
//
//for (int i = 0; i<size-1;i++){
//
//    for (int j = i+1; j<size;j++){
//
//        if (mascotas[j].edad > mascotas[i].edad && mascotas[i].isFull == 1 && mascotas[j].isFull == 1){
//        swapMascotas(&mascotas[i],&mascotas[j]);
//        }
//        else if (mascotas[j].edad == mascotas[i].edad && strcmp(mascotas[i].nombre,mascotas[j].nombre) > 0 &&mascotas[i].isFull == 1 && mascotas[j].isFull == 1) {
//        swapMascotas(&mascotas[i],&mascotas[j]);
//        }
//    }
//}
//}
//
//void mostrarCantidadDeXTipoPorRaza ( e_Raza razas[],int sizeR,e_Mascota mascotas[],int sizeM,e_Tipo tipos[],int sizeT){
//int contadoresR[sizeR];
//int auxTipo;
//mostrarTipos(tipos,sizeT);
//if (ac_getInt(&auxTipo,1,sizeT,"Ingrese tipo de mascota: ",3)!= -1){
//for (int i = 0 ; i<sizeR ; i++){
//    contadoresR[i] = 0;
//}
//for (int i = 0; i < sizeR ; i++){
//    if (razas[i].isFull == 1){
//    for (int j = 0; j < sizeM ; j++){
//        if (mascotas[j].isFull == 1 && mascotas[j].idTipo == tipos[auxTipo-1].id && mascotas[j].idRaza == razas[i].id){
//        contadoresR[i]++;
//    }
//    }
//    }
//}
//system("cls");
//printf("Cantidad de %s por raza:\n",tipos[auxTipo-1].descripcion);
//for (int i = 0; i <sizeR; i++){
//    if (razas[i].isFull == 1){
//    printf("%20s : %d\n",razas[i].descripcion,contadoresR[i]);
//    }
//}
//}
//}
//
//void mostrarPesoPromedioPorCadaTamanio (e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR){
//
//for (int i = 0; i < sizeTam ; i++){
//    printf("Peso promedio de mascotas %s : %.2f\n",tamanios[i].descripcion,sacarPesoPromedioPorTamanio(tamanios[i].size,mascotas,TAMMASCOTAS,tamanios,TAMTAMANIOS,razas,TAMRAZAS));
//}
//
//}
//
//
//int calcularCantidadDeMachosPorTamanio (char tamanio,e_Tamanio tamanios[],int sizeT,e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR){
//int contador = 0;
//int indiceR,indiceT;
//
//for (int i = 0; i < sizeM ; i++){
//    indiceR = conseguirIndiceRaza(mascotas[i],razas,sizeR);
//    indiceT = conseguirIndiceTamanioPorRaza(razas[indiceR],tamanios,sizeT);
//    if (tamanios[indiceT].size == tamanio && mascotas[i].isFull == 1 && mascotas[i].sexo == 'm'){
//        contador++;
//    }
//}
//return contador;
//}
//
//void mostrarMayorPesoPorPais (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR){
//char paises[sizeR][30];
//int j,k;
//
//for (int i = 0;i<sizeR;i++){
//    strcpy(paises[i],razas[i].paisDeOrigen);
//}
//int n = sizeR;
//
//for (int i = 0;i < n;i++){
//    for (j = i+1;j<n;){
//        if (strcmp(paises[i],paises[j])== 0){
//            for (k = j;k < n ; k++){
//                strcpy(paises[k],paises[k+1]);
//            }
//            n--;
//        }
//        else {
//            j++;
//        }
//    }
//}
//
//
//char paises2 [n][30];
//for (int i = 0; i<n ; i++){
//strcpy(paises2[i],paises[i]);
//}
//
//float pesos[n];
//for (int i = 0; i< n ; i++){
//    pesos[i] = 0;
//}
//
//int indice;
//
//for (int l = 0; l < n ; l++){
//    for (int m = 0; m < sizeM ; m++){
//        if (mascotas[m].isFull == 1){
//        indice = conseguirIndiceRaza(mascotas[m],razas,sizeR);
//        if (strcmp(razas[indice].paisDeOrigen,paises2[l]) == 0 && mascotas[m].peso > pesos[l]){
//            pesos[l] = mascotas[m].peso;
//        }
//    }
//    }
//}
//
//
//printf("PESO MAXIMO DE UNA MASCOTA POR PAIS: \n\n");
//for (int i = 0; i<n ; i++){
//        if (razas[i].isFull == 1){
//        printf("Pais de Origen: %20s     , Peso Maximo: %.1f\n",paises2[i],pesos[i]);
//        }
//}
//}
//
//void mostrarMascotaMasLivianaPorRaza (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR){
//float pesosMinimos[sizeR];
//int flags [sizeR];
//
//for (int i = 0; i<sizeR ; i++){
//    flags[i] = 0;
//    for (int j = 0; j<sizeM ; j++){
//        if (flags[i] == 0 && mascotas[j].isFull == 1 && mascotas[j].idRaza == razas[i].id){
//            pesosMinimos[i] = mascotas[j].peso;
//            flags[i] = 1;
//        }
//        else if (mascotas[j].isFull == 1 && mascotas[j].peso < pesosMinimos[i] && mascotas[j].idRaza == razas[i].id){
//            pesosMinimos[i] = mascotas[j].peso;
//        }
//    }
//}
//printf("RAZA        PESO MINIMO\n");
//for (int i = 0; i<sizeR ; i++){
//    if (razas[i].isFull == 1){
//    printf("%20s : %.1f\n",razas[i].descripcion,pesosMinimos[i]);
//    }
//}
//}
//
//float calcularPromedioEdadPorRaza (int idRaza,e_Mascota mascotas[],int sizeM){
//int suma = 0;
//float promedio;
//int contador = 0;
//
//for (int i = 0; i <sizeM ; i++){
//    if (mascotas[i].idRaza == idRaza && mascotas[i].isFull == 1){
//        suma+= mascotas[i].edad;
//        contador++;
//    }
//}
//promedio = (float) suma /contador;
//return promedio;
//}


void inicializarPaises (e_pais vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}

void mostrarPaises(e_pais paises[], int size){
printf("***PAISES***       (Nombre)             (Continente)     (Codigo Telefonico)   (Id Pais)\n");
for(int i = 0; i <size ; i++){
    if (paises[i].isFull == 1){
        printf("%d.     %20s         %15s             %3d             %d\n",i+1,paises[i].nombreDePais,paises[i].continente,paises[i].codigoTelefonico,paises[i].idPais);
    }
}
}

void hardcodearPaises (e_pais paises[],int size){
int idsPais [5] = {10000,10521,10818,10451,10651};
int codigos [5] = {54,49,32,66,98};
char nombres[5][30] = {"Argentina","Alemania","Belgica","Tailandia","Persia"};
char continentes [5][20] = {"America del Sur","Europa","Europa","Asia","Asia"};

for (int i = 0; i<size; i++){
    paises[i].idPais = idsPais[i];
    paises[i].codigoTelefonico = codigos[i];
    strcpy(paises[i].nombreDePais,nombres[i]);
    strcpy(paises[i].continente,continentes[i]);
    paises[i].isFull = 1;
}
}


int getRaza (e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP)
{
    system("cls");
    int i = getEmptySlotRaza(razas,sizeR);
    int todoBien = 0;
    int aux;
    int auxTam;
    int auxPais;

    if (i != -1)
    {
        printf("****ALTA DE RAZA****\n");
        do
        {
            if (ac_getInt(&aux,1000,9999,"Ingese ID de Raza: (xxxx)",3)== -1)
            {
                break;
            }
            else if (buscarRaza(aux,razas,sizeR)== -1)
            {
                razas[i].id = aux;
                if (ac_getString(razas[i].descripcion,30,1,"\nIngrese nombre de la raza: ") == -1)
                {
                    break;
                }
                normalizeString( razas[i].descripcion);

                mostrarPaises(paises,sizeP);
                if (ac_getInt(&auxPais,1,sizeP,"\nIngrese pais : ",3)==-1)
                {
                    break;
                }
                razas[i].idPaisDeOrigen = paises[auxPais-1].idPais;

                mostrarTamanios(tamanios,sizeTam);
                if (ac_getInt(&auxTam,1,sizeTam,"\nIngrese tamanio : ",3)==-1)
                {
                    break;
                }
                razas[i].size = tamanios[auxTam-1].size;

                printf("\n");

            }
            else
            {
                printf("\nEl ID que ha ingresado ya corresponde a una raza en el sistema.\n");
                system("pause");
                break;
            }
            razas[i].isFull = 1;
            printf("\nAlta de raza realizada con exito. \n\n\n");
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

int conseguirIndicePaisPorId (int id, e_pais paises[],int sizeP){
int indice;
for (int  i = 0; i<sizeP;i++){
    if (paises[i].idPais == id){
        indice = i;
        break;
    }
}
return indice;

}

void mostrarMascota (e_Mascota x,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP)
{
    int indiceT = conseguirIndiceTipo(x,tipos,sizeT);
    int indiceR = conseguirIndiceRaza(x,razas,sizeR);
    int indiceTam = conseguirIndiceTamanioPorRaza(razas[indiceR],tamanios,sizeTamanios);
    int indicePais = conseguirIndicePaisPorId( razas[indiceR].idPaisDeOrigen,paises,sizeP);
    printf("%10d     %10s        %2d          %c %15s  %15s         %10s     %.1f %20s\n",x.id,x.nombre,x.edad,x.sexo,tipos[indiceT].descripcion,razas[indiceR].descripcion,tamanios[indiceTam].descripcion,x.peso,paises[indicePais].nombreDePais);
}

void mostrarMascotas(e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP)
{
    int flag = 0;

    for (int i = 0; i<size; i++)
    {
        if (mascotas[i].isFull == 1)
        {
            flag = 1;
            mostrarMascota(mascotas[i],tipos,sizeT,razas,sizeR,tamanios,sizeTamanios,paises,sizeP);
        }
    }

    if (flag == 0)
    {
        printf("No hay mascotas que mostrar\n");
    }
}

void mostrarTodasMascotasPorRaza (e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP){

for (int i = 0;i<sizeR; i++){
    if (razas[i].isFull == 1){
        int indiceTam = conseguirIndiceTamanioPorRaza(razas[i],tamanios,sizeTamanios);
        int indicePais = conseguirIndicePaisPorId(razas[i].idPaisDeOrigen,paises,sizeP);
        printf("RAZA:%15s      TAMANIO:%10s      PAIS DE ORIGEN:%20s\n",razas[i].descripcion,tamanios[indiceTam].descripcion,paises[indicePais].nombreDePais);

        mostrarMascotasPorRaza(mascotas,size,tipos,sizeT,razas,sizeR,tamanios,sizeTamanios,razas[i].id);
    printf("\n");
    }
}
}



void mostrarMascotaConEncabezados (e_Mascota x,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP)
{
    int indiceT = conseguirIndiceTipo(x,tipos,sizeT);
    int indiceR = conseguirIndiceRaza(x,razas,sizeR);
    int indiceTam = conseguirIndiceTamanioPorRaza(razas[indiceR],tamanios,sizeTamanios);
    int indicePais = conseguirIndicePaisPorId(razas[indiceR].idPaisDeOrigen,paises,sizeP);
    printf("ID                NOMBRE       EDAD        SEXO           TIPO             RAZA            TAMANIO    PESO        PAIS DE ORIGEN\n");
    printf("%10d     %10s        %2d          %c %15s  %15s         %10s     %.1f %20s\n",x.id,x.nombre,x.edad,x.sexo,tipos[indiceT].descripcion,razas[indiceR].descripcion,tamanios[indiceTam].descripcion,x.peso,paises[indicePais].nombreDePais);
}

void mostrarPaisesConMasMascotas (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR,e_pais paises[],int sizeP){
char countries[sizeR][30];
int j,k;

for (int i = 0;i<sizeR;i++){
    int indicePais = conseguirIndicePaisPorId(razas[i].idPaisDeOrigen,paises,sizeP);
    strcpy(countries[i],paises[indicePais].nombreDePais);
}
int n = sizeR;

for (int i = 0;i < n;i++){
    for (j = i+1;j<n;){
        if (strcmp(countries[i],countries[j])== 0){
            for (k = j;k < n ; k++){
                strcpy(countries[k],countries[k+1]);
            }
            n--;
        }
        else {
            j++;
        }
    }
}


char paises2 [n][30];
for (int i = 0; i<n ; i++){
strcpy(paises2[i],countries[i]);
}

int contadores[n];
for (int i = 0; i< n ; i++){
    contadores[i] = 0;
}

int indice2;
int indice3;

for (int m = 0; m < sizeM ; m++){
        if (mascotas[m].isFull == 1){
        indice2 = conseguirIndiceRaza(mascotas[m],razas,sizeR);
        indice3 = conseguirIndicePaisPorId(razas[indice2].idPaisDeOrigen,paises,sizeP);

        for (int l = 0; l<n ; l++){
        if (strcmp(paises[indice3].nombreDePais,paises2[l]) == 0){
            contadores[l]++;
            break;
        }
        }
    }
    }

int max = sacarMaximo(contadores,n);

printf("PAISES CON MAYOR CANTIDAD DE MASCOTAS: \n\n");
for (int i = 0; i<n ; i++){
    if (contadores[i] == max){
        printf("Pais de Origen: %20s     , Cantidad de mascotas: %d\n",paises2[i],contadores[i]);
    }
}
}

void mostrarRazasCompletas (e_Raza razas[],int size,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP){
printf("RAZAS          (Descripcion)          (Tamanio)             (Pais de Origen)      (#ID)    :\n");
for (int i = 0;i<size; i++){
int indiceTam = conseguirIndiceTamanioPorRaza(razas[i],tamanios,sizeTam);
int indicePais = conseguirIndicePaisPorId(razas[i].idPaisDeOrigen,paises,sizeP);
if (razas[i].isFull == 1){
printf("%d.  %20s         %10s %30s       %d\n",i+1,razas[i].descripcion,tamanios[indiceTam].descripcion,paises[indicePais].nombreDePais,razas[i].id);
}
}
}

void mostrarRazaCompleta (e_Raza x,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP){
printf("RAZAS          (Descripcion)          (Tamanio)             (Pais de Origen)      (#ID)    :\n");
int indiceTam = conseguirIndiceTamanioPorRaza(x,tamanios,sizeTam);
int indicePais = conseguirIndicePaisPorId(x.idPaisDeOrigen,paises,sizeP);
if (x.isFull == 1){
printf(" %20s         %10s %30s       %d\n",x.descripcion,tamanios[indiceTam].descripcion,paises[indicePais].nombreDePais,x.id);
}
}

void ordenarMascotasPorCodigoTelefonico (e_Mascota mascotas[],int sizeM,e_Raza razas[],int sizeR,e_pais paises[],int sizeP){
e_Mascota aux;
for (int i = 0 ; i < sizeM-1 ; i++){
        int indiceRazaI = conseguirIndiceRaza(mascotas[i],razas,sizeR);
        int indicePaisI = conseguirIndicePaisPorId(razas[indiceRazaI].idPaisDeOrigen,paises,sizeP);
        int codigoTelI = paises[indicePaisI].codigoTelefonico;

    for (int j = i+1 ; j<sizeM; j++){

        int indiceRazaJ = conseguirIndiceRaza(mascotas[j],razas,sizeR);
        int indicePaisJ = conseguirIndicePaisPorId(razas[indiceRazaJ].idPaisDeOrigen,paises,sizeP);
        int codigoTelJ = paises[indicePaisJ].codigoTelefonico;


        if (mascotas[i].isFull == 1 && mascotas[j].isFull == 1 && codigoTelJ > codigoTelI){
            aux = mascotas[i];
            mascotas[i] = mascotas[j];
            mascotas[j] = aux;
        }
    }
}
}

void eliminarRaza (e_Mascota mascotas[],int size,e_Tipo tipos[],int sizeTipos, e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam,e_pais paises[],int sizeP){
    int aux;
    int indiceRazaBaja;
    char confirmar;
    system("cls");
    printf("****BAJA DE RAZA****\n");
    ac_getInt(&aux,0,9999,"Ingrese ID de raza a dar de baja (xxxx) :",3);
    indiceRazaBaja = buscarRaza(aux,razas,sizeR);
    if ( indiceRazaBaja == -1)
    {
        printf("La raza que desea dar de baja no existe.\n");
        system("pause");
    }
    else
    {
            system("cls");
            printf("Datos de la raza: \n");
            mostrarRazaCompleta(razas[indiceRazaBaja],tamanios,sizeTam,paises,sizeP);
            printf("\nSeguro que desea continuar? Se perderan todos los datos. (y/n)\n");
        fflush(stdin);
        scanf("%c",&confirmar);
        if (confirmar == 'y')
        {
            for (int i = 0; i <size; i++){
                if (mascotas[i].isFull == 1 && mascotas[i].idRaza == razas[indiceRazaBaja].id){
                    mascotas[i].isFull = 0;
                }
            }

            razas[indiceRazaBaja].isFull = 0;
            razas[indiceRazaBaja].id = -1;
            razas[indiceRazaBaja].idPaisDeOrigen = -1;
            strcpy(razas[indiceRazaBaja].descripcion,"");
            razas[indiceRazaBaja].size = ' ';
            printf("\nBaja de raza realizada con exito. \n");
            system("pause");
        }
        else
        {
            printf("\nBaja cancelada\n");
            system("pause");
        }
    }

}

float sacarPesoTotalPorTamanio (char tamanioElejido,e_Mascota mascotas[],int size,e_Raza razas[],int sizeR,e_Tamanio tamanios[],int sizeTam){
float suma = 0;

printf("%c",tamanioElejido);

for (int i = 0; i<size; i++){
        int indiceR = conseguirIndiceRaza(mascotas[i],razas,sizeR);
        int indiceTam = conseguirIndiceTamanioPorRaza(razas[indiceR],tamanios,sizeTam);

    if (tamanioElejido == tamanios[indiceTam].size && mascotas[i].isFull){
        suma+= mascotas[i].peso;
    }
}
return suma;
}

void mostrarMascotasPorTamanio(e_Mascota mascotas[],int sizeM,e_Tipo tipos[],int sizeT,e_Raza razas[],int sizeR,e_Tamanio tamanios[], int sizeTamanios,e_pais paises[],int sizeP,char tamanioElejido)
{
    int flag = 0;

    for (int i = 0; i<sizeM; i++)
    {
        if (mascotas[i].isFull == 1){
        int indiceRaza = conseguirIndiceRaza(mascotas[i],razas,sizeR);
        int indiceTamanio = conseguirIndiceTamanioPorRaza(razas[indiceRaza],tamanios,sizeTamanios);
        if (tamanios[indiceTamanio].size == tamanioElejido)
        {
            flag = 1;
            mostrarMascota(mascotas[i],tipos,sizeT,razas,sizeR,tamanios,sizeTamanios,paises,sizeP);
        }
    }
    }
    if (flag == 0)
    {
        printf("No hay mascotas de ese tamanio\n");
    }
}

void listarMascotasPorTamanioAElejir (e_Mascota mascotas[],int sizeM,e_Tamanio tamanios[],int sizeTam,e_Raza razas[],int sizeR,e_Tipo tipos[],int sizeT,e_pais paises[],int sizeP){

int opcion;

mostrarTamanios(tamanios,sizeTam);
if (ac_getInt(&opcion,1,sizeTam,"Ingrese tamanio :",2) == 1){
system("cls");

mostrarMascotasPorTamanio(mascotas,sizeM,tipos,sizeT,razas,sizeR,tamanios,sizeTam,paises,sizeP,tamanios[opcion-1].size);

float peso = sacarPesoTotalPorTamanio(tamanios[opcion-1].size,mascotas,sizeM,razas,sizeR,tamanios,sizeTam);

printf("\nPeso total de mascotas de tamanio %s : %.2f\n\n",tamanios[opcion-1].descripcion,peso);
}

}


