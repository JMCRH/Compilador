#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include "TablaDeSimbolos.h"

//Definición de funciones
int Derivaciones(int num, char Tip[3], char Lex[20], char Derivacion[30], char Sustitucion[30]);
int GIC_OperacionesAritmeticas();

/*ESTRUCTURA DE LA GRAMATICA:
S->numOS | numUS | num | id | idOS | idUS
O-> *|/
U-> +|-
*/
int GIC_OperacionesAritmeticas()
{
	printf("\n DERIVACIONES \n");
	char Lex[20];
	char Tip[3];
	int num = 1;
	char Derivacion[30], Sustitucion[30];
	int bandera = 1;
	int longitud = LongitudTS();
	
	
	//Consulta la tabla de simbolos para saber qué lexema se encuentra en la posición num
	ConsultarTipTok(Tip,num);
	//Si es un número entero o decimal, entoncesguarda el lexema en la derivación como num
	if(strcmp(Tip,"NE") == 0 || strcmp(Tip,"ND") == 0)
	{
		//S->num
		strcpy(Derivacion,"S->num");
		strcpy(Sustitucion,"num");
		printf("S ");
	}
	//Si no es un numero, pero es un ID, entonces guarda el lexema en la derivación como id
	else if(strcmp(Tip,"ID") == 0)
	{
		//S->id
		strcpy(Derivacion,"S->id");
		strcpy(Sustitucion,"id");
		printf("S");
	}
	//Si no es ninguno de los anteriores, entonces es un error y no continua con el análisis
	else
	{
		printf("Error de sintaxis\n\n");
		return 0;
	}
	
	//Si se encontró un número o un ID, entonces se procede a verificar si es una operación aritmética
	//Si bandera == 1, entonces no hay errores en sintaxis, si bandera == 0, entonces hay errores en sintaxis y finaliza
	while(bandera == 1)
	{
		num = num + 1;
		if(num <= longitud)
		{
			ConsultarTipTok(Tip,num);
			bandera = Derivaciones(num,Tip,Lex,Derivacion,Sustitucion);
		}
		//Si se trata de un número impar y es mayor a la longitud de la tabla de simbolos, puede ser válida
		else if(num > longitud && (num-1) % 2 != 0)
		{
			printf(" -> %s\n",Sustitucion);
			printf("\n LA CADENA ES VALIDA\n\n");
			bandera = 0;
		}
		else if(num > longitud && (num-1) % 2 == 0)
		{
			printf(" -> %s\n",Sustitucion);
			printf("Error de sintaxis \n\n");
			bandera = 0;
		}
	}
	return 1;
	
}

//fUNCIÓN QUE VERIFICA LAS DERIVACIONES Y REALIZA LAS SUSTITUCIONES
int Derivaciones(int num, char Tip[3], char Lex[20], char Derivacion[30], char Sustitucion[30])
{	
	//Si num es par, debe ser algún signo
	if(num % 2 == 0)
	{
		//OA1-> *|/
		if(strcmp(Tip,"OA1") == 0)
		{
			strcpy(Derivacion,Sustitucion);
			strcat(Derivacion,"OS");
			ConsultarLexema(Lex,num);
			//printf("%s",Lex);
			strcat(Sustitucion,Lex);
			printf(" -> %s -> %sS \n",Derivacion, Sustitucion);
		}
		//OA2-> +|-
		else if(strcmp(Tip,"OA2") == 0)
		{
			strcpy(Derivacion,Sustitucion);
			strcat(Derivacion,"US");
			ConsultarLexema(Lex,num);
			//printf("%s\n",Lex);
			strcat(Sustitucion,Lex);
			printf(" -> %s -> %sS \n",Derivacion, Sustitucion);
		}
		//Si no es ninguna de las anteriores, entonces es un error
		else
		{
			printf("Error de sintaxis\n\n");
			return 0;
		}
		return 1;
	}
	//Si no es par, se debe tratar de un num o un id
	else
	{
		if(strcmp(Tip,"NE") == 0 || strcmp(Tip,"ND") == 0)
		{
			strcpy(Derivacion,Sustitucion);
			strcat(Derivacion,"num");
			//ConsultarLexema(Lex,num);
			//printf("%s",Lex);
			strcat(Sustitucion,"num");			
		}
		else if(strcmp(Tip,"ID") == 0)
		{
			strcpy(Derivacion,Sustitucion);
			strcat(Derivacion,"id");
			//ConsultarLexema(Lex,num);
			//printf("%s",Lex);
			strcat(Sustitucion,"id");
		}
		else
		{
			printf("Error de sintaxis\n\n");
			return 0;
		}
		return 1;
	}
}