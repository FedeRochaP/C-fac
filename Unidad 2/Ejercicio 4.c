#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 5
#define N 2

struct proveedor
{
    char name[20];
    int provNum;
};

struct producto
{
    int code, price, stock;
};

void provLoad(struct proveedor prov[M])
{
    int i;
    for (i = 0; i < M; i++)
    {
        printf("Ingrese el nombre del proveedor: ");
        scanf("%s", &prov[i].name);
        printf("Ingrese el número del proveedor (1000-1022): ");
        scanf("%d", &prov[i].provNum);
        printf("\n");
    }
}

void prodLoad(struct producto prod[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Ingrese el codigo del producto: ");
        scanf("%d", &prod[i].code);
        printf("Ingrese el precio del producto: ");
        scanf("%d", &prod[i].price);
        printf("Ingrese el stock del producto: ");
        scanf("%d", &prod[i].stock);
        printf("\n");
    }
}

void showProv(struct proveedor prov[M]) {
    int i;
    for (i = 0; i < M; i++)
    {
        printf("Proveedor: %s\n Número de Proveedor: %d", prov[i].name, prov[i].provNum);
        printf("\n");
        printf("-----------------------\n");
        printf("\n");
    }
}

void showProd(struct producto prod[N]) {
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Producto n°%d\nCodigo: %d\nPrecio: %d\nStock: %d ", i, prod[i].code, prod[i].price, prod[i].stock);
        printf("\n");
        printf("-----------------------\n");
        printf("\n");
    }
}

void buy(struct producto prod[N], )

int main()
{
    struct proveedor prov[M];
    struct producto prod[N];
    provLoad(prov);
    printf("-----------------------\n");
    prodLoad(prod);
    printf("-----------------------\n");
    showProv(prov);
    printf("-----------------------\n");
    showProd(prod);
    printf("-----------------------\n");
}