#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[10], surname[10];
    int id;
};

void load(struct student stu[3])
{
    int i;
    for (i=0; i<3; i++)
    {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", &stu[i].name);
        printf("Ingrese el apellido del alumno: ");
        scanf("%s", &stu[i].surname);
        printf("Ingrese el DNI: ");
        scanf("%d", &stu[i].id);
        printf("\n");
    }
}

void show(struct student stu[3]) {
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Alumno: %s %s \n", stu[i].name, stu[i].surname);
        printf("DNI: %d \n\n", stu[i].id);
    }
}

void uper(struct student stu[3]) {
    int i;
    for ( i = 0; i < 3; i++)
    {
        if (stu[i].id > 40)
        {
            printf("El alumno %s %s posee un DNI mayor a 40 mill.\n", stu[i].name, stu[i].surname);
        }
        
    }
    
}

int main()
{
    struct student stu[3];
    load(stu);
    printf("---------------------------\n");
    show(stu);
    printf("---------------------------\n");
    uper(stu);
    return 0;
}