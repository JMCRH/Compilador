#include <stdio.h>
#include <stdlib.h>
#include "TablaDeSimbolos.h"
#include "AnalisisLexico.h"
#include "AnalisisSintactico.h"
#include "AnalisisSemantico.h"

int main(int argc, char *argv[])
{
	int op = 0, bandera = 0;
	char Cadena[50];

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
				VerificarTipos();
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
}