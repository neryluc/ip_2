#include <stdio.h>

#define TAM 100

void preencherVetor(float vetor[], float valor, int *posicoesUtilizadas);
int buscaValor(float vetor[], int posicoesUtilizadas, float valorProcurado);
void exibirValores(float vetor[], int posicoesUtilizadas);

int main() {
	int posicoesUtilizadas = 0, continuarInserindo = 1, valorJaExiste;
	float vetor[TAM], novoValor;

	do {
		printf("\nDigite um valor para inserir no vetor: ");
		scanf_s("%f", &novoValor);

		valorJaExiste = buscaValor(vetor, posicoesUtilizadas, novoValor);

		if (posicoesUtilizadas == TAM) {
			printf("\nO vetor não permite que mais valores sejam inseridos!");
		}
		else {
			if (valorJaExiste) {
				printf("\nO valor ja existe no vetor.\n");
			}
			else {
				preencherVetor(vetor, novoValor, &posicoesUtilizadas);
			}

			printf("\nValores no vetor: ");
			exibirValores(vetor, posicoesUtilizadas);

			printf("\nDeseja continuar inserindo? (1 = SIM, 0 = NAO) ");
			scanf_s("%d", &continuarInserindo);
		}

	} while (continuarInserindo);

	printf("\nAdeus.");
	getchar();
	return 0;
}

void preencherVetor(float vetor[], float valor, int *posicoesUtilizadas) {
	if (*posicoesUtilizadas < TAM) {
		if (*posicoesUtilizadas == 0) {
			vetor[*posicoesUtilizadas] = valor;
		} else {
			int i;
			for (i = 0; i <= *posicoesUtilizadas; i++) {
				if (i == *posicoesUtilizadas) {
					vetor[*posicoesUtilizadas] = valor;
					break;
				} else {
					if (vetor[i] > valor) {
						int j;
						for (j = *posicoesUtilizadas; j > i; j--) {
							vetor[j] = vetor[j - 1];
						}
						vetor[i] = valor;
						break;
					} else {
						continue;
					}
				}
			}
		}
		*posicoesUtilizadas = *posicoesUtilizadas + 1;
	}
}

int buscaValor(float vetor[], int posicoesUtilizadas, float valorProcurado) {
	int valorExiste = 0;
	int i;

	if (posicoesUtilizadas > 0) {
		for (i = 0; i < posicoesUtilizadas; i++) {
			if (vetor[i] == valorProcurado) {
				valorExiste = 1;
				break;
			}
		}
	}

	return valorExiste;
}

void exibirValores(float vetor[], int posicoesUtilizadas) {
	int i;

	for (i = 0; i < posicoesUtilizadas; i++) {
		printf("%f", vetor[i]);
		if (i < posicoesUtilizadas - 1) {
			printf(", ");
		}
	}
	printf("\n");
}