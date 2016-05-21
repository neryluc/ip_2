#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define REG 100
#define TAM_NOME 50
#define TAM_CPF 11
#define TAM_TELE 10

struct Conta {
	int numero;
	char nome[TAM_NOME];
	char cpf[TAM_CPF];
	char telefone[TAM_TELE];
	float saldo;
};

int buscaConta(struct Conta contas[], int tam, int numero);
void cadastrar(struct Conta contas[], int tam, int numero);

int main() {
	struct Conta contasCorrentes[REG];
	struct Conta contasPoupancas[REG];

	cadastrar(contasCorrentes, REG, 123);

	system("pause");
	return 0;
}

int buscaConta(struct Conta contas[], int tam, int numero) {
	if (contas[0].numero < 0) {
		return -1;
	}

	int pos, i;
	for (i = 0; i < tam; i++) {
		if (contas[i].numero == numero) {
			pos = i;
			break;
		} else if (i = tam - 1) {
			pos = -2;
		}
	}

	return pos;
}

void cadastrar(struct Conta contas[], int tam, int numero) {
	if (contas[tam - 1].numero >= 0) {
		printf("O cadastro de contas esta lotado!");
		return;
	}

	struct Conta novaConta;
	novaConta.numero = numero;

	// TODO preencher outros campos da conta

	int i;
	for (i = 0; i < tam; i++) {
		if (contas[i].numero < 0) {
			contas[i] = novaConta;
			break;
		}
	}

	printf("Conta cadastrada com sucesso!");
}