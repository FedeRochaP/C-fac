#include <stdio.h>
#define M 2
#define N 2

int main(){
    int var[M][N], i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Por favor ingrese un numero para la posision [%d][%d]: ", i+1, j+1);
            scanf("%d", &var[i][j]);
            printf("------------------------\n");
        }
    }
    
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", var[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    int suma = 0;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
                suma += var[i][j];
        }
        printf("Fila %d total de suma: %d", i, suma);
        suma = 0;
        printf("\n");
    }

    int prom = 0, tot = 0;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j == 1)
            {
                tot += var[i][j];
            }
        }
    }
    printf("\n");
    prom = tot / N;
    printf("Promedio de la tercer columna: %d", prom);  
    printf("\n\n");

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (var[i][j] >= 100)
            {
                printf("El número de la posicion [%d][%d] es mayor a 100\n", i+1, j+1);
            }
        }
    }

}
