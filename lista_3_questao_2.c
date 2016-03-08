#include <stdio.h>

#define TAM 100

void inserirNoVetor(float vetor[], float valor, int *posicoesUtilizadas);
void preencherVetor(float vetor[], int *qntPreenchidas);
void exibirValores(float vetor[], int posicoesUtilizadas);
int buscaValor(float vetor[], int posicoesUtilizadas, float valorProcurado);
int buscaBinaria(float vetor[], int posicoesUtilizadas, float valorProcurado);

int main() {
	float vetor[TAM];
	int posicoesUtilizadas = 0;

	preencherVetor(vetor, &posicoesUtilizadas);

	system("pause");
	return 0;
}

void preencherVetor(float vetor[], int *posicoesUtilizadas) {
	int continuarInserindo = 1, valorJaExiste;
	float novoValor;

	do {
		printf("\nDigite um valor para inserir no vetor: ");
		scanf_s("%f", &novoValor);

		valorJaExiste = buscaValor(vetor, *posicoesUtilizadas, novoValor);

		if (*posicoesUtilizadas == TAM) {
			printf("\nO vetor não permite que mais valores sejam inseridos!");
		}
		else {
			if (valorJaExiste) {
				printf("\nO valor ja existe no vetor.\n");
			}
			else {
				inserirNoVetor(vetor, novoValor, posicoesUtilizadas);
			}

			printf("\nValores no vetor: ");
			exibirValores(vetor, *posicoesUtilizadas);

			printf("\nDeseja continuar inserindo? (1 = SIM, 0 = NAO) ");
			scanf_s("%d", &continuarInserindo);
		}

	} while (continuarInserindo);
}

void inserirNoVetor(float vetor[], float valor, int *posicoesUtilizadas) {
	if (*posicoesUtilizadas < TAM) {
		if (*posicoesUtilizadas == 0) {
			vetor[*posicoesUtilizadas] = valor;
		}
		else {
			int i;
			for (i = 0; i <= *posicoesUtilizadas; i++) {
				if (i == *posicoesUtilizadas) {
					vetor[*posicoesUtilizadas] = valor;
					break;
				}
				else {
					if (vetor[i] > valor) {
						int j;
						for (j = *posicoesUtilizadas; j > i; j--) {
							vetor[j] = vetor[j - 1];
						}
						vetor[i] = valor;
						break;
					}
					else {
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

int buscaBinaria(float v[], int n, float chave) {
	int inicio = 0, meio;
	int fim = n - 1;

	do {
		meio = (inicio + fim) / 2;
		if (v[meio] > chave)
			fim = meio - 1;
		else
			inicio = meio + 1;
	} while (chave != v[meio] && inicio <= fim);

	if (chave == v[meio])
		return meio;
	else if (n == 0)
		return -2;
	else
		return -1;
}