#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    int num, dni, edad;
    char nomb[15], sexo[15];
} inscriptos;

typedef struct nodo
{
    inscriptos ins;
    struct nodo *sig;
} nodo;

void lista(nodo *&root)
{
    nodo *nuevo;
    char c;
    inscriptos aux;
    FILE *archi = fopen("inscriptos.dat", "rb");
    // aux.num = 1;
    // aux.dni = 40123456;
    // strcpy(aux.nomb, "Fede");
    // aux.edad = 25;
    // strcpy(aux.sexo, "Masculino");
    // fwrite(&aux, sizeof(aux),1, archi);
    while (fread(&aux, sizeof(inscriptos), 1, archi))
    {
        if (aux.edad > 20)
        {
            nodo *nuevo = (nodo *)malloc(sizeof(nodo));
            nuevo->sig = root;
            root = nuevo;
            nuevo->ins = aux;
            printf("%s\n%s", nuevo->ins.nomb, nuevo->ins.sexo);
        }
    }
    printf("\nProceso finalizado\n");
    printf("----------------------\n");
    fclose(archi);
}

int mostrar(nodo *root, int &h, int &m)
{
    if (root != NULL)
    {
        if (stricmp(root->ins.sexo, "Masculino") == 0)
        {
            h++;
        }

        else
        {
            m++;
        }
        return mostrar(root->sig, h, m);
    }
    else
    {
        return 0;
    }
}

void modificar(nodo *root){
    int a, e;
    nodo *actual = root;
    printf("Ingresar numero de inscripto: ");
    scanf("%d", &a);
    while (actual != NULL && actual->ins.num != a)
    {
       actual = actual->sig;
    }
    if(actual == NULL){
        printf("No se encontro el numero");
    }
    else {
        printf("Ingerese la nueva edad: ");
        scanf("%d", &e);
        actual->ins.edad = e;
        printf("Nueva edad: %d", root->ins.edad);
    }
    FILE * archi = fopen("inscriptos.dat", "wb");
    while (root != NULL)
    {
        fwrite(&root->ins, sizeof(root->ins), 1, archi);
        root = root->sig;
    }
    fclose(archi);
}

int main()
{
    int h = 0, m = 0;
    nodo *root = NULL;
    lista(root);
    mostrar(root, h, m);
    printf("Hombre: %d, Mujeres: %d", h, m);
    modificar(root);
}
