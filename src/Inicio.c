#include"Definicoes.h"
#include"Pilha.h"
#include"Fila.h"

void main()
{
	int num;
	int i;
	int *variavel;
	int operacao;

	int dbg;
	Pilha* pilha = criaPilha();
	Fila* fila = criaFila();
	fila->inicio = 0;
	fila->fim = 0;
	system("clear");

	printf("TAMANHO MAXIMO = %d\n", TAMANHO_MAXIMO);
	printf("Digite o numero de operações \n");
	scanf("%d", &num);
	variavel = (int *) malloc(sizeof(int) * num);
	for(i = 0; i<num; i++)
	{
		printf("Digite a operação (1 = inserção, 2 = remoção)\n");
		scanf("%d", &operacao);
		printf("Digite o elemento a ser inserido/removido\n");
		scanf("%d", &variavel[i]);
		if(operacao == 1)
		{
			printf("Isso foi uma inserção\n");

			dbg = empilha(variavel[i], pilha);
			if(dbg == ESTRUTURA_CHEIA)
			{
				printf("\t\tEstrutura Cheia Detectada\t[PILHA]\n");
			}
			dbg = addFila(variavel[i], fila);
			printf("\t\t\t\t\t\t\t\t\t\tFIM  %d      INICIO   %d\n\n", fila->fim, fila->inicio);
			if(dbg == ESTRUTURA_CHEIA)
			{
				printf("\t\tEstrutura Cheia Detectada\t[FILA]\n");
			}
			printf("empilhado : %d\n", variavel[i]);
		}
		else if(operacao == 2)
		{
			printf(" Isso foi uma remoção\n");
			//DEBUGGER
			dbg = desempilha( pilha, &variavel[i]);
			if(dbg == ESTRUTURA_VAZIA)
			{
				printf("\t\tEstrutura Cheia Detectada\t[PILHA]\n");
			}
			dbg = rmFila(fila, &variavel[i]);
			printf("\t\t\t\t\t\t\t\t\t\tFIM  %d      INICIO   %d\n\n", fila->fim, fila->inicio);
			if(dbg == ESTRUTURA_VAZIA)
			{
				printf("\t\tEstrutura Cheia Detectada\t[FILA]\n");
			}
			printf("empilhado : %d\n", variavel[i]);
		}
		else
		{
			printf("Operação não suportada\n");
		}
	}
	mostraPilha(pilha);

	destroiFila(fila);
	destroiPilha(pilha);
	if(variavel != NULL)
	{
		free(variavel);
		variavel = NULL;
	}
}
