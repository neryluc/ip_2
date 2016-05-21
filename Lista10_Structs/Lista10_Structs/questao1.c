#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define REG 3
#define NOME_TAM 50

struct Estado {
	char nome[NOME_TAM];
	int qntVeiculos;
	int qntAcidentes;
};

void cadastrarEstados(struct Estado estados[], int tam);
void maiorMenorAcidentes(struct Estado estados[], int tam, int *posMenor, int *posMaior);
int mediaAcidentes(struct Estado estados[], int tam);
float mediaAcidentesPorEstado(struct Estado estados[], int pos);
void estadosAcimaMedia(struct Estado estados[], int tam, int media);

int main() {
	struct Estado estados[REG];
	cadastrarEstados(estados, REG);

	int posMenor, posMaior;
	maiorMenorAcidentes(estados, REG, &posMenor, &posMaior);
	printf("Estado com menor numero de acidentes: %s.\n", estados[posMenor].nome);
	printf("Estado com maior numero de acidentes: %s.\n", estados[posMaior].nome);

	int media = mediaAcidentes(estados, REG);
	printf("A media de acidentes no pais eh: %d.\n", media);

	estadosAcimaMedia(estados, REG, media);

	int estado;
	printf("Digite o numero de um estado: ");
	scanf_s("%d", &estado);
	float mediaPorEstado = mediaAcidentesPorEstado(estados, estado - 1);
	printf("A media de acidentes deste estado eh de %.2f acidente(s) por veiculo\n", mediaPorEstado);

	system("pause");
	return 0;
}

void cadastrarEstados(struct Estado estados[], int tam) {
	int i;
	printf("Cadastro de informacoes de %d estados\n\n", tam);

	for (i = 0; i < tam; i++) {
		struct Estado novoEstado;

		char nome[NOME_TAM];
		do {
			printf("Digite o nome do estado %d: ", i+1);
			fseek(stdin, 0, SEEK_END);
			gets(nome);

			if (strlen(nome) == 0 || strlen(nome) >= NOME_TAM) {
				printf("O nome precisa ter no maximo %d caracteres.\n", NOME_TAM);
			}
			else {
				strcpy(novoEstado.nome, nome);
			}
		} while (strlen(nome) == 0 || strlen(nome) >= NOME_TAM);

		printf("Digite a quantidade de veiculos do estado (em 2007): ");
		scanf_s("%d", &novoEstado.qntVeiculos);

		printf("Digite a quantidade de acidentes no estado (em 2007): ");
		scanf_s("%d", &novoEstado.qntAcidentes);

		estados[i] = novoEstado;
		printf("\n");
	}
}

void maiorMenorAcidentes(struct Estado estados[], int tam, int *posMenor, int *posMaior) {
	*posMenor = 0;
	*posMaior = 0;
	int i;
	for (i = 0; i < tam; i++) {
		if (estados[i].qntAcidentes < estados[*posMenor].qntAcidentes) {
			*posMenor = i;
		}

		if (estados[i].qntAcidentes > estados[*posMaior].qntAcidentes) {
			*posMaior = i;
		}
	}
}

int mediaAcidentes(struct Estado estados[], int tam) {
	int i, somaAcidentes = 0;
	for (i = 0; i < tam; i++) {
		somaAcidentes += estados[i].qntAcidentes;
	}
	return somaAcidentes / tam;
}

void estadosAcimaMedia(struct Estado estados[], int tam, int media) {
	printf("Exibindo estados acima da media de aciddentes: \n");
	int i;
	for (i = 0; i < tam; i++) {
		if (estados[i].qntAcidentes > media) {
			printf("Estado: %s, Quantidade de Acidentes: %d.\n", 
				estados[i].nome, estados[i].qntAcidentes);
		}
	}
}

float mediaAcidentesPorEstado(struct Estado estados[], int pos) {
	float media = estados[pos].qntVeiculos / estados[pos].qntAcidentes;
	return media;
}