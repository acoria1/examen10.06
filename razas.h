#include "mascotas.h"

#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED
typedef struct {
int id;
char descripcion[30];
char size;
int idPaisDeOrigen;
int isFull;
}e_Raza;

typedef struct{
char size;
char descripcion[10];
}e_Tamanio;


#endif // RAZAS_H_INCLUDED


