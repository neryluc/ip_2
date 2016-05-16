#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_REG 40
#define TAM_DESC 50

struct Produto {
	int codigo;
	char descricao[TAM_DESC];
	float valueUni;
	int qntEstoque;
};

void cadastrarProduto(struct Produto vetProduto[], int *pos);
void alterarValorUni(struct Produto vetProduto[], int tam);
float getValorUnitario(struct Produto vetProduto[], int tam, int codigo);

int main() {
	struct Produto produtos[TAM_REG];
	int qntProdutos = 0, opcao;

	do {
		printf("############### MENU #################\n");
		printf(">> 1) Cadastrar \n");
		printf(">> 2) Alterar Valor Unitario \n");
		printf(">> 3) Obter valor unitario \n");
		printf(">> 0) Sair \n");

		scanf_s("%d", &opcao);
		printf("\n");

		switch (opcao) {
		case 1:
			cadastrarProduto(produtos, &qntProdutos);
			break;
		case 2:
			alterarValorUni(produtos, TAM_REG);
			break;
		case 3: {
			int codigo;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);
			
			float valorUni = getValorUnitario(produtos, TAM_REG, codigo);
			
			if (valorUni > 0)
				printf("Valor Unitario: %f.\n\n", valorUni);
			else
				printf("Nao existe produto com o codigo informado!\n\n");

			break;
		}	
		default:
			break;
		}

	} while (opcao != 0);

	system("pause");
	return 0;
}

void cadastrarProduto(struct Produto vetProduto[], int *pos) {
	struct Produto produto;
	
	char nomeProduto[TAM_DESC];
	do {
		printf("Nome do produto: ");
		fseek(stdin, 0, SEEK_END);
		fgets(nomeProduto, TAM_DESC, stdin);

		if (strlen(nomeProduto) > TAM_DESC)
			printf("Maximo de %d caracteres!\n", TAM_DESC);
		else
			strcpy(produto.descricao, nomeProduto);
	} while (strlen(nomeProduto) > TAM_DESC);


	printf("Codigo: ");
	scanf_s("%d", &produto.codigo);

	printf("Valor uni.: ");
	scanf_s("%f", &produto.valueUni);

	printf("Quantidade do estoque: ");
	scanf_s("%d", &produto.qntEstoque);

	vetProduto[*pos] = produto;
	*pos++;

	printf("\nProduto cadastrado com sucesso!\n\n");
}

void alterarValorUni(struct Produto vetProduto[], int tam) {
	int codigo;

	printf("Digite o codigo do produto: ");
	scanf_s("%d", &codigo);

	int i;
	for (i = 0; i < tam; i++) {
		if (vetProduto[i].codigo == codigo) {
			printf("Produto: %s", vetProduto[i].descricao);
			printf("Digite o novo valor unitario: ");
			scanf_s("%f", &vetProduto[i].valueUni);
			printf("Valor alterado com sucesso!\n\n");
			return;
		}
	}

	printf("Nao existe produto cadastrado com este codigo!\n\n");
}

float getValorUnitario(struct Produto vetProduto[], int tam, int codigo) {
	int i;
	float valorUniEncontrado = -1;

	for (i = 0; i < tam; i++) {
		if (vetProduto[i].codigo == codigo) {
			valorUniEncontrado = vetProduto[i].valueUni;
			break;
		}
	}

	return valorUniEncontrado;
}