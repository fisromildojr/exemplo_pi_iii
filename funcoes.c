#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

#include "funcoes.h"

// Menu do Sistema
int menuPrincipal()
{
    int op;
    system("cls");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx       SISTEMA       xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx CONTROLE DE PRODUTO xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                     xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n");

    printf("          Digite as uma das opções abaixo para prosseguir no sistema\n\n\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Listar Produtos Cadastrados\n");
    printf("3 - Sair\n");

    printf("\n--> ");
    scanf("%i", &op);
    setbuf(stdin, NULL);

    return op;
}

// Funcao de inserir produto
void inserirProduto()
{
    Produto produto;
    int i, op;
    char nome[100];
    char strValor[10];
    char sql[500];
    float valor;

    do
    {
        MYSQL *conexao = conectar();

        system("cls");
        printf("<<< CADASTRO DE PRODUTO >>>\n\n");
        printf("Nome: ");
        fgets(nome, 100, stdin);
        nome[strlen(nome) - 1] = '\0';
        for (i = 0; nome[i]; i++)
            nome[i] = toupper(nome[i]);
        strcpy(produto.nome, nome);

        printf("Valor: ");
        fgets(strValor, 15, stdin);
        strValor[strlen(strValor) - 1] = '\0';
        valor = strtof(strValor, NULL);
        produto.valor = valor;

        strcpy(sql, "INSERT INTO produto VALUES(null,'");
        strcat(sql, produto.nome);
        strcat(sql, "','");
        sprintf(strValor, "%.2f", produto.valor);
        strcat(sql, strValor);
        strcat(sql, "');");
        
        printf("SQL Gerado => %s", sql);

        system("cls");

        mysql_query(conexao, sql);

        if (mysql_affected_rows(conexao) != 1)
        {
            printf("\nErro: Nao foi possivel cadastrar o produto\n\n");
            printf("Pressione qualquer tecla para continuar...\n");
            mysql_close(conexao);
            getchar();
        }
        else
        {
            printf("\nProduto cadastrado com sucesso!!!\n\n");
            printf("1 - Cadastrar outro produto\n");
            printf("2 - Voltar\n");
            
            scanf("%i", &op);
            setbuf(stdin, NULL);
            mysql_close(conexao);
        }

        if (op != 1)
        {
            break;
        }

    } while (op == 1);
}

 void listarProdutos(){
	 MYSQL *conexao = conectar();
	 MYSQL_RES *resp;
     MYSQL_ROW linhas;
     MYSQL_FIELD *campos;

     Produto produto;

     char sql[500];
     int i, op=0;

     do{
         strcpy(sql, "SELECT produto.id as CODIGO, produto.nome as NOME, produto.valor as VALOR FROM produto;");
         mysql_query(conexao, sql);

         resp = mysql_store_result(conexao);

         if(resp){
             system("cls");
             printf("<<< PRODUTOS CADASTRADOS >>>\n\n");

             printf("CODIGO\t\t\t\tNOME\t\t\t\tVALOR\n");
             campos = mysql_fetch_fields(resp);

                 printf("\n");

                 while ((linhas=mysql_fetch_row(resp)) != NULL)
                   {
                      for (i=0;i<mysql_num_fields(resp);i++)
                         if(linhas[i]==NULL)
                             printf("\t\t\t\t");
                         else
                             printf("%s\t\t\t\t",linhas[i]);
                      printf("\n");
                   }
                printf("\n\n\n###########################################################################\n");
                        printf("1 - Voltar\t\t\t2 - Editar\t\t\t3 - Excluir\n");
                        scanf("%i", &op);
                        setbuf(stdin,NULL);     
         }else{
        	 system("cls");
             printf("A consulta nao retornou nenhum resultado...\n\n\n");
             printf("1 - Voltar\n");
             printf("4 - Tentar Novamente\n");
             scanf("%i", &op);
             setbuf(stdin,NULL);
         }

         if (op==1){
         	mysql_close(conexao);
             break;
         }
     }while(op==4);
 }
