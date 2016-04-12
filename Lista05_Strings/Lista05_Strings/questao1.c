#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 80

int main() {
	char str[TAM];

	printf("Digite a frase: ");
	gets(str);

	int i;
	char caracter;;
	
	for (i = 0; str[i] != '\0'; i++) {
		caracter = tolower(str[i]);
		if (isalpha(caracter) && (caracter == 'a' || caracter == 'e' || 
				caracter == 'i' || caracter == 'o' || caracter == 'u')) {
			printf("*");
		} else {
			printf("%c", str[i]);
		}
	}

	printf("\n");

	system("pause");
	return 0;
}