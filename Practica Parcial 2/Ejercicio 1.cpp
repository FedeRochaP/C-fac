#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define N 3

typedef struct
{
    char nomb[15];
    int tipo, precio, stock;
} productos;

void carga(productos *prod)
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese nombre del producto: ");
        scanf("%s", &prod[i].nomb);
        printf("Ingrese el tipo (1:bazar, 2:muebles, 3:manteleria): ");
        scanf("%d", &prod[i].tipo);
        printf("Ingrese precio de venta: ");
        scanf("%d", &prod[i].precio);
        printf("Ingrese el stock del producto: ");
        scanf("%d", &prod[i].stock);
    }
}

void mayor(productos *prod, int *a, int *b, int i)
{
    if (i < N)
    {
        if (prod[i].tipo == 2)
        {
            if (prod[i].precio >= 1000)
            {
                (*a)++;
            }
            if (prod[i].stock == 0)
            {
                (*b)++;
            }
            return mayor(prod, a, b, i + 1);
        }
        return mayor(prod, a, b, i + 1);
    }
}

void prom(productos *prod)
{
    int i, suma = 0, cont = 0, tot;
    for (i = 0; i < N; i++)
    {
        if (prod[i].tipo == 2)
        {
            suma += prod[i].precio;
            cont++;
        }
    }
    tot = suma / cont;
    printf("Promedio: %d\n", tot);
}

void show(productos *prod, int i)
{
    if (i < N)
    {
        printf("Nombre: %s\nPrecio: %d\n", prod[i].nomb, prod[i].precio);
        return show(prod, i + 1);
    }
}

int main()
{
    int i = 0, a = 0, b = 0;
    productos *prod = (productos *)malloc(sizeof(productos) * N);
    carga(prod);
    mayor(prod, &a, &b, i);
    printf("Mayores a $1000: %d\nIguales a stock 0: %d\n", a, b);
    prom(prod);
    show(prod,i);
}
