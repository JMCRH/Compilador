/*	Las sigientes dos lineas y la última del archivo, son instrucciones que evitan la 
	redefinición de las funciones y estructuras en caso de haber sido utilizadas con anterioridad
*/
#ifndef LENGUAJE_DE_BAJO_NIVEL_H
#define LENGUAJE_DE_BAJO_NIVEL_H

#include "CodigoTresDirecciones.h"

//Funciones prototipo
void Encabezado();
void MUL();
void DIV();
void ADD();
void SUB();
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
    TempAux = inicio;
	
	while (TempAux != NULL)
	{		
		//Duplica el temporal en una variable global
		Aux = TempAux;
		//Si el tipo de operación es una multiplicacion...
		if(strcmp(TempAux->TipoOperacion,"MUL")==0)
		{
			printf("Multiplicacion\n");
			//Llama a la función que carga una multiplicación en el ASM
			MUL();
			TempAux = TempAux->siguiente;
		}
		else if(strcmp(TempAux->TipoOperacion,"DIV")==0)
		{
			printf("Division\n");
			//Llama a a la función que carga una división en el ASM
			DIV();
			TempAux = TempAux->siguiente;
		}
		else if(strcmp(TempAux->TipoOperacion,"ADD")==0)
		{
			printf("Suma\n");
			//Llama a la función que carga una suma en el ASM
			ADD();
			TempAux = TempAux->siguiente;
		}
		else if(strcmp(TempAux->TipoOperacion,"SUB")==0)
		{
			printf("Resta\n");
			//Llama a la función que carga una resta en el ASM
			SUB();
			TempAux = TempAux->siguiente;
		}
	}
	//Abriri el archivo ASM en modo de "Escritura y Adición"
	ASM = fopen(NombreArchivo,"a");
	//Carga la intruccion de cierre
	fprintf(ASM,".exit");
	//cerrar el archivo ASM
	fclose(ASM);
	//Muestra un mensaje de confirmación
	printf("\nArchivo ** %s **  creado con exito\n\n",NombreArchivo);
}
//FUNCIÓN QUE CARGA LOS VALORES Y LA OPERACIÓN DE MULTIPLICACIÓN EN EL ARCHIVO *.ASM
void MUL()
{
	//Abriri el archivo ASM en modo de "Escritura y Adición"
	ASM = fopen(NombreArchivo,"a");
	//Si el primer operando es un temporal...
	if(Aux->Operando1[0] == 'T')
	{
		//Utiliza el temporal como primer operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV AX, r%s",Aux->Operando1[1]);
	}
	else
	{
		//Si no, utiliza el valor del primer operando
		fprintf(ASM,"MOV AX, %s",Aux->Operando1);
	}
	//Si el segundo operando es un temporal...
	if(Aux->Operando2[0] == 'T')
	{
		//Utiliza el temporal como segundo operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV BX, r%s",Aux->Operando2[1]);
	}
	else
	{
		//Si no, utiliza el valor del segundo operando
		fprintf(ASM,"MOV BX, %s",Aux->Operando2);
	}
	//Realiza la multiplicación
	//Abre la plantilla de multiplicación

	//Cerrar el archivo ASM
	fclose(ASM);
}

//FUNCIÓN QUE CARGA LOS VALORES Y LA OPERACIÓN DE DIVISIÓN EN EL ARCHIVO *.ASM
void DIV()
{
	//Abriri el archivo ASM en modo de "Escritura y Adición"
	ASM = fopen(NombreArchivo,"a");
	//Si el primer operando es un temporal...
	if(Aux->Operando1[0] == 'T')
	{
		//Utiliza el temporal como primer operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV AX, r%s",Aux->Operando1[1]);
	}
	else
	{
		//Si no, utiliza el valor del primer operando
		fprintf(ASM,"MOV AX, %s",Aux->Operando1);
	}
	
	//Si el segundo operando es un temporal...
	if(Aux->Operando2[0] == 'T')
	{
		//Utiliza el temporal como segundo operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV BX, r%s",Aux->Operando2[1]);
	}
	else
	{
		//Si no, utiliza el valor del segundo operando
		fprintf(ASM,"MOV BX, %s",Aux->Operando2);
	}
	//Realiza la división
	//Abre la plantilla de división

	//Cerrar el archivo ASM
	fclose(ASM);
}

//FUNCIÓN QUE CARGA LOS VALORES Y LA OPERACIÓN DE SUMA EN EL ARCHIVO *.ASM
void ADD()
{
	//Abriri el archivo ASM en modo de "Escritura y Adición"
	ASM = fopen(NombreArchivo,"a");
	//Si el primer operando es un temporal...
	if(Aux->Operando1[0] == 'T')
	{
		//Utiliza el temporal como primer operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV AX, r%s",Aux->Operando1[1]);
	}
	else
	{
		//Si no, utiliza el valor del primer operando
		fprintf(ASM,"MOV AX, %s",Aux->Operando1);
	}

	//Si el segundo operando es un temporal...
	if(Aux->Operando2[0] == 'T')
	{
		//Utiliza el temporal como segundo operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV BX, r%s",Aux->Operando2[1]);
	}
	else
	{
		//Si no, utiliza el valor del segundo operando
		fprintf(ASM,"MOV BX, %s",Aux->Operando2);
	}

	//Realiza la suma
	//Abre la plantilla de suma

	//Cerrar el archivo ASM
	fclose(ASM);
}

//FUNCIÓN QUE CARGA LOS VALORES Y LA OPERACIÓN DE RESTA EN EL ARCHIVO *.ASM
void SUB()
{
	//Abriri el archivo ASM en modo de "Escritura y Adición"
	ASM = fopen(NombreArchivo,"a");
	//Si el primer operando es un temporal...
	if(Aux->Operando1[0] == 'T')
	{
		//Utiliza el temporal como primer operando (en el asm llevará el número de resultado)
		fprintf(ASM,"\nMOV AX, r%s\n",Aux->Operando1[1]);
	}
	else
	{
		//Si no, utiliza el valor del primer operando
		fprintf(ASM,"MOV AX, %s",Aux->Operando1);
	}

	//Si el segundo operando es un temporal...
	if(Aux->Operando2[0] == 'T')
	{
		//Utiliza el temporal como segundo operando (en el asm llevará el número de resultado)
		fprintf(ASM,"MOV BX, r%s",Aux->Operando2[1]);
	}
	else
	{
		//Si no, utiliza el valor del segundo operando
		fprintf(ASM,"MOV BX, %s",Aux->Operando2);
	}

	//Realiza la resta
	//Abre la plantilla de resta

	//Cerrar el archivo ASM
	fclose(ASM);
}


//FUNCIÓN QUE CARGA EL ENCABEZADO DEL PROGRAMA EN EL ARCHIVO *.ASM
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
	fclose(INI_ASM);
	//Cierra el archivo ASM
	fclose(ASM);
	printf("Datos copiados aducuadamente\n");
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