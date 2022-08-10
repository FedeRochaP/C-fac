#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	int array[5], i;
	for (i=0; i<5; i++) {
		printf ("Ingrese un numero n°: ");
		scanf ("%d", &array[i]);	
	}
	printf("-------------------------------\n");
	for (i=0; i<5; i++) {
		printf("Su numero es: %d\n", array[i]);		
	}
	printf("-------------------------------\n");
	for (i=0; i<5; i++) {
		if (array[i]==0) {
			printf("Su numero en la posicion %d es igual a 0\n", i+1);
		}
	}
	printf("-------------------------------\n");
	for (i=0; i<5; i++) {
		if ((i+1)%2 == 0) {
			printf("Su numero en la posicion par %d es %d\n", i+1, array[i]);
		}
	}
	printf("-------------------------------\n");
	for (i=0; i<5; i++) {
		if ((array[i])%2 == 0) {
			printf("Su numero en la posicion %d es par\n", i+1, array[i]);
		}
	}
	
	return 0;
}
