#include <stdio.h>
#define N 2
#define M 2

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

void carga(int array[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("Ingrese el sueldo: ");
            scanf("%d", &array[i][j]);
        }
    }
}

void show(int array[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("El sueldo del empleado %d en el mes %d es : %d\n", j, i, array[i][j]);
        }
    }
}

int showRec(int array[N][M], int i, int j)
{
    if (i < N)
    {
        if (i == 2)
        {
            if (j < M)
            {
                printf("El sueldo es: %d", array[i][j]);
                return showRec(array, i, j++);
            }
            else
            {
                return showRec(array, i++, j);
            }
        }
        return showRec(array, i++, j);
    }
}

void prom(int array[N][M])
{
    int i, j, tot;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tot += array[i][j];
        }
    }
    printf("El promedio de suledo es: %d", tot / (N+M));
}

int main()
{
    int array[N][M], i = 0, j = 0;
    cero(array);
    carga(array);
    show(array);
    showRec(array, i, j);
    prom(array);
    return 0;
}
