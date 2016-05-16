#include <stdio.h>
#include <stdlib.h>

#define TAM 3

struct Estado {
	char nome[50];
	int qntVeiculos;
	int qntAcidentes;
};

// Letra A
void coletarDados(struct Estado vetor[], int tam);
// Letra B
void maiorMenorQntAcidentes(struct Estado vetor[], int tam, int *posMenor, int *posMaior);
// TODO: Letra C
// Letra D
int mediaAcidentes(struct Estado vetor[], int tam);
// Letra E
void estadosAcimaMedia(struct Estado vetor[], int tam, int media);

int main() {
	system("chcp 1252 >nul");
	struct Estado estados[TAM];

	coletarDados(estados, TAM);

	int media = mediaAcidentes(estados, TAM);
	printf("A media de acidentes nos estados eh: %d\n.", media);

	int maior, menor;
	maiorMenorQntAcidentes(estados, TAM, &maior, &menor);

	printf("Estado com maior acidentes: %d.\n", estados[maior].qntAcidentes);
	printf("Estado com menor acidentes: %d.\n", estados[menor].qntAcidentes);

	system("pause");
	return 0;
}

void coletarDados(struct Estado vetor[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		printf(">> Estado %d \n", i + 1);
		fflush(stdin);
		fflush(NULL);
		
		printf(">> Digite o nome: ");
		gets_s(vetor[i].nome, sizeof(vetor[i].nome));
		fflush(stdin);
		fflush(NULL);
		
		printf(">> Digte a quantidade de veículos (em 2007): ");
		scanf_s("%d", &vetor[i].qntVeiculos);
		fflush(stdin);
		fflush(NULL);
		
		printf(">> Digite a quantidade de acidentes (em 2007): ");
		scanf_s("%d", &vetor[i].qntAcidentes);
		fflush(stdin);
		fflush(NULL);

		printf("\n");
		fflush(stdin);
		fflush(NULL);
	}
}

void maiorMenorQntAcidentes(struct Estado vetor[], int tam, int *posMenor, int *posMaior) {
	if (tam <= 0) {
		return;
	}
	
	int i;
	*posMenor = 0;
	*posMaior = 0;
	for (i = 0; i < tam; i++) {
		if (vetor[i].qntAcidentes > vetor[*posMaior].qntAcidentes) {
			*posMaior = i;
		}
		if (vetor[i].qntAcidentes < vetor[*posMenor].qntAcidentes) {
			*posMenor = i;
		}
	}
}

int mediaAcidentes(struct Estado vetor[], int tam) {
	int i, qntAcidentes = 0;
	for (i = 0; i < tam; i++) {
		qntAcidentes += vetor[i].qntAcidentes;
	}

	return qntAcidentes / tam;
}

void estadosAcimaMedia(struct Estado vetor[], int tam, int media) {
	if (tam <= 0) {
		printf("Nao existem estados para exibir!\n");
		return;
	}

	printf("Os estados acima da media de acidentes sao: \n");

	int i;
	for (i = 0; i < tam; i++) {
		if (vetor[i].qntAcidentes > media) {
			printf("%s.\n", vetor[i].nome);
		}
	}
}
