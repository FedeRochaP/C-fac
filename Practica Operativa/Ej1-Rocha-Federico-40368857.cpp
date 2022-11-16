// Rocha Cueli Federico Agustín
// 40368857
// 21076
// LSI

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    int cod, precio;
} produ;

int carga(produ *productos, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese el codigo del producto:");
        scanf("%d", &productos[i].cod);
        printf("Ingrese el precio del producto:");
        scanf("%d", &productos[i].precio);
        printf("-----------------------------------\n");
    }
}

int muestra(produ *productos, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("El codigo del producto %d es: %d\n", i+1, productos[i].cod);
        printf("El precio del producto %d es: %d\n", i+1, productos[i].precio);
        printf("-----------------------------------\n");
    }
}

int masCaro(produ *productos, int tam)
{
    int max=0;
    for (int i = 0; i < tam; i++)
    {
        if(productos[i].precio>productos[max].precio){
            max=i;
        }
    }
    return max;
}

int main()
{
    int tam = 4, maximo;
    produ *productos = (produ *)malloc(sizeof(produ) * tam);
    carga(productos, tam);
    muestra(productos, tam);
    maximo = masCaro(productos, tam);
    printf("El codigo del producto mas caro es %d", productos[maximo].cod);
}
