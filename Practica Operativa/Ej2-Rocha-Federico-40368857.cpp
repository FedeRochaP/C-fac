// Rocha Cueli Federico Agustín
// 40368857
// 21076
// LSI

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int sueldo;
    char nomb[15];
} afiliados;

typedef struct nodo
{
    afiliados afil;
    struct nodo *sig;
} nodo;

void carga(nodo *&root)
{
    char nombre[15];
    printf("-----------------------------------\n");
    printf("Ingrese el nombre del afiliado (fin: Terminar): ");
    scanf("%s", &nombre);
    if (stricmp (nombre, "fin"))
    {
        nodo *nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->sig = root;
        root = nuevo;
        printf("Ingrese el sueldo: ");
        scanf("%d", &nuevo->afil.sueldo);
        strcpy (nuevo->afil.nomb,nombre);
        return carga(root);
    }
    else
        return;
}

void recorre(nodo *root)
{
    if (root != NULL)
    {
        recorre(root->sig);
        printf("Nombre: %s, Sueldo: %d \n", root->afil.nomb, root->afil.sueldo);
        printf("-----------------------------------\n");
        return;
    }
    else
        return;
}

float prom(nodo *root)
{
    int suma=0, cont=0;
    while (root != NULL)
    {
        cont++;
        suma += root->afil.sueldo;
        root = root->sig;
    }
    return (suma/cont);
}



int main(void)
{
    float promedio;
    nodo *root = NULL;
    carga(root);
    recorre(root);
    promedio = prom(root);
    printf("El promedio de sueldos es: %f", promedio);
    return 0;
}

