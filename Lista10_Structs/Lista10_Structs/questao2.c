#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define REGISTROS 40
#define DESC 50

struct Produto {
	int codigo;
	char descricao[DESC];
	float valorUni;
	int qntEstoque;
};

void cadastrarProduto(struct Produto produtos[], int *pos);
void alterarValorUnitario(struct Produto produtos[], int codigo, float newValue, int tam);
float buscarValorUnitario(struct Produto produtos[], int codigo, int tam);
int buscarQntEstoque(struct Produto produtos[], int codigo, int tam);
void venda(struct Produto produtos[], int codigo, int qnt, int tam);
void atualizarEstoque(struct Produto produtos[], int codigo, int newQntEsto, int tam);
void exibirTodos(struct Produto produtos[], int ultimaPos);
void exibirTodosEstoqueZero(struct Produto produtos[], int ultimaPos);
int buscarPorCodigo(struct Produto produtos[], int codigo, int tam);

int main() {
	struct Produto produtos[REGISTROS];
	int opcao, pos = 0;

	do {
		printf("Menu\n");
		printf("1) Cadastrar Produto\n");
		printf("2) Alterar valor unitario\n");
		printf("3) Exibir valor unitario\n");
		printf("4) Exibir quantidade em estoque\n");
		printf("5) Vender\n");
		printf("6) Atualizar estoque\n");
		printf("7) Exibir todos os produtos\n");
		printf("8) Exibir todos os produtos com estoque zero\n");

		printf("\nDigite a opcao: ");
		scanf_s("%d", &opcao);

		printf("\n----------------------------------------------------------------\n");
		switch (opcao) {
		case 1: {
			cadastrarProduto(produtos, &pos);
			break;
		}
		case 2: {
			int codigo, posicao;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);

			posicao = buscarPorCodigo(produtos, codigo, REGISTROS);

			if (posicao < 0) {
				printf("Nao existe produto cadastrado com esse codigo!\n\n");
			}
			else {
				float newValue;
				printf("Digite o novo valor unitario do produto %s: ", produtos[posicao].descricao);
				scanf_s("%f", &newValue);

				alterarValorUnitario(produtos, codigo, newValue, REGISTROS);
			}
			break;
		}
		case 3: {
			int codigo, posicao;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);

			posicao = buscarPorCodigo(produtos, codigo, REGISTROS);

			if (posicao < 0) {
				printf("Nao existe produto cadastrado com esse codigo!\n\n");
			}
			else {
				float valorUni = buscarValorUnitario(produtos, codigo, REGISTROS);
				if (valorUni >= 0) {
					printf("O valor unitario do produto %s eh: %f.\n\n", produtos[posicao].descricao, valorUni);
				}
			}
			break;
		}
		case 4: {
			int codigo, posicao;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);

			posicao = buscarPorCodigo(produtos, codigo, REGISTROS);

			if (posicao < 0) {
				printf("Nao existe produto cadastrado com esse codigo!\n\n");
			}
			else {
				int qnt = buscarQntEstoque(produtos, codigo, REGISTROS);
				if (qnt >= 0) {
					printf("O estoque do produto %s eh: %d.\n\n", produtos[posicao].descricao, qnt);
				}
			}
			break;

			break;
		}
		case 5: {
			int codigo, posicao;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);

			posicao = buscarPorCodigo(produtos, codigo, REGISTROS);

			if (posicao < 0) {
				printf("Nao existe produto cadastrado com esse codigo!\n\n");
				break;
			}

			int qntDesejada;
			printf("Digite a quantidade desejada: ");
			scanf_s("%d", &qntDesejada);

			venda(produtos, codigo, qntDesejada, REGISTROS);

			break;
		}
		case 6: {
			int codigo, posicao;
			printf("Digite o codigo do produto: ");
			scanf_s("%d", &codigo);

			posicao = buscarPorCodigo(produtos, codigo, REGISTROS);

			if (posicao < 0) {
				printf("Nao existe produto cadastrado com esse codigo!\n\n");
				break;
			}

			int novaQnt;
			printf("Digite o novo estoque: ");
			scanf_s("%d", &novaQnt);

			atualizarEstoque(produtos, codigo, novaQnt, REGISTROS);
			break;
		}
		case 7: {
			exibirTodos(produtos, pos);
			break;
		}
		case 8: {
			exibirTodosEstoqueZero(produtos, pos);
			break;
		}
		default: printf("Adeus"); break;
		}
		printf("\n----------------------------------------------------------------\n\n");

	} while (opcao != 0);

	system("pause");
	return 0;
}

void cadastrarProduto(struct Produto produtos[], int *pos) {
	struct Produto novoProduto;

	char nome[DESC];
	do {
		printf("Digite o nome: ");
		fseek(stdin, 0, SEEK_END);
		gets(nome);

		if (strlen(nome) <= 0 || strlen(nome) > DESC) {
			printf("Nome maior do que o permitido!");
		}
		else {
			strcpy(novoProduto.descricao, nome);
		}

	} while (strlen(nome) <= 0 || strlen(nome) > DESC);

	printf("Digite o codigo: ");
	scanf_s("%d", &novoProduto.codigo);

	printf("Digite o valor unitario: ");
	scanf_s("%f", &novoProduto.valorUni);

	printf("Digite a quantidade em estoque: ");
	scanf_s("%d", &novoProduto.qntEstoque);

	produtos[*pos] = novoProduto;
	*pos = *pos + 1;

	printf("\nProduto cadastrado com sucesso!");
}

void alterarValorUnitario(struct Produto produtos[], int codigo, float newValue, int tam) {
	int posProduto = buscarPorCodigo(produtos, codigo, tam);

	if (posProduto < 0) {
		printf("Nao existe produto com o codigo informado!");
		return;
	}

	produtos[posProduto].valorUni = newValue;
	printf("Valor unitario alterado com sucesso!");
}

float buscarValorUnitario(struct Produto produtos[], int codigo, int tam) {
	int posicao = buscarPorCodigo(produtos, codigo, tam);

	if (posicao < 0) {
		printf("Nao existe produto com o codigo informado!");
		return -1;
	}

	return produtos[posicao].valorUni;
}

int buscarQntEstoque(struct Produto produtos[], int codigo, int tam) {
	int posicao = buscarPorCodigo(produtos, codigo, tam);

	if (posicao < 0) {
		printf("Nao existe produto com o codigo informado!");
		return -1;
	}

	return produtos[posicao].qntEstoque;
}

void venda(struct Produto produtos[], int codigo, int qnt, int tam) {
	int pos = buscarPorCodigo(produtos, codigo, tam);

	if (pos < 0) {
		printf("Nao existe produto com o codigo informado!");
		return;
	}

	int estoProd = produtos[pos].qntEstoque;

	if (estoProd == 0) {
		printf("O produto nao possui estoque!");
		return;
	}

	if (qnt > estoProd) {
		printf("O produto nao possui estoque suficiente para a venda!");
		return;
	}

	if (qnt <= estoProd) {
		int opcao;
		printf("Voce deseja efetuar a venda? (1 - SIM, 0 - NAO) ");
		scanf_s("%d", &opcao);

		if (opcao == 1) {
			produtos[pos].qntEstoque -= qnt;
			float valorFinal = produtos[pos].valorUni * qnt;
			printf("O valor da venda eh de R$ %.2f", valorFinal);
		}
	}
}

void atualizarEstoque(struct Produto produtos[], int codigo, int newQntEsto, int tam) {
	int pos = buscarPorCodigo(produtos, codigo, tam);

	if (pos < 0) {
		printf("Nao existe produto com o codigo informado!");
		return;
	}

	produtos[pos].qntEstoque = newQntEsto;
	printf("Estoque atualizado!");
}

void exibirTodos(struct Produto produtos[], int ultimaPos) {
	if (ultimaPos == 0) {
		printf("Nao existem produtos cadastrados!");
		return;
	}

	int i;
	for(i = 0; i < ultimaPos; i++) {
		printf("Nome: %s, Codigo: %d\n", produtos[i].descricao, produtos[i].codigo);
	}
}

void exibirTodosEstoqueZero(struct Produto produtos[], int ultimaPos) {
	if (ultimaPos == 0) {
		printf("Nao existem produtos cadastrados!");
		return;
	}

	int i;
	for (i = 0; i < ultimaPos; i++) {
		if (produtos[i].qntEstoque == 0) {
			printf("Nome: %s, Codigo: %d\n", produtos[i].descricao, produtos[i].codigo);
		}
	}
}

int buscarPorCodigo(struct Produto produtos[], int codigo, int tam) {
	int retorno = -1;
	int i;
	for (i = 0; i < tam; i++) {
		if (produtos[i].codigo == codigo) {
			retorno = i;
			break;
		}
	}
	return retorno;
}