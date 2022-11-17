#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include "TablaDeSimbolos.h"

void generarCodigoTresDirecciones();

struct ArregloMejorado
{
    char Lexemas[20];
    char Codigos[20];
};

void generarCodigoTresDirecciones()
{
    //Obtener la longitud de la tabla
    int longitud = LongitudTS();
    ArregloMejorado Lista [longitud];
    int num = 1;

    //Recorrer la tabla de simbolos
    for(int i= 0; i < longitud ; i++ )
    {
        ConsultarLexema(Lista->Lexemas, num);
        

    }

}