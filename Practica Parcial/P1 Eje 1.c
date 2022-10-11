#include <stdio.h>
#define N 3

struct empleados
{
    int edad, sueldo;
    char nombre[20];
};

void carga (struct empleados emp[N]) {
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", &emp[i].nombre);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &emp[i].edad);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%d", &emp[i].sueldo);
        printf("-------------------------------------\n");
    }
}

void mostrar (struct empleados emp[N]) {
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("Nombre: %s \n",emp[i].nombre);
        printf("Edad: %d \n", emp[i].edad);
        printf("Sueldo:: %d \n", emp[i].sueldo);
        printf("-------------------------------------\n");
    }
}

int sueldoMenor (struct empleados emp[N], int i, int a) {
    if (i<N)
    {
        if(emp[i].sueldo < a) {
            printf("Empleado %s edad %d posee un sueldo menor al ingresado\n\n", emp[i].nombre, emp[i].edad);
            return sueldoMenor(emp, i+1, a);
        }
    }
}

int edad(struct empleados emp[N], int eMay, int *eMen) {
    int i;
    for ( i = 0; i < N; i++) {
        if (emp[i].edad < 30)
        {
            (*eMen)++;
        }
        if (emp[i].edad > 45)
        {
            eMay++;
        }
    }
    return eMay;
}

int main() {
    struct empleados emp[N];
    int a, i=0, eMay=0, eMen=0, tot;
    carga(emp);
    mostrar(emp);
    printf ("Ingrese un sueldo: ");
    scanf("%d", &a);
    printf("-------------------------------------\n");
    sueldoMenor(emp, i, a);
    eMay = edad(emp, eMay, &eMen);
    printf ("Empleados menores a 30: %d \n", eMen);
    printf ("Empleados mayores a 45: %d", eMay);
}
