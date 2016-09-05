#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"Definicoes.h"
#include"Sacola.h"


int main ( int argc, char *argv[] )
{
	int comando, valor;
	int n, i;
	int flag[ 3 ];//Bandeira que indica se é fila, pilha....
	int recebido;
	int lixo;
	//Argc = quantidade de parametros +1 (nome do programa)
	//Argv = parâmetros, começa no argv[1], pq o argv[0] é o nome do programa
	//EOF == -1
	FILE* arquivo;
	arquivo = fopen(argv[1], "r"); //Abre arquivo passado como parâtro como somente leitura

	if(arquivo == NULL)//Tratamento de erros pra abertura de arquivo
	{
		return NAO_FOI_POSSIVEL_ABRIR_ARQUIVO;
	}

	while(!feof(arquivo))
	{
		fscanf(arquivo, "%d %d\n", &lixo, &lixo);//só pra contar o tanto de linhas que esse arquivo tem
		n++;
	}

	if(!(n >=0 && n<=1000))//Se não cumprir a condição de ser um numero entre 0 e 1000 (está no exercício), envia sinal de erro
	{
		fclose(arquivo);
		return ARGUMENTO_INVALIDO;
	}

//Fecha o arquivo e abre novamente pra apontar pro inicio do arquivo
	fclose(arquivo);
	arquivo = fopen(argv[1], "r");


	Sacola sacola;

	memset ( flag, 0, sizeof( flag ) );//Copia o caracter 0 para as posições de flag

	sacola.comeco_fila = 0;
	sacola.final_fila = 0;
	sacola.indice_pilha = 0;
	sacola.indice_lista_prioridade = 0;

	for ( i=0; i<(n); i++ ) 
	{
		fscanf(arquivo, "%d %d\n", &comando, &valor );//EDITAR AQUI
		if ( comando == 1 ) 
		{
			insere_fila ( valor, &sacola );
			insere_pilha ( valor, &sacola );
			insere_lista_prioridade ( valor, &sacola );
		}

		else
		{
			recebido = remove_fila ( &sacola );
			if ( recebido != valor ) 
			{
				flag[0] = 1;
			}
			recebido = remove_pilha ( &sacola );
			if ( recebido != valor ) 
			{
				flag[1] = 1;
			}
			recebido = remove_lista_prioridade ( &sacola );
			if ( recebido != valor ) 
			{
				flag[2] = 1;
			}
		}
	}

	if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] == 3 )
	{
		return IMPOSSIVEL;
	}
	else
	{
		if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] < 2 )
		{
			return INCERTO;
		}
		else
		{
			if ( !flag[0] ) return FILA;
			if ( !flag[1] ) return PILHA;
			if ( !flag[2] ) return FILA_DE_PRIORIDADES;
		}
	}
	return 0;
}
