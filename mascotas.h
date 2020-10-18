#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct {
int id;
char nombre[20];
int edad;
char sexo;
int idTipo;
int idRaza;
float peso;
int isFull;
} e_Mascota;

typedef struct {
int id;
char descripcion[20];
} e_Tipo;

#endif // MASCOTAS_H_INCLUDED




