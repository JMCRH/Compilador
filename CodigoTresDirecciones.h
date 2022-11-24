/*	Las sigientes dos lineas y la última del archivo, son instrucciones que evitan la 
	redefinición de las funciones y estructuras en caso de haber sido utilizadas con anterioridad
*/
#ifndef CODIGO_TRES_DIRECCIONES_H
#define CODIGO_TRES_DIRECCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include "TablaDeSimbolos.h"

//Funciones prototipo
void generarCodigoTresDirecciones();

struct Temporales
{
    char nTemporal[4];
    char Operando1[5];
    char Operando2[5];
    char Operador[3];
};


#endif // CODIGO_TRES_DIRECCIONES_H