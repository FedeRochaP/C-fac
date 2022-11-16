#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M 5

void cero(int array[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            array[i][j] = 0;
        }
    }
}

void tabla(int array[N][M])
{
    int i, j, x, a;
    printf("Desea cargar datos (1: Si, 0: No): ");
    scanf("%d", &x);
    printf("-------------------------------------------\n");
    while (x != 0)
    {
        printf("Ingrese el numero de la provincia: ");
        scanf("%d", &i);
        printf("Ingrese zona: ");
        scanf("%d", &j);
        printf("Ingrese la cantidad de industrias relevadas: ");
        scanf("%d", &a);
        array[i-1][j-1] = array[i-1][j-1] + a;
        printf("-------------------------------------------\n");
        printf("Desea cargar datos (1: Si, 0: No): ");
        scanf("%d", &x);
        printf("-------------------------------------------\n");
    }
    if (x == 0)
    {
        printf("-------------------------------------------\n");
        printf("Caraga finalizada\n");
        printf("-------------------------------------------\n");
    }
}

void show(int array[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("La provicia %d zona %d posee %d industrias\n", i+1, j+1, array[i][j]);
        }
    }
}

void noInd(int array[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (array[i][j] == 0)
            {
                printf("La provicia %d zona %d no posee industrias\n", i+1, j+1);
            }
            
        }
    }
}

int main()
{
    int array[N][M];
    cero(array);
    tabla(array);
    show(array);
    printf("-------------------------------------------\n");
    noInd(array);
}