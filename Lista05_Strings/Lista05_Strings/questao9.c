#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 100

int main() {
	char str[TAM];

	printf("Digite a frase: ");
	gets(str);

	int i, totalLetras = 0, totalDigitos = 0, totalSimbolos = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i]))
			totalDigitos++;
		else if (isalpha(str[i]))
			totalLetras++;
		else
			totalSimbolos++;
	}

	printf("A frase possui %d letras, %d digitos e %d simbolos.\n", 
		totalLetras, totalDigitos, totalSimbolos);

	system("pause");
	return 0;
}