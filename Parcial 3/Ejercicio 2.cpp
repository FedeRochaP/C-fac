#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    int dni, sector, sueldo;
} empleados;

int carga(empleados *emp, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Ingrese el DNI: ");
        scanf("%d", &emp[i].dni);
        printf("Ingrese sector: ");
        scanf("%d", &emp[i].sector);
        printf("Ingrese sueldo: ");
        scanf("%d", &emp[i].sueldo);
        printf("---------------------------------------------\n");
    }
}

void show(empleados *emp, int a)
{
    int i;
    for (i = 0; i < a; i++)
    {
        printf("DNI: %d\nSector: %d\nSueldo: %d\n", emp[i].dni, emp[i].sector, emp[i].sueldo);
        printf("---------------------------------------------\n");
    }
}

int mayor(empleados *emp, int a, int i, int *c)
{
    if (i < a)
    {
        if (emp[i].sueldo >= 150)
        {
        	(*c)++;
            return mayor(emp, a, i + 1, c);
        }
        return mayor(emp, a, i + 1, c);
    }
}

void file(empleados *emp, int a){
	FILE *archi;
	archi = fopen("personal.dat", "wb");
    for (int i = 0; i < a; i++)
    {
        fwrite(&emp[i], sizeof(empleados),1 ,archi);
    }
    fclose(archi);
}

void fileshow(empleados *emp, int a){
	FILE *archi;
	archi = fopen("personal.txt", "rb");
    for (int i = 0; i < a; i++)
    {
        fread(&emp, sizeof(emp),1 ,archi);
//        while(feof(archi)==0){
//        	
//		}
    }
    fclose(archi);
}

int main()
{
    int a, i = 0, c = 0;
    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &a);
    printf("---------------------------------------------\n");
    empleados *emp = (empleados *)malloc(sizeof(empleados) * a);
    carga(emp, a);
    show(emp, a);
    mayor(emp, a, i, &c);
    printf("La cantidad de empleados con suledo mayor a 150k es: %d", c);
    file(emp,a);
    fileshow(emp,a);
}
