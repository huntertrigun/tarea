#include <stdio.h>
#include <stdlib.h>
const char *DATOS [] = {"datos1.dat", "datos2.dat"};


int leer_rol (FILE * archivo) {
	// int rol;
	// fread(&rol, sizeof(rol), 1, archivo);
	// return rol;
	static const int BUFFER_SIZE = 128*1024;
	static int buffer[BUFFER_SIZE];
	static int counter = 0;
	static FILE * archivo_interno = NULL;

	if (archivo_interno != archivo)
	{
		counter = 0;
		archivo_interno = archivo;
	}

	if (counter == BUFFER_SIZE)
	{
		counter = 0;
	}

	if (counter == 0)
	{
		fread(buffer, sizeof(*buffer), BUFFER_SIZE, archivo_interno);
	}

	return buffer[counter++];
}

int main (int argc, char const *argv[])
{
    for (int i = 0; i < 2; ++i)
    {
        FILE *archivo = fopen(DATOS[i], "r");
        printf("Ingrese rol\n");

        int rol = 201221054;
        scanf("%d", &rol);
        while (!feof(archivo))
        {
            int otro_rol = leer_rol(archivo);
            
            if (rol == otro_rol)
            {
                printf("el rol se encuentra en el %s en la linea %d \n", "archivo1", ftell(archivo) / sizeof(otro_rol));
                fclose(archivo);
                return 0;
            }	

        }

        fclose(archivo);
    }
    return 1;
}
