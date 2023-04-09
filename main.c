#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

#include "conexao.c"
#include "funcoes.c"

int main()
{
	int opcao;
    do{
                opcao = menuPrincipal();

                switch(opcao){
                    case 1:
                        inserirProduto();
                    break;
                    case 2:
                        listarProdutos();   
                    break;
                    case 3:
                        return 0;
                    break;
                    default:
                        printf("Opcao invalida...\n");
                    break;
                }
            
            }while(1);
            return 0;
}
