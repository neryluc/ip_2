#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

int main() {
	char f1[TAM], f2[TAM], f3[TAM + TAM + 1];

	printf("Digite a uma frase: ");
	gets(f1);

	printf("Digite outra frase: ");
	gets(f2);

	int i;
	for (i = 0; f1[i] != '\0'; i++) {
		f3[i] = f1[i];
	}

	int j;
	for (j = 0; f2[j] != '\0'; j++, i++) {
		f3[i] = f2[j];
	}

	f3[i] = '\0';

	printf("A frase final concatenada eh: %s\n", f3);

	system("pause");
	return 0;
}