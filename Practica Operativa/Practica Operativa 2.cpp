#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct product {
    int cod;
    float price;
}typedef product;

struct nodo {
    product prod;
    int a;
    struct nodo* sig;
}typedef nodo;

void carga(nodo* &root ) {
    int cod;
    scanf("%d", &cod);
    if(cod != 0){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->sig = root;
    root=nuevo;
    nuevo->prod.cod = cod;
    scanf("%f", &nuevo->prod.price);
    return carga(root);
    }
    else
        return;
}
void recorre(nodo* root){
    if(root != NULL){
        recorre(root->sig);
        printf("Datos: %d, Precio: %f \n", root->prod.cod, root->prod.price);
        return;
    }
    else
        return;
}

int main(void)
{
    nodo* root = NULL;
    carga(root);
    recorre(root);
}