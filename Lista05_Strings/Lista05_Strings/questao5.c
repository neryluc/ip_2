#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

int main() {
	char frase[TAM];

	printf("Digite a frase: ");
	gets(frase);

	int i, total = 0;
	char carac;

	for (i = 0; frase[i] != '\0'; i++) {
		carac = tolower(frase[i]);
		if (carac != 'a' && carac != 'e' && carac != 'i' && carac != 'o' && carac != 'u') {
			total++;
		}
	}

	printf("Total de caracteres nao vogais: %d.\n", total);

	system("pause");
	return 0;
}