/*	Las sigientes dos lineas y la última del archivo, son instrucciones que evitan la 
	redefinición de las funciones y estructuras en caso de haber sido utilizadas con anterioridad
*/
#ifndef LENGUAJE_DE_BAJO_NIVEL_H
#define LENGUAJE_DE_BAJO_NIVEL_H

#include "CodigoTresDirecciones.h"

//Funciones prototipo
void Encabezado();

const char* NombreArchivo = "Compilador.asm";
FILE *ArchivoASM;
struct Temporales *Aux = NULL;

void CrearArchivoASM()
{
	int Index = 1;
	int Longitud = nTemp;
	
    //Crear el archivo ASM con el nombre "Compilador.asm" en modo escritura
    ArchivoASM = fopen(NombreArchivo,"w");
    Encabezado();
    //ConsultaTemporal(Aux,Index);
    if(strcmp(Aux->TipoOperacion,"ADD")==0)
    {
    	//Suma();
	}
    
}


void Encabezado()
{
	fprintf(ArchivoASM,"%s",".model small \n .data");
	fprintf(ArchivoASM,"%s","\nn1 db 0 \n n2 de 0");
	fclose(ArchivoASM);
}

#endif //LENGUAJE_DE_BAJO_NIVEL_H