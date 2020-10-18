#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones_adicionales.h"

void normalizeString (char a[])
{
    strlwr(a);
    a[0] = toupper(a[0]);
    for (int j=0; a[j]!= '\0'; j++)
    {
        if (a[j]== ' ')
        {
            a[j+1] = toupper(a[j + 1]);
        }
    }
}

int sacarMaximo (int vec[],int size){
int max;
int flag = 0;
for (int i = 0; i<size; i++){
if (flag == 0){
    max = vec[i];
    flag = 1;
}
else {
    if (vec[i]>max){
        max = vec[i];
    }
}
}
return max;
}




