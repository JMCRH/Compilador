#include "CodigoTresDirecciones.h"

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
    ConsultaTemporal(Aux,Index);
    if(strcmp(Aux->TipoOperacion,"ADD")==0)
    {
    	Suma();
	}
    
}


void Encabezado()
{
	fprintf(ArchivoASM,"%s",".model small \n .data");
	fprintf(ArchivoASM,"%s","\nn1 db 0 \n n2 de 0");
	fclose(ArchivoASM);
}


void ConultaTemporal()