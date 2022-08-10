#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vocales(char prog[], char proc[], char year[])
{
    int i, va=0, ve=0, vi=0, vo=0, vu=0, vt=0;
    char pp[25];
    strcpy(pp, prog);
    strcat(pp, " ");
    strcat(pp, proc);
    printf("%s", pp);
    for (i = 0; i < 25; i++)
    {
        switch (pp[i])
        {
        case 'a':
            va++;
            break;
        case 'e':
            ve++;
            break;
        case 'i':
            vi++;
            break;
        case 'o':
            vo++;
            break;
        case 'u':
            vu++;
            break;
        }
    }
    vt = va + ve + vi + vo + vu;
    printf("El total de vocales de la frase es: %d", vt);
}

int main()
{
    char prog[] = "Programación", proc[] = "Procedural", year[] = "2022", cero, copy, nc[15];
    printf("%s %s %s \n", prog, proc, year);
    printf("Modificar el ultimo número 2 por un cero?(S/N): ");
    scanf("%c", &cero);
    if (cero == 'S')
    {
        year[3] = '0';
    }
    else
    {
        printf("No se hicieron cambios\n");
    }

    fflush(stdin);
    printf("%s %s %s \n", prog, proc, year);
    printf("--------------------------------\n");
    printf("Desea copiar la cadena %s en una nueva cadena de caracteres?(S/N): ", prog);
    scanf("%c", &copy);
    if (copy == 'S') {
        strcpy (nc, prog);
        printf("Se a copiado con exito la cadena %s \n", nc);
    }
    else {
        printf("La caneda no ah sido copiada\n");
    }
    vocales(prog, proc, year);
    return 0;
}