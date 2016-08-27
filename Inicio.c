#include"Definicoes.h"

void main()
{
	int num;
	int i;
	int *variavel;
	int operacao;
	printf("Digite o numero de operações \n");
	scanf("%d", &num);
	variavel = (int *) malloc(sizeof(int) * num);
	for(i = 0; i<num; i++)
	{
		printf("Digite a operação (1 = inserção, 2 = remoção)\n");
		scanf("%d", &operacao);
		printf("Digite o elemento a ser inserido/removido\n");
		scanf("%d", &variavel[num]);
		if(operacao == 1)
		{
			printf("Isso foi uma inserção\n");
		}
		else if(operacao == 2)
		{
			printf(" Isso foi uma remoção\n");
		}
		else
		{
			printf("Operação não suportada\n");
		}
	}
	if(variavel != NULL)
	{
		free(variavel);
		variavel = NULL;
	}
}
