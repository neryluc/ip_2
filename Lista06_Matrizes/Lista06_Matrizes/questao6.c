#include <stdlib.h>
#include <stdio.h>

#define LIN 4
#define COL 4

int main() {
	int matriz[LIN][COL];

	int i, j;
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			printf("Digite um valor para a linha %d e coluna %d: ", i + 1, j + 1);
			scanf_s("%d", &matriz[i][j]);
		}
	}

	printf("\nExibindo a matriz digitada: \n");
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
				printf("%5d", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	int total = 0;
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			if (j > i)
				total += matriz[i][j];
		}
	}

	printf("A soma dos numeros acima da diagonal principal da matriz eh: %d.\n", total);

	system("pause");
	return 0;
}