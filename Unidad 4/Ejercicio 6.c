#include <stdio.h>
#define N 6

int load(int array[N], int i){
    int a;
    if(i<N){
        printf("Ingrese un valor N° %d: ", i+1);
        scanf("%d", &a);
        array[i] = a;
        return load(array, i+1);
    }
    else {
        return 0;
    }
}

int show(int array[N], int i){
    if (i<N)
    {
        printf("Valor de posición %d: %d\n", i+1, array[i]);
        return show(array, i+1);
    }
    else {
        return 0;
    }
}

int major(int array[N], int i, int major1){
    if (i<N)
    {
        if (major1<array[i])
        {
            return major(array, i+1, major1=array[i]);
        }
        else {
            return major(array, i+1, major1=major1);
        }
    }   
    else {
        return printf("El mayor numero es: %d", major1);
    }
}

int main(){
    int array[N] = {0,0,0,0,0,0}, i=0, major1=0;
    load(array, i);
    printf("-------------------\n");
    show(array, i);
    printf("-------------------\n");
    major(array, i, major1);
}