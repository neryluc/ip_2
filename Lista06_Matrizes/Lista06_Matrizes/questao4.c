#include <stdlib.h>
#include <stdio.h>

#define LIN 5
#define COL 3

int main() {
	float notas[LIN][COL];

	int i, j;
	for (i = 0; i < LIN; i++) {
		printf("Aluno %d:\n", i + 1);
		for (j = 0; j < COL; j++) {
			if (j == 0) {
				printf("- Primeita nota: ");
				scanf_s("%f", &notas[i][j]);
			}
			else if (j == 1) {
				printf("- Segunda Nota: ");
				scanf_s("%f", &notas[i][j]);
			}
			else {
				notas[i][j] = ((notas[i][j - 2] * 2) + (notas[i][j - 1] * 3)) / 5;
			}
		}
		printf("\n");
	}

	for (i = 0; i < LIN; i++) {
		printf("O aluno numero %d obteve media %.2f.\n", i+1, notas[i][2]);
	}

	system("pause");
	return 0;
}