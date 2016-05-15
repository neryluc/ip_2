#include <stdlib.h>
#include <stdio.h>

#define TAM 8

void printVetor(int *vetor, int tam);
void bubbleSort(int *vetor, int tam);
void insertionSort(int *vetor, int tam);
void selectionSort(int *vetor, int tam);

int main() {
	int vetor[TAM] = { 21, 27, 12, 20, 37, 19, 17, 15 };

	printVetor(vetor, TAM);
	bubbleSort(vetor, TAM);
	printVetor(vetor, TAM);

	system("pause");
	return 0;
}

void bubbleSort(int *vetor, int tam) {
	int i, aux;
	int maxPos = tam - 1;
	
	while(maxPos > 0){
		for (i = 0; i < maxPos; i++) {
			if (vetor[i + 1] < vetor[i]) {
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
			}
		}
		maxPos--;
	}
}

void selectionSort(int *vetor, int tam) {
	int i, j, menorValorPos, aux;
	for (i = 0; i < tam - 1; i++) {
		menorValorPos = i;

		for (j = i + 1; j < tam; j++) {
			if (vetor[j] < vetor[menorValorPos])
				menorValorPos = j;
		}

		aux = vetor[i];
		vetor[i] = vetor[menorValorPos];
		vetor[menorValorPos] = aux;
	}
}

void insertionSort(int *vetor, int tam) {
	int posChave, valorChave;
	int posSubVetorOrdenado;

	for (posChave = 1; posChave < tam; posChave++) {
		valorChave = vetor[posChave];
		posSubVetorOrdenado = posChave - 1;

		while (posSubVetorOrdenado >= 0 && vetor[posSubVetorOrdenado] > valorChave) {
			// "empurra para frente" o valor do subvetor ordenado que eh maior do que o valor da chave
			vetor[posSubVetorOrdenado + 1] = vetor[posSubVetorOrdenado];
			// decrementa pois vamos precisar analisar o restando dos campos do subvetor ordenado
			posSubVetorOrdenado--;
		}

		/*
		* Neste ponto, posSubVetorOrdenado pode ser:
		* 1) A posicao 0, se todos os valores do subvetor ordenado forem maiores do que o valor da chave
		* 2) A posicao do valor no subvetor ordenado que eh menor que ou igual ao valor da chave
		* No caso do item 2, o valor da chave devera ser colocado em posSubVetorOrdenado + 1
		*/
		vetor[posSubVetorOrdenado + 1] = valorChave;
	}
}

void printVetor(int *vetor, int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		printf("%d  ", vetor[i]);
	}
	printf("\n");
}