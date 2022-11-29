#include <stdio.h>
#include <stdlib.h>
#include "TablaDeSimbolos.h"
#include "AnalisisLexico.h"
#include "AnalisisSintactico.h"
#include "AnalisisSemantico.h"

void VerificarStatus(int bandera)
{
	if (bandera == 0)
	{
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	int op = 0, bandera = 0;
	char Cadena[50];

	//Despliegue de opciones
	printf("\tCALCULADORA COMPILADA \n");
	printf("Escriba la cadena: ");
	fflush(stdin);
	gets(Cadena);
	LeerCadena(Cadena);
	bandera = Analizar();
	VerificarStatus(bandera);

	//Mostrar trabla de simbolos
	printf("\n");
	Imprimir();

	//Verificar gramática
	bandera = GIC_OperacionesAritmeticas();
	VerificarStatus(bandera);

	//Ingreso de tipos de datos para los IDs
	TipoDatoId();

	//Verificacion de tipos de datos asignados
	bandera = VerificarTipos();
	VerificarStatus(bandera);

	//Asignacion de valores en los IDs
	AsignarValores();
	printf("\n");

	//mostrar tabla de simbolos completa
	printf("\n");
	ImprimirCompleta();

/*
	do
	{
		printf("\t------MENU DE OPCIONES------\n\n");
		printf("1.- Ingresar operacion.\n");
		printf("2.- Mostrar Tabla de Simbolos.\n");
		printf("3.- Analizar sintaxis.\n");
		printf("4.- Ingresar tipo de dato.\n");
		printf("5.- Validar tipos de datos.\n");
		printf("6.- Ingresar el valor de los identificadores. \n");
		printf("7.- Salir.\n");
		fflush(stdin);
		printf("Digite el numero de la opcion deseada: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
				printf("Escriba la cadena: ");
				fflush(stdin);
				gets(Cadena);
				LeerCadena(Cadena);
				bandera = Analizar();
				break;
			case 2:
				Imprimir();
				break;
			case 3:
				bandera = GIC_OperacionesAritmeticas();
				break;
			case 4:
				TipoDatoId();
				break;
			case 5:
				bandera = VerificarTipos();
				break;
			case 6:
				AsignarValores();
				break;				
			case 7:
				exit(EXIT_SUCCESS);
				remove("revision.txt");
				break;
		}
	} while (op!=7 && bandera != 0);
	*/
}

//funcion que verifica el estado de la bandera para saber si ha habido errores
