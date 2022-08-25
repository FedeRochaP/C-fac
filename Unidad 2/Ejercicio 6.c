#include <stdio.h>
#define M 3
#define N 3

void cero(int array[M][N]){
    int i, j;
    for ( i = 1; i <= M; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            array[i][j] = 0;
        }   
    }
}

void load (int array[M][N]) {
    int  i=0, j=0;
    char turn;
    printf("Desea cargar un turno (S:para continuar, N:para terminar): ");
    scanf("%c", &turn);
    while (turn == 'S')
    {
        printf("Ingrese la tematica a la que desea ingresar (1-6): ");
        scanf("%d", &i);
        printf("Ingrese el turno al que desa asistir (1-4): ");
        scanf("%d", &j);
        array[i][j] += 1;

        fflush(stdin);
        printf("Desea cargar un turno (S:para continuar, N:para terminar): ");
        scanf("%c", &turn);
    }
}

void showArray (int array[M][N]) {
    int i, j;
    for (i = 1; i <= M; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            printf("La tematica %d, turno %d tiene %d inscriptos", i, j, array[i][j]);
            printf("\n");
        }
        
    }
    
}

void prom(int array[M][N]) {
    int i, j , indi, tot, prom;
    printf("Ingrese el area tematica que desea promerdiar (1-6): ");
    scanf("%d", &indi);
    for ( i = 1; i <= M; i++)
    {
        for ( i = 1; i <= N; i++)
        {
            if (i == indi)
            {
                tot += array [i][j];
            }
            
        }
    }
    prom = tot/M;
    printf("El area ingresada posee un promedio de alumnos de: %d", prom);
    
}

int main(){
    int array[M][M];
    cero(array);
    load(array);
    showArray(array);
    prom(array);
}