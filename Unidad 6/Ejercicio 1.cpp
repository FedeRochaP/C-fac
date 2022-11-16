#include <stdio.h>
#include <stdlib.h>

// typedef struct FILE
//{
//     char name[15];
//     int age;
// };

typedef struct
{
    int num;
    char nom[15];
} datos;

void carga(datos dat[3], FILE *fichero)
{
    fichero = fopen("fichero.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d", &dat[i].num);
        fflush(stdin);
        printf("Ingrese un nombre: ");
        scanf("%s", &dat[i].nom);
        fwrite(&dat, sizeof(datos), 1, fichero);
        
    }
    fflush;
    fclose(fichero);
}

void listar(datos dat[3], FILE *fichero)
{
    int i=0;
    fichero = fopen("fichero.txt", "r");
    fread(&dat, sizeof(datos), 1, fichero);
    while (!feof(fichero))
    {
        printf("%d %s \n", dat[i].num, dat[i].nom);
        i++;
        fread(&dat, sizeof(datos), 1, fichero);
    }
    fclose(fichero);
}

int main()
{
    datos dat[3];
    FILE *fichero;
    carga(dat, fichero);
    listar(dat, fichero);
    printf("Proceso completado");
    return 0;
}
