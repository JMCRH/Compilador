#include "TablaDeSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//FUNCIÓN PARA AGREGAR TIPO DE DATO DE LOS IDENTIFICADORES
void TipoDatoId()
{
	int numAux = 0;
	aux = ini;
	if (ini == NULL)
	{
		printf("\n-------NO EXISTEN ELEMENTOS EN LA TABLA DE SIMBOLOS------\n\n");		
	}
	else
	{
		printf("_________________________________________\n");
		while(aux != NULL)
		{
			//Si se encuentra un ID se pregunta qué tipo de dato es ese ID
			if(strcmp(aux -> TipTok,"ID") == 0)
			{
				printf("El identificador '%s' es un: \n", aux -> Lexema);
				printf("1. Numero Entero \n");
				printf("2. Numero Decimal \n");
				printf("Digita la opcion: ");
				fflush(stdin);
				scanf("%i",&numAux);
				printf("Numero leido: %i\n",numAux);
								
				if (numAux == 1)
				{
					strcpy(aux -> TipoId,"NumE");
				}
				else if (numAux == 2)
				{
					strcpy(aux ->TipoId,"NumD");
				}
				numAux = 0;
				printf("Tipo de dato aignado: %s\n\n", aux -> TipoId);
				aux = aux->Sig;
			}
			else
			{
				aux = aux->Sig;
			}
		}
	}
	printf("Se ha ingresado el tipo de dato de los identificadores.\n");
	printf("_________________________________________\n");
}

///-----------------