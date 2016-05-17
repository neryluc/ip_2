#include <stdio.h>
#include <stdlib.h>

#define TAM_REG 100

// Definicao das estruturas

struct ContaCorrente{
	int numero;
	char nome[50];
	char cpf[11];
	char telefone[10];
	float saldo;
};

struct ContaPoupanca{
	int numero;
	char nome[50];
	char cpf[11];
	char telefone[10];
	float saldo;
};

// Prototipos das funcoes e procedimentos
int buscarContaCorrente(struct ContaCorrente cadastro[], int tam, int numero);
int buscarContaPoupanca(struct ContaPoupanca cadastro[], int tam, int numero);
void cadastrarContaCorrente(struct ContaCorrente cadastro[], int numero);
void cadastrarContaPoupanca(struct ContaPoupanca cadastro[], int numero);
void saldoContaCorrente(struct ContaCorrente cadastro[], int numero);
void saldoContaPoupanca(struct ContaPoupanca cadastro[], int numero);

int main(){
	struct ContaCorrente cadastroContaCorrente[TAM_REG];
	struct ContaPoupanca cadastrarContaPoupanca[TAM_REG];

	int opcao;
	system("clear");

	do{
		printf("************** MENU **************\n");
		printf("\n######## CONTA CORRENTE ########\n");
		printf("## 1 - Cadastrar\n");
		printf("## 2 - Saldo\n");
		printf("\n######## CONTA POUPANCA ########\n");
		printf("## 3 - Cadastrar\n");
		printf("## 4 - Saldo\n");
		printf("\n**********************************\n");

		printf("\nEscolha uma opcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
		}

	}while(opcao != 0);

	getchar();
	return 0;
} 

