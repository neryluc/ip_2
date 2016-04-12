#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 100

int main() {
	char str[TAM];

	printf("Digite uma frase: ");
	gets(str);

	int i;
	for (i = 0; str[i] != '\0'; i++);

	if (i > 0) {
		int j;
		char caracter;
		for (j = i - 1; j >= 0; j--) {
			caracter = tolower(str[j]);
			if (isalpha(caracter) && (caracter != 'a' && caracter != 'e' &&
				caracter != 'i' && caracter != 'o' && caracter != 'u')) {
				printf("#");
			}
			else {
				printf("%c", str[j]);
			}
		}
	}

	printf("\n");

	system("pause");
	return 0;
}