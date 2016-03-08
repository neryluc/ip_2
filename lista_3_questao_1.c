#include <stdio.h>

#define	TAM 100

void preencherValores(int vetor[], int *qntPreenchida);
int buscarValor(int vetor[], int posicoesPreenchidas, int valorProcurado);
void exibirValores(int vetor[], int posicoesUtilizadas);
void vetorDiferenca(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado);
void vetorIntersecao(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado);
void vetorUniao(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado);


int main() {
	int vetorA[TAM], vetorB[TAM];
	int qntVetorA, qntVetorB;
	
	int vetorDiffAB[TAM], qntVetorDiferencaAB;
	int vetorDiffBA[TAM], qntVetorDiferencaBA;
	int vetorIntersec[TAM], qntVetorIntersecao;
	int vetorUni[TAM + TAM], qntVetorUniao;

	printf("---- Vetor A ----\n");
	preencherValores(vetorA, &qntVetorA);
	
	printf("\n---- Vetor B ----\n");
	preencherValores(vetorB, &qntVetorB);

	printf("\n---- Vetor diferenca: A - B ----\n");
	vetorDiferenca(vetorA, vetorB, qntVetorA, qntVetorB, vetorDiffAB, &qntVetorDiferencaAB);
	exibirValores(vetorDiffAB, qntVetorDiferencaAB);

	printf("\n---- Vetor diferenca: B - A ----\n");
	vetorDiferenca(vetorB, vetorA, qntVetorB, qntVetorA, vetorDiffBA, &qntVetorDiferencaBA);
	exibirValores(vetorDiffBA, qntVetorDiferencaBA);

	printf("\n---- Vetor intersecao: A e B ----\n");
	vetorIntersecao(vetorA, vetorB, qntVetorA, qntVetorB, vetorIntersec, &qntVetorIntersecao);
	exibirValores(vetorIntersec, qntVetorIntersecao);

	printf("\n---- Vetor Uniao: A e B ----\n");
	vetorUniao(vetorA, vetorB, qntVetorA, qntVetorB, vetorUni, &qntVetorUniao);
	exibirValores(vetorUni, qntVetorUniao);

	printf("\n");

	system("pause");
	return 0;
}

void preencherValores(int vetor[], int *qntPreenchida) {
	int continuarInserindo = 1;
	*qntPreenchida = 0;

	do {
		printf("Digite um valor: ");
		scanf_s("%d", &vetor[*qntPreenchida]);

		*qntPreenchida = *qntPreenchida + 1;

		printf("Deseja continuar inserindo? (1 = SIM, 0 = NAO) ");
		scanf_s("%d", &continuarInserindo);
		
	} while (continuarInserindo);
}

void vetorUniao(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado){
	int i, j, valorJaInserido;
	*qntVetorGerado = 0;

	for (i = 0; i < qntA; i++) {
		valorJaInserido = buscarValor(vetorGerado, *qntVetorGerado, vetorA[i]);
		if (valorJaInserido != 1) {
			vetorGerado[*qntVetorGerado] = vetorA[i];
			*qntVetorGerado = *qntVetorGerado + 1;
		}
	}

	for (j = 0; j < qntB; j++) {
		valorJaInserido = buscarValor(vetorGerado, *qntVetorGerado, vetorB[j]);
		if (valorJaInserido != 1) {
			vetorGerado[*qntVetorGerado] = vetorB[j];
			*qntVetorGerado = *qntVetorGerado + 1;
		}
	}
}

void vetorIntersecao(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado) {
	int i, j, valorExisteEmB, valorJaInserido;
	*qntVetorGerado = 0;

	for (i = 0; i < qntA; i++) {
		valorExisteEmB = 0;
		for (j = 0; j < qntB; j++) {
			if (vetorB[j] == vetorA[i]) {
				valorExisteEmB = 1;
				break;
			}
		}

		if (valorExisteEmB) {
			valorJaInserido = buscarValor(vetorGerado, *qntVetorGerado, vetorA[i]);
			if (valorJaInserido != 1) {
				vetorGerado[*qntVetorGerado] = vetorA[i];
				*qntVetorGerado = *qntVetorGerado + 1;
			}
		}
	}
}

void vetorDiferenca(int vetorA[], int vetorB[], int qntA, int qntB, int vetorGerado[], int *qntVetorGerado) {
	int i, j, valorExisteEmB, valorJaInserido;
	*qntVetorGerado = 0;

	for (i = 0; i < qntA; i++) {
		valorExisteEmB = 0;
		for (j = 0; j < qntB; j++) {
			if (vetorB[j] == vetorA[i]) {
				valorExisteEmB = 1;
				break;
			}
		}

		if(valorExisteEmB == 0){
			valorJaInserido = buscarValor(vetorGerado, *qntVetorGerado, vetorA[i]);
			if (valorJaInserido != 1) {
				vetorGerado[*qntVetorGerado] = vetorA[i];
				*qntVetorGerado = *qntVetorGerado + 1;
			}
		}
	}
}

int buscarValor(int vetor[], int posicoesPreenchidas, int valorProcurado) {
	int i;
	int achouValor = 0;

	for (i = 0; i < posicoesPreenchidas; i++) {
		if (vetor[i] == valorProcurado) {
			achouValor = 1;
			break;
		}
	}

	if (posicoesPreenchidas == 0)
		return -1;
	else 
		return achouValor;
}

void exibirValores(int vetor[], int	posicoesUtilizadas) {
	int i;

	for (i = 0; i < posicoesUtilizadas; i++) {
		printf("%d", vetor[i]);
		if (i < posicoesUtilizadas - 1) {
			printf(", ");
		}
	}
	printf("\n");
}