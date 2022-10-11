# include <stdio.h>
#define N 3

int Calculo (int arr[], int i)
{
    if (i!=N){
        return arr[i] - Calculo (arr, i+1);
    }
    else {
        return 0;
    }
}

int main() {
    int A[N]={9,5,2};
    printf("Resultado es: %d", Calculo(A,2));
    return 0;
}