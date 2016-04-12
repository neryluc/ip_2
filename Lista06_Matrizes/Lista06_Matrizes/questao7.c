#include <stdlib.h>
#include <stdio.h>

#define LIN 3
#define COL 3

int main() {
	float matriz[LIN][COL], maiorElemento = 0;

	int i, j;
	for (i = 0; i < COL; i++) {
		for (j = 0; j < LIN; j++) {
			printf("Digite um valor para a linha %d coluna %d: ", j + 1, i + 1);
			scanf_s("%f", &matriz[j][i]);

			if (matriz[i][j] > maiorElemento)
				maiorElemento = matriz[i][j];
		}
	}

	printf("\nExibindo a matriz digitada: \n");
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			printf("%10.2f", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\nExibindo a matriz apos processamento: \n");
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			if (i + j == COL - 1) {
				printf("%10.2f", matriz[i][j] * maiorElemento);
			}
			else {
				printf("%10.2f", matriz[i][j]);
			}
		}
		printf("\n");
	}

	system("pause");
	return 0;
}