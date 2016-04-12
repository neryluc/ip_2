#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 100

int main() {
	char str[TAM], caracter;

	printf("Digite uma frase: ");
	gets(str);

	printf("Digite um caracter: ");
	caracter = getchar();

	int i, total = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == caracter)
			total++;
	}

	printf("O caracter aparece %d vez(es) na frase digitada.\n", total);

	system("pause");
	return 0;
}