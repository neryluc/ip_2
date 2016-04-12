#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

int main() {
	char str[TAM], caracter;

	printf("Digite a frase: ");
	gets(str);

	printf("Digite uma letra: ");
	caracter = getchar();

	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (tolower(str[i]) == tolower(caracter)) {
			str[i] = toupper(caracter);
		}
	}

	printf("A frase final formada eh: %s\n", str);

	system("pause");
	return 0;
}