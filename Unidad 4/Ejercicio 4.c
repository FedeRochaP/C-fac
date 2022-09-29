#include <stdio.h>
#define N 100

struct languages
{
    int js, html, css, py, java, c, total;
};

int cero(struct languages lan[N], int i) {
    
}

int plus(struct languages lan[N], int i)
{
    int var=0;
    printf("Ingrese que lenguaje considera el mejor para programar (1-Javascrpipt, 2-HTML, 3-CSS, 4-Python, 5-Java, 6-C, 0-Terminar): ");
    scanf("%d", &var);
    if (var != 0)
    {
        switch (var)
        {
        case 1: lan[i].js += 1 ; break;
        case 2: lan[i].html += 1 ; break;
        case 3: lan[i].css += 1 ; break;
        case 4: lan[i].py += 1 ; break;
        case 5: lan[i].java += 1 ; break;
        case 6: lan[i].c += 1 ; break;
        }
        lan[i].total += 1;
        plus(lan, i+1);
    }
    else {
        return printf("Carga finalizada");
    }
}

void showUp(struct languages lan[N], int i) {
    printf("El total de gente en JavaScript es: %d", lan[i].js);
    printf("El total de gente en HTML es: %d", lan[i].html);
    printf("El total de gente en CSS es: %d", lan[i].css);
    printf("El total de gente en Python es: %d", lan[i].py);
    printf("El total de gente en Java es: %d", lan[i].java);
    printf("El total de gente en C es: %d", lan[i].c);
}

int main(){
    int i=0;
    struct languages lan[N];
    plus(lan, i);
    showUp(lan, i);
}