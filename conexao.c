#include <mysql.h>
#include "conexao.h"


MYSQL *conectar()
{
    MYSQL *conexao = mysql_init(NULL);
    char *servidor = "localhost";
    char *usuario = "root";
    char *senha = "123456";
    char *banco = "pi_iii";
    if (!mysql_real_connect(conexao, servidor, usuario, senha, banco, 0, NULL, 0))
    {
        printf("Erro ao conectar com o banco de dados: %s\n", mysql_error(conexao));
        exit(1);
    }
    printf("Conexao realizada com sucesso!!!\n");
    return conexao;
}
