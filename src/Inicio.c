#include"Definicoes.h"
#include"Pilha.h"
#include"Fila.h"
void sair(Pilha* pilha, Fila* fila, int* variavel);

int main(int argc, char *argv[])
{

	int num = 0;
	Pilha* pilha = criaPilha();
	Fila* fila = criaFila();
	FILE* arquivo;
	int i;
	int *variavel;
	int operacao;
	system("eject");
	printf("\nPrograma aberto \n");

	arquivo = fopen(argv[1], "r"); //Abre arquivo passado como parâtro como somente leitura

	if(arquivo == NULL)//Tratamento de erros pra abertura de arquivo
	{
		printf("Arquivo não existe\n");
		return NAO_FOI_POSSIVEL_ABRIR_ARQUIVO;
	}

	while(!feof(arquivo))
	{
		fscanf(arquivo, "%s\n", NULL);//só pra contar o tanto de linhas que esse arquivo tem
		num++;
	}

	if(!(num >=0 && num <=100))//Se não cumprir a condição de ser um numero entre 0 e 1000 (está no exercício), envia sinal de erro
	{
		fclose(arquivo);
		return ARGUMENTO_INVALIDO;
	}

//Fecha o arquivo e abre novamente pra apontar pro inicio do arquivo
	fclose(arquivo);
	arquivo = fopen(argv[1], "r");
	variavel = (int *) malloc(sizeof(int) * num);//Alocação dinâmica num vetor, pra otimizar e economizar memória (pode trabalhar como um vetor normal)

	for(i = 0; i<=num; i++)
	{
		fscanf(arquivo, "%d %d\n", &operacao, &variavel[i]);
		if(operacao == 1)//inserção
		{
			empilha(variavel[i], pilha);
			addFila(variavel[i], fila);
		}
		else if(operacao == 2)//remoção
		{
			desempilha(pilha, &variavel[i]);
			rmFila(fila, &variavel[i]);
		}
		else	//Tratamento de erros
		{
			return ARGUMENTO_INVALIDO;
		}
	}

	/*
	int num;
	int i;
	int *variavel;
	int operacao;

	Pilha* pilha = criaPilha();
	Fila* fila = criaFila();
	system("clear");
	printf("Digite o numero de operações \n");
	scanf("%d", &num);
	if(!(num >=0 && num <=100))//Se não cumprir a condição de ser um numero entre 0 e 1000 (está no exercício), envia sinal de erro
	{
		return ARGUMENTO_INVALIDO;
	}

	variavel = (int *) malloc(sizeof(int) * num);//Alocação dinâmica num vetor, pra otimizar e economizar memória (pode trabalhar como um vetor normal)

	for(i = 0; i<num; i++)
	{
		printf("Digite a operação (1 = inserção, 2 = remoção)\n");
		scanf("%d", &operacao);
		printf("Digite o elemento a ser inserido/removido\n");
		scanf("%d", &variavel[i]);
		if(operacao == 1)
		{
			empilha(variavel[i], pilha);
			addFila(variavel[i], fila);
		}
		else if(operacao == 2)
		{
			desempilha( pilha, &variavel[i]);
			rmFila(fila, &variavel[i]);
		}
		else
		{
			printf("Operação não suportada\n");
		}
	}
	sair(pilha, fila, variavel);//Tratamento de memory leak (vazamento de memória)
	return OK; //Retorna que foi "tudo bem"
	*/
}

void sair(Pilha* pilha, Fila* fila, int* variavel)
{
	destroiFila(fila);
	destroiPilha(pilha);
	if(variavel != NULL)
	{
		free(variavel);
		variavel = NULL;
	}
}
