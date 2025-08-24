#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	
	printf("Digite a aresta 1: ");
	scanf("%d", &a);
	printf("Digite a aresta 2: ");
	scanf("%d", &b);
	printf("Digite a aresta 3: ");
	scanf("%d", &c);
	
	if (a+b>c && a+c>b && b+c>a) {
		if (a==b && a==c) {
			printf("Equilátero\n");
		} else if (a==b || a==c || b==c) {
		    printf("Isósceles\n");
		} else {
		    printf("Escaleno\n");
		}    
	} else {
	    printf("O triângulo não existe\n");
	}    
		

    return 0;
}
