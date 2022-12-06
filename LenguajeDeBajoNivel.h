/*	Las sigientes dos lineas y la última del archivo, son instrucciones que evitan la 
	redefinición de las funciones y estructuras en caso de haber sido utilizadas con anterioridad
*/
#ifndef LENGUAJE_DE_BAJO_NIVEL_H
#define LENGUAJE_DE_BAJO_NIVEL_H

#include "CodigoTresDirecciones.h"

//Funciones prototipo
void Encabezado();
void CopiaTemporal(struct Temporales *, int);

//Variables globales
const char* NombreArchivo = "Compilador.asm";
FILE *ASM;
//Se crear una variable del tipo Temporal como auxiliar
struct Temporales *Aux = NULL;

//FUNCIÓN QUE CREA EL ARCHIVO *.ASM
void CrearArchivoASM()
{
	int Index = 1;
	int Longitud = nTemp;

    //Crear el archivo ASM con el nombre "Compilador.asm" en modo escritura
    ASM = fopen(NombreArchivo,"w");

    Encabezado();
    //ConsultaTemporal(Aux,Index);
    if(strcmp(Aux->TipoOperacion,"ADD")==0)
    {
    	//Suma();
	}
    
}


void Encabezado()
{
	//Puntero para abriri el archivo de encabezado
	FILE *INI_ASM;
	//Datos que se pueden leer por pasada
	char DatosLeidos[200]; 
	int cantidad;


	//Abre el archivo que contiene el encabezado en modo lectura
	INI_ASM = fopen("Encabezado.txt","r");
	//verifica si el archivo se abre correctamente
	if(!INI_ASM)
	{
		perror("OCURRIO UN ERROR AL ABRIR EL ARCHIVO DEL ENCABEZADO");
		exit(EXIT_FAILURE);
	}
	//Lee el contenido del archivo Encabazado.txt
	while(feof(INI_ASM) == 0)
	{
		fgets(DatosLeidos,200,INI_ASM);
		fprintf(ASM,DatosLeidos);
	}
	
	printf("Datos coopiados aducuadamente\n");
	fclose(ASM);
	fclose(INI_ASM);
}

void CopiaTemporal(struct Temporales *Aux, int Index)
{
    TempAux = inicio;
	while (TempAux != NULL)
	{
		if(TempAux->nTemporal == Index)
		{
				Aux = TempAux;
		}
		else
		{
			TempAux = TempAux->siguiente;
		}
	}
}

#endif //LENGUAJE_DE_BAJO_NIVEL_H