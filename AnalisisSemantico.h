#include "TablaDeSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Definición de funciones prototipo
//void VerificarTipos();

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
            //Si no es un ID, pero es un Numero Entero o Decimal, se asigna el tipo de dato correspondiente
			else if(strcmp(aux -> TipTok,"NE"))
			{
                strcpy(aux -> TipoId,"NumE");
				aux = aux->Sig;
			}
            else if(strcmp(aux -> TipTok,"ND"))
            {
                strcpy(aux -> TipoId,"NumD");
                aux = aux->Sig;
            }
            /*Si no es ni un ID, ni un Numero Entero o Decimal, se pasa al siguiente 
            elemento de la tabla de simbolos. Se asume que es un operador*/
            else
            {
                strcpy(aux -> TipoId," ");
                aux = aux->Sig;
            }
		}
	}
	printf("Se ha ingresado el tipo de dato de los identificadores.\n");
	printf("_________________________________________\n");
}

//FUNCIÓN PARA VERIFICAR QUE LOS TIPOS DE DATOS DE LA OPERACIÓN SEAN VÁLIDOS
void VerificarTipos()
{
    char TipoPrincipal[4];
    char Tipo[4];
    int Index = 1;
    int Longitud = LongitudTS();
    bool Error = false;

    //Se obtiene el tipo de dato de la variable o ID principal
    ConsultarTipos(TipoPrincipal, Index);
    Index += 2;

    //Si el ID principal es un Numero Entero
    if (strcmp(TipoPrincipal,"NumE")==0)
    {
        //Consulta el tipo de dato de los siguiente 
        while (Index <= Longitud)
        {
            ConsultarTipos(Tipo, Index);
            //Si el tipo de los demás elementos es diferenete a Numero Entero, se marca un error
            if (strcmp(TipoPrincipal,Tipo) != 0)
            {
                Error = true;
                break;
            }
            Index+= 2;           
        }   
        if (Error == true)
        {
            printf("Error: Los tipos de datos de la operacion no son validos.\n");
            printf("No se permite el estrechamiento de tipos de datos.\n");
        }
        else
        {
            printf("=== LOS TIPOS DE DATOS SON VALIDOS ===\n");
        }
        
    }
    /*  Si el ID principal no es un Numero Entero pero es un Numero decimal
        Entonces se aceptara que una operacion contenga decimales y enteros,
        Pues se realiza un ensanchamiento de tipos de datos
    */
    else if (strcmp(TipoPrincipal,"NumD")==0)
    {
        printf("=== LOS TIPOS DE DATOS SON VALIDOS ===\n");
    }
    
    
    
    
    
}