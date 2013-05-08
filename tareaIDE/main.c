#include <stdio.h>
#include <stdlib.h>
const char *DATO1 = "/home/labcv/Escritorio/tarea/datos1.dat";
const char *DATO2 = "/home/labcv/Escritorio/tarea/datos2.dat";

int main (int argc, char const *argv[])
{
    FILE *archivo1 = fopen(DATO1, "r");
    FILE *archivo2 = fopen(DATO2, "r");
    printf("Ingrese rol\n");

    int rol;
    // scanf("%d", &rol);
    rol=201221054;
    while (!feof(archivo1))
    {
        int otro_rol;
        fread(&otro_rol, sizeof(otro_rol), 1, archivo1);
        if (rol == otro_rol)
        {
            printf("el rol se encuentra en el archivo %s en la linea %d \n", "archivo1", ftell(archivo1)/sizeof(otro_rol));

        }

    }

    fclose(archivo1);
    fclose(archivo2);
    return 0;
}

