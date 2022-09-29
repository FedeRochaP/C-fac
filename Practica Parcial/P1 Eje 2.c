#include <stdio.h>
#define N 3

struct sucursal
{
    int ven, emp;
};

void carga(struct sucursal suc[N])
{
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("Ingrese el número de empleados: ");
        scanf("%d", &suc[i].emp);
        printf("Ingrese la ventas totales del mes: ");
        scanf("%d", &suc[i].ven);
    }
}

void show(struct sucursal suc[3]) {
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Epleados empresa n°%d: %d\n", i, suc[i].emp);
        printf("Ventas totales: %d \n\n", suc[i].ven);
    }
}

int empleados(struct sucursal suc[3], int a[N]){
    int i;
    for ( i = 0; i < N; i++)
    {
        if (suc[i].emp>12)
        {
            a[i] = i;
        }
        else if (suc[i].emp<6)
        {
            return printf("La empresar %d tiene menos de 6 empleados", i);
        }
        
        
    }
    
}

int main()
{
    int a[N], i;
    struct sucursal suc[N];
    carga(suc);
    show(suc);
    for (i = 0; i < N; i++)
    {
        printf("La empresa %d tiene mas de 12 empledos", a[i]);
    }
    
    return 0;
}
