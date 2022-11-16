#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    char nomb[15], sexo[15];
    int dni, edad, cod;
} trabajo;

typedef struct nodo
{
    trabajo tra;
    struct nodo *sig;
} nodo;

void carga(nodo *&root)
{
    int x;
    nodo *nuevo;
    printf("Ingrese documento(0: Para terminar): ");
    scanf("%d", &x);
    if (x != 0)
    {
        nodo *nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->sig = root;
        root = nuevo;
        nuevo->tra.dni = x;
        printf("Ingrese nombre: ");
        scanf("%s", &nuevo->tra.nomb);
        printf("Ingrese sexo: ");
        scanf("%s", &nuevo->tra.sexo);
        printf("Ingrese edad: ");
        scanf("%d", &nuevo->tra.edad);
        printf("Ingrese codigo de localidad: ");
        scanf("%d", &nuevo->tra.cod);
        return carga(root);
    }
    else
        return;
}

void show(nodo *root)
{
    if (root != NULL)
    {
        if (root->tra.edad > 20)
        {
            show(root->sig);
            printf("Nombre: %s\nDNI: %d\n", root->tra.nomb, root->tra.dni);
            return;
        }
        return show(root->sig);
    }
}

int postulante(nodo *root)
{
    if (root != NULL)
    {
        if ((root->tra.cod == 1))
        {
            return 1;
        }
        return postulante(root->sig);
    }
    else
    {
        return (0);
    }
}

void varones(nodo *root, int &var)
{
    if (root != NULL)
    {
        if (root->tra.cod == 19)
        {
            var++;
            return varones(root->sig, var);
        }
        return varones(root->sig, var);
    }
    else
    {
        printf("Cantidad de varones %d", var);
    }
}

int main()
{
    int var = 0;
    nodo *root = NULL;
    carga(root);
    show(root);
    if (postulante(root) == 1)
    {
        printf("Se encontro un participante en la localida 1");
    }
    else
    {
        printf("No se encontro participante en la localidad 1");
    }
    varones(root, var);
}
