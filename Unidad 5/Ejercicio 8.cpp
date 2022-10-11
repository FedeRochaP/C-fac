#include <stdio.h>

struct facultad
{
    char facName;
    struct node* ins;
};

struct node
{
    char name;
    float prom;
    int clas;
    struct node* sig;
};

int main() {
    int cant, i=0;
    facultad *U;
    struct facultad fa[];
    
    
}