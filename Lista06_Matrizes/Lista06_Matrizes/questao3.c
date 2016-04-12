#include <stdlib.h>
#include <stdio.h>

#define LINHAS 3
#define COLUNAS 4

int main() {
	float matrizA[LINHAS][COLUNAS], matrizB[LINHAS][COLUNAS], matrizC[LINHAS][COLUNAS];

	int i, j;
	for (i = 0; i < LINHAS; i++) {
		for (j = 0; j < COLUNAS; j++) {
			printf("Digite um valor para a linha %d, coluna %d, da Matriz A: ", i+1, j+1);
			scanf_s("%f", &matrizA[i][j]);
		}
	}

	for (i = 0; i < LINHAS; i++) {
		for (j = 0; j < COLUNAS; j++) {
			printf("Digite um valor para a linha %d, coluna %d, da Matriz B: ", i + 1, j + 1);
			scanf_s("%f", &matrizB[i][j]);
		}
	}
	
	printf("\nImprimindo a Matriz C \n");

	for (i = 0; i < LINHAS; i++) {
		for (j = 0; j < COLUNAS; j++) {
			matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
			printf("%.2f     ", matrizC[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}