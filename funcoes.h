#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

typedef struct Produto{
	int id;
	char nome[100];
	float valor;
} Produto;

int menuPrincipal();

void inserirProduto();

void listarProdutos();
