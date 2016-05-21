#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define REG 100
#define TAM_NOME 50
#define TAM_CPF 12
#define TAM_TELE 11

struct Conta {
	int numero;
	char nome[TAM_NOME];
	char cpf[TAM_CPF];
	char telefone[TAM_TELE];
	float saldo;
};

int buscaConta(struct Conta contas[], int tam, int numero);
void cadastrar(struct Conta contas[], int tam, int numero);
void consultarSaldo(struct Conta contas[], int tam, int numero);
void depositar(struct Conta contas[], int tam, int numero);
void sacar(struct Conta contas[], int tam, int numero);
void imprimirTodas(struct Conta contas[], int tam);

int main() {
	struct Conta contasCorrentes[REG];
	struct Conta contasPoupancas[REG];

	int opcao;

	do {
		printf("Menu\n");
		printf("1) Cadastrar conta\n");
		printf("2) Consultar saldo\n");
		printf("3) Depositar\n");
		printf("4) Sacar\n");
		printf("5) Exibir todas as contas\n");

		printf("\nDigite uma opcao: ");
		scanf_s("%d", &opcao);

		printf("\n-----------------------------------------------------\n");
		switch (opcao) {


		case 1: {
			int tipoConta;
			do {
				printf("Conta Corrente (1) ou Conta Poupanca (2): ");
				scanf_s("%d", &tipoConta);
			} while (tipoConta != 1 && tipoConta != 2);

			int numeroNova;
			do {
				printf("Digite o numero da nova conta: ");
				scanf_s("%d", &numeroNova);
				if (numeroNova < 0) {
					printf("O numero da conta nao pode ser negativo!\n");
				}
			} while (numeroNova < 0);

			if (tipoConta == 1) {
				cadastrar(contasCorrentes, REG, numeroNova);
			}
			else if (tipoConta == 2) {
				cadastrar(contasPoupancas, REG, numeroNova);
			}
			break;
		}


		case 2: {
			int tipoConta;
			do {
				printf("Conta Corrente (1) ou Conta Poupanca (2): ");
				scanf_s("%d", &tipoConta);
			} while (tipoConta != 1 && tipoConta != 2);


			int numero;
			do {
				printf("Digite o numero da conta: ");
				scanf_s("%d", &numero);
				if (numero < 0) {
					printf("O numero da conta nao pode ser negativo!\n");
				}
			} while (numero < 0);

			if (tipoConta == 1) {
				consultarSaldo(contasCorrentes, REG, numero);
			}
			else if (tipoConta == 2) {
				consultarSaldo(contasPoupancas, REG, numero);
			}
			break;
		}

		case 3: {
			int tipoConta;
			do {
				printf("Conta Corrente (1) ou Conta Poupanca (2): ");
				scanf_s("%d", &tipoConta);
			} while (tipoConta != 1 && tipoConta != 2);


			int numero;
			do {
				printf("Digite o numero da conta: ");
				scanf_s("%d", &numero);
				if (numero < 0) {
					printf("O numero da conta nao pode ser negativo!\n");
				}
			} while (numero < 0);

			if (tipoConta == 1) {
				depositar(contasCorrentes, REG, numero);
			}
			else if (tipoConta == 2) {
				depositar(contasPoupancas, REG, numero);
			}
			break;
		}

		case 4: {
			int tipoConta;
			do {
				printf("Conta Corrente (1) ou Conta Poupanca (2): ");
				scanf_s("%d", &tipoConta);
			} while (tipoConta != 1 && tipoConta != 2);


			int numero;
			do {
				printf("Digite o numero da conta: ");
				scanf_s("%d", &numero);
				if (numero < 0) {
					printf("O numero da conta nao pode ser negativo!\n");
				}
			} while (numero < 0);

			if (tipoConta == 1) {
				sacar(contasCorrentes, REG, numero);
			}
			else if (tipoConta == 2) {
				sacar(contasPoupancas, REG, numero);
			}
			break;
		}

		case 5: {
			int tipoConta;
			do {
				printf("Conta Corrente (1) ou Conta Poupanca (2): ");
				scanf_s("%d", &tipoConta);
			} while (tipoConta != 1 && tipoConta != 2);

			if (tipoConta == 1) {
				imprimirTodas(contasCorrentes, REG);
			}
			else if (tipoConta == 2) {
				imprimirTodas(contasPoupancas, REG);
			}
			break;
		}
		default: printf("Adeus."); break;
		}
		printf("\n-----------------------------------------------------\n");
	} while (opcao != 0);
	
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
		} else if (i == tam - 1) {
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

	char nome[TAM_NOME];
	do {
		printf("Digite o nome do titular: ");
		fseek(stdin, 0, SEEK_END);
		gets(nome);

		if (strlen(nome) <= 0 || strlen(nome) > TAM_NOME) {
			printf("O nome precisa ter no maximo %d caracteres.\n", TAM_NOME);
		} else {
			strcpy(novaConta.nome, nome);
		}
	} while (strlen(nome) <= 0 || strlen(nome) > TAM_NOME);


	char telefone[TAM_NOME];
	do {
		printf("Digite o telefone do titular: ");
		fseek(stdin, 0, SEEK_END);
		gets(telefone);

		if (strlen(telefone) <= 0 || strlen(telefone) > TAM_TELE) {
			printf("O telefone precisa ter no maximo %d caracteres.\n", TAM_TELE);
		}
		else {
			strcpy(novaConta.telefone, telefone);
		}
	} while (strlen(telefone) <= 0 || strlen(telefone) > TAM_TELE);

	char cpf[TAM_CPF];
	do {
		printf("Digite o CPF do titular: ");
		fseek(stdin, 0, SEEK_END);
		gets(cpf);

		if (strlen(cpf) <= 0 || strlen(cpf) > TAM_CPF) {
			printf("O CPF precisa ter no maximo %d caracteres.\n", TAM_CPF);
		}
		else {
			strcpy(novaConta.cpf, cpf);
		}
	} while (strlen(cpf) <= 0 || strlen(cpf) > TAM_CPF);


	do {
		printf("Digite o saldo inicial: ");
		scanf_s("%f", &novaConta.saldo);
		
		if (novaConta.saldo < 0) {
			printf("O saldo precisa ser, no minimo, R$ 0.00.\n");
		}
	} while (novaConta.saldo < 0);

	int i;
	for (i = 0; i < tam; i++) {
		if (contas[i].numero < 0) {
			contas[i] = novaConta;
			break;
		}
	}

	printf("Conta cadastrada com sucesso!");
}

void consultarSaldo(struct Conta contas[], int tam, int numero) {
	int pos = buscaConta(contas, tam, numero);

	if (pos < 0) {
		printf("A conta nao esta cadastrada!");
		return;
	}

	printf("O saldo da conta eh de R$ %.2f", contas[pos].saldo);
}

void depositar(struct Conta contas[], int tam, int numero) {
	int pos = buscaConta(contas, tam, numero);

	if (pos < 0) {
		printf("A conta nao esta cadastrada!");
		return;
	}
	
	float valorDeposito;
	do {
		printf("Digite o valor do reposito (R$): ");
		scanf_s("%f", &valorDeposito);

		if (valorDeposito <= 0) {
			printf("O valor do deposito precisa ser maior do que R$ 0.00.\n");
		}
		else {
			contas[pos].saldo += valorDeposito;
			printf("Deposito efetuado!");
		}

	} while (valorDeposito <= 0);

}

void sacar(struct Conta contas[], int tam, int numero) {
	int pos = buscaConta(contas, tam, numero);

	if (pos < 0) {
		printf("A conta nao esta cadastrada!");
		return;
	}

	float valorSaque;
	do {
		printf("Digite o valor para sacar (R$): ");
		scanf_s("%f", &valorSaque);

		if (valorSaque <= 0) {
			printf("O valor do saque precisa ser maior do que R$ 0.00.\n");
		}
		else {
			if (contas[pos].saldo < valorSaque) {
				printf("A conta nao possui saldo suficiente para este valor!");
			}
			else {
				contas[pos].saldo -= valorSaque;
				printf("Saque efetuado!");
			}
		}
	} while (valorSaque <= 0);

}

void imprimirTodas(struct Conta contas[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		if (contas[i].numero >= 0) {
			printf("Numero da conta: %d\n", contas[i].numero);
			printf("Nome do titular: %s\n", contas[i].nome);
			printf("Telefone de contato: %s\n", contas[i].telefone);
			printf("\n");
		} else {
			break;
		}
	}
}