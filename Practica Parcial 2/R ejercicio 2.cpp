#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char pais[15], cont[15];
    int puntos;
} mundial;

typedef struct nodo
{
    mundial mun;
    struct nodo *sig;
} nodo;

void carga(nodo *&root)
{
    char x[15];
    printf("Ingrese pais(fin: Para terminar): ");
    scanf("%s", &x);
    if (stricmp(x, "fin"))
    {
        nodo *nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->sig = root;
        root = nuevo;
        strcpy(nuevo->mun.pais, x);
        printf("Ingrese continente: ");
        scanf("%s", &nuevo->mun.cont);
        printf("Ingrese puntos: ");
        scanf("%d", &nuevo->mun.puntos);
        return carga(root);
    }
    else
        return;
}

void cantidad(nodo *root, int &cont)
{
    if (root != NULL)
    {
        if (stricmp(root->mun.cont, "Europa") == 0)
        {
            cont++;
            return cantidad(root->sig, cont);
        }
        return cantidad(root->sig, cont);
    }
}

void eliminar(nodo *root, nodo *ant)
{
    if (root != NULL)
    {
        if (stricmp(root->mun.pais, "Brasil") == 0)
        {
            ant->sig = root->sig;
            free(root);
            
        }
        else
        	eliminar(root->sig, ant->sig);
    }
}

void recorre(nodo *root)
{
    if (root != NULL)
    {
        recorre(root->sig);
        printf("Pais: %s\nContinente: %s\nPuntos: %d\n", root->mun.pais, root->mun.cont, root->mun.puntos);
        return;
        return recorre(root->sig);
    }
}

void puntos(nodo *root)
{
	int a;
    char x[15];
    printf("Ingrese un pais: ");
    scanf("%d", &x);
    while ((root != NULL) && !stricmp(root->mun.pais, x))
    {
        root = root->sig;
    }
    if (root == NULL)
    {
        printf("No se encontro en pais");
    }
    else
    {
        printf("Ingrese el nuevo puntaje: ");
        fflush(stdin);
        scanf("%d", &a);
        root->mun.puntos = a;
    }
}

int main()
{
    int cont = 0;
    nodo *root = NULL;
    carga(root);
    cantidad(root, cont);
    printf("Cantidad de paises Europeos: %d\n", cont);
//    eliminar(root, root);
    recorre(root);
    puntos(root);
    recorre(root);
}
