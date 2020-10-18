#ifndef FUNCIONES_ADICIONALES_H_INCLUDED
#define FUNCIONES_ADICIONALES_H_INCLUDED


#endif // FUNCIONES_ADICIONALES_H_INCLUDED

/** \brief Normaliza una cadena de caracteres. Primero la pasa a lower case y luego pone en mayuscula la primera letra de cada palabra o nombre.
ej: "AGUSTIN coria" --> "Agustin Coria"
 *
 * \param cadena a normalizar
 *
 */
void normalizeString (char a[]);

/** \brief calcula el maximo entre un vector de integros
 *
 * \param vector de integros
 * \param tamanio de vector
 * \return max
 *
 */
int sacarMaximo (int vec[],int size);
