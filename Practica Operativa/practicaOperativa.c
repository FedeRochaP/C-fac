// Rocha Cueli Federico Agustín
// 40368857
// 21076
// LSI

#include <stdio.h>
#include <stdlib.h>

#define N 3

void cero (int arrayBi[N][N]){
    int i, j;
    for ( i = 1; i <= N; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            arrayBi[i][j] = 0;
        }   
    }
}


void cargaArray (int arrayBi[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Por favor ingrese un numero para la posision [%d][%d]: ", i+1, j+1);
            scanf("%d", &arrayBi[i][j]);
            printf("------------------------\n");
        }
    }
}

void suma (int arrayBi[N][N]) {
    int i, j, suma=0;
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j){
                suma += arrayBi[i][j];
            }
        }
    }
    printf("La suma total de los elementos de la diagonal es: %d \n", suma);
    printf("\n");
}

void mostrarArray (int arrayBi[N][N]){
    int i,j;
    printf("------------------------\n\n");
    printf("--Matriz--\n\n");
    for (i = 0; i < N; i++)
    {
        printf("| ");
        for (j = 0; j < N; j++)
        {
            printf("%d ", arrayBi[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("------------------------\n");
}

void mayorACero (int arrayBi[N][N]){
    int i, j, mayor=0;
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (arrayBi[i][j] > 0){
                mayor += 1;
            }
        }
    }
    printf("La cantidad total de componentes mayores a cero es: %d \n", mayor);
    printf("\n");
}

int main() {
    int arrayBi[N][N], i, j;
    cero(arrayBi);
    cargaArray(arrayBi);
    suma(arrayBi);
    mostrarArray(arrayBi);
    mayorACero(arrayBi);
}
