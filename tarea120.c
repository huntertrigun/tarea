#include <stdio.h>
#include <stdlib.h>
const char *DATOS [] = {"datos1.dat", "datos2.dat"};

int main (int argc, char const *argv[])
{
    for (int i = 0; i < 2; ++i)
    {
        FILE *archivo = fopen(DATOS[i], "r");
        printf("Ingrese rol\n");

        int rol;
        scanf("%d", &rol);
        // rol = 201221054;
        while (!feof(archivo))
        {
            int otro_rol;
            fread(&otro_rol, sizeof(otro_rol), 1, archivo);
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
