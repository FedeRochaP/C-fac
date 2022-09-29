#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3

int load(int array[M][N], int i, int j){
    if (i<M)
    {
        if (j<N)
        {
            printf("Ingrese un valor para la posicion [%d][%d]: ", i+1, j+1, array[i][j]);
            scanf("%d", array[i][j]);
            return load(array, i, j+1);
        }
        else {
            // return load(array, i, j);
            return load(array, i+1, j);
        }
    }
    else
    {
        return 0;
    }
    
}

int main(){
    int array[M][N], i=0, j=0;
    load(array,i,j);
}