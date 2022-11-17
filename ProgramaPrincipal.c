#include <stdio.h>
#include <stdlib.h>
#include "TablaDeSimbolos.h"
#include "AnalisisLexico.h"
#include "AnalisisSintactico.h"

int main(int argc, char *argv[])
{
	int op = 0, bandera = 0;

	do
	{
		printf("\t------MENU DE OPCIONES------\n\n");
		printf("1.- Analizar archivo.\n");
		printf("2.- Mostrar Tabla de Simbolos.\n");
		printf("3.- Analizar sintaxis.\n");
		printf("4.- Ingresar tipo de dato.\n");
		printf("5.- Salir.\n");
		printf("Digite el numero de la opcion deseada: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
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
				exit(EXIT_SUCCESS);
				break;
		}
	} while (op!=5);
}