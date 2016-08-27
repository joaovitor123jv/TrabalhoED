#include"Definicoes.h"
#include"Pilha.h"

void main()
{
	int num;
	int i;
	int *variavel;
	int operacao;
	Pilha* pilha = criaPilha();
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
			empilha(variavel[i], pilha);
			printf("empilhado : %d\n", variavel[i]);
		}
		else if(operacao == 2)
		{
			printf(" Isso foi uma remoção\n");
			desempilha(pilha, &variavel[i]);
			printf("Obtido -> %d\n", variavel[i]);
		}
		else
		{
			printf("Operação não suportada\n");
		}
	}
	mostraPilha(pilha);
	destroiPilha(pilha);
	if(variavel != NULL)
	{
		free(variavel);
		variavel = NULL;
	}
}
