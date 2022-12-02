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
int generarCodigoTresDirecciones();
void prioridad1() ;
void prioridad2();

//variable global
int nTemp = 1;
char TempText[5] = "T";
char Num[3];

struct Temporales
{
    int nTemporal;
    char Operando1[10];
    char Operando2[10];
    char Operador[10];
    char NotacionPosfija[20];
    char TipoOperacion[4];
    struct Temporales *siguiente;    
};

struct Temporales *inicio = NULL, *final = NULL, *TempAux = NULL;

//Funcion para crear un nuevo temporal
void CrearTemporal(char OP1[5], char OP2[5],char OP[3] ,char Notacion[20],int nTemp)
{
    if(inicio==NULL)
    {
        inicio = malloc(sizeof(struct Temporales));
        inicio->nTemporal = nTemp;
        strcpy(inicio->Operando1,OP1);
        strcpy(inicio->Operando2,OP2);
        strcpy(inicio->Operador,OP);
        strcpy(inicio->NotacionPosfija,Notacion);
        inicio->siguiente = NULL;
        final = inicio;
        if(strcmp(inicio->Operador,"*")==0)
        {
        	strcpy(inicio->TipoOperacion,"MUL");
		}
		else if(strcmp(inicio->Operador,"/")==0)
		{
			strcpy(inicio->TipoOperacion,"DIV")
		}
		else if(strcmp(inicio->Operador,"+")==0)
		{
			strcpy(inicio->TipoOperacion,"ADD")
		}
		else if(strcmp(inicio->Operador,"-")==0)
		{
			strcpy(inicio->TipoOperacion,"SUB")
		}
		else
		{
			printf("\n OCURRIÓ UN ERROR EN LA CREACION DEL TEMPORAL\n");
		}
    }
    }
    }
    else
    {
        TempAux = malloc(sizeof(struct Temporales));
        TempAux->nTemporal = nTemp;
        strcpy(TempAux->Operando1,OP1);
        strcpy(TempAux->Operando2,OP2);
        strcpy(TempAux->Operador,OP);
        strcpy(TempAux->NotacionPosfija,Notacion);
        TempAux->siguiente = NULL;
        final = TempAux;
        if(strcmp(TempAux->Operador,"*")==0)
        {
        	strcpy(TempAux->TipoOperacion,"MUL");
		}
		else if(strcmp(TempAux->Operador,"/")==0)
		{
			strcpy(TempAux->TipoOperacion,"DIV")
		}
		else if(strcmp(TempAux->Operador,"+")==0)
		{
			strcpy(TempAux->TipoOperacion,"ADD")
		}
		else if(strcmp(TempAux->Operador,"-")==0)
		{
			strcpy(TempAux->TipoOperacion,"SUB")
		}
		else
		{
			printf("\n OCURRIÓ UN ERROR EN LA CREACION DEL TEMPORAL\n");
		}
    } 
}


int generarCodigoTresDirecciones()
{
    prioridad1();
    prioridad2();
}

//FUNCION QUE REALIZA LA BUSQUEDA DE OPERADORES DE PRIMER NIVEL
void prioridad1()
{
    printf("Entrando a prioridad 1\n");
    aux = ini;
    char Notacion [20];
    char Operando1[10];
    char Operando2[10];
    char Operador[10];
    while(aux != NULL)
    {
        //Se busca un operador de prioridad 1 (*, /)
        if(strcmp(aux->Lexema,"*")==0 || strcmp(aux->Lexema,"/")==0)
        {
            printf("Encontrado operador de prioridad 1\n");
            //Copia los datos de la operacion (operandos y operador)
            strcpy(Operando1,aux->Ant->ValorId);
            strcpy(Operando2,aux->Sig->ValorId);
            strcpy(Operador,aux->Lexema);
            strcpy(Notacion,Operando1);
            strcat(Notacion,Operando2);
            strcat(Notacion,Operador);
            //Identificador de temporales
            itoa(nTemp,Num,10);
            strcpy(TempText,"T");
            strcat(TempText,Num);
            printf("%s -> ",TempText);
            printf("%s\n",Notacion);
            //Se guardan los valores en la estructura de los temporales
            CrearTemporal(Operando1,Operando2,Operador,Notacion,nTemp);
            if(aux->Ant->Ant != NULL)  
            {
                aux->Ant->Ant->Sig = aux;
                aux->Ant=aux->Ant->Ant;
            }
            else
            {
                aux->Ant=NULL;
                ini=aux;
            }
            if(aux->Sig->Sig != NULL)
            {
                aux->Sig->Sig->Ant = aux;
                aux->Sig=aux->Sig->Sig;
            }
            else
            {
                aux->Sig=NULL;
                fin=aux;
            }
            
            strcpy(aux->ValorId,TempText);
            nTemp++;
        }
        aux=aux->Sig;
    }
}

//FUNCION QUE REALIZA LA BUSQUEDA DE OPERADORES DE SEGUNDO NIVEL (+,-)
void prioridad2()
{
    printf("Entrando a prioridad 2\n");
    aux = ini;
    char Notacion [20];
    char Operando1[5];
    char Operando2[5];
    char Operador[3];
    while (aux!=NULL)
    {
        if (strcmp(aux->Lexema,"+")==0 || strcmp(aux->Lexema,"-")==0)
        {
            printf("Encontrado operador de prioridad 1\n");
            //Copia los datos de la operacion (operandos y operador)
            strcpy(Operando1,aux->Ant->ValorId);
            strcpy(Operando2,aux->Sig->ValorId);
            strcpy(Operador,aux->Lexema);
            strcpy(Notacion,Operando1);
            strcat(Notacion,Operando2);
            strcat(Notacion,Operador);
            //Identificador de temporales
            itoa(nTemp,Num,10);
            strcpy(TempText,"T");
            strcat(TempText,Num);
            printf("%s -> ",TempText);
            printf("%s\n",Notacion);
            //Se guardan los valores en la estructura de los temporales
            CrearTemporal(Operando1,Operando2,Operador,Notacion,nTemp);
            if(aux->Ant->Ant != NULL)  
            {
                aux->Ant->Ant->Sig = aux;
                aux->Ant=aux->Ant->Ant;
            }
            else
            {
                aux->Ant=NULL;
                ini=aux;
            }
            if(aux->Sig->Sig != NULL)
            {
                aux->Sig->Sig->Ant = aux;
                aux->Sig=aux->Sig->Sig;
            }
            else
            {
                aux->Sig=NULL;
                fin=aux;
            }
            strcpy(aux->ValorId,TempText);
            nTemp++;
        }
        aux=aux->Sig;        
    }
    
}

//Función para Consultar el temporal
void ConsultaTemporal(Temporales *AuxT, int Index)
{
	int bandera = 0;
	TempAux = inicio;
	while(TempAux !=NULL)
	{
		if(TempAux->nTemporal == Index)
		{
			AuxT = TempAux;
			bandera = 1;
			break;
		}
		else
		{
			TempAux = TempAux->siguiente;
		}
	}
	if(bandera == 0)
	{
		printf("El Indice no se encuentra\n");
	}
	
}



#endif // CODIGO_TRES_DIRECCIONES_H