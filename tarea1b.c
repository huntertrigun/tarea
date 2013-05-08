#include <stdio.h>
#include <stdlib.h>
const char* DATO1 = "datos1.dat";
const char* DATO2 = "datos2.dat";

int main(int argc, char const *argv[])
{
	FILE *archivo1=fopen(DATO1 , "r");
	FILE *archivo2=fopen(DATO2 , "r");
	FILE *archivo_out=fopen("datos.dat" , "w");
    while (!feof(archivo1))
    {
    	int valor;
    	fread(&valor, sizeof( valor), 1, archivo1);
    	fwrite(&valor, sizeof(valor), 1, archivo_out);
    }
	while (!feof(archivo2))
    {
    	int valor;
    	fread(&valor, sizeof(valor), 1, archivo2);
    	fwrite(&valor, sizeof(valor), 1, archivo_out);
    }
    int otro_rol;
    fread(&otro_rol, sizeof(otro_rol), 1, archivo)

	return 0;
}