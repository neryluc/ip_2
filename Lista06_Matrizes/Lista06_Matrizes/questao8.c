#include <stdlib.h>
#include <stdio.h>

#define LIN 4
#define COL 5

int main() {
	int matriz[LIN][COL], somaLinha[LIN], somaColuna[COL], total = 0;

	int i, j;
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			printf("Digite o valor da linha %d e coluna %d: ", i+1, j+1);
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
	
	int somadorLinha = 0;
	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			somadorLinha += matriz[i][j];
		}
		somaLinha[i] = somadorLinha;
		somadorLinha = 0;
	}

	int somadorColuna = 0;
	for (j = 0; j < COL; j++) {
		for (i = 0; i < LIN; i++) {
			somadorColuna += matriz[i][j];
		}
		somaColuna[j] = somadorColuna;
		somadorColuna = 0;
	}

	for (i = 0; i < LIN; i++) {
		total += somaLinha[i];
	}

	printf("\nExibindo os valores do vetor somaLinha: \n");
	for (i = 0; i < LIN; i++) {
		printf("%5d", somaLinha[i]);
	}

	printf("\nExibindo os valores do vetor somaColuna: \n");
	for (i = 0; i < COL; i++) {
		printf("%5d", somaColuna[i]);
	}

	printf("\nO valor da variavel TOTAL eh: %d.\n", total);

	system("pause");
	return 0;
}