#include"Pilha.h"

Pilha* criaPilha()
{
	Pilha* pilha = malloc(sizeof(*pilha));
	if(pilha == NULL)
	{
		return NULL;
	}
	pilha->topo = 0;
	return pilha;
}

int destroiPilha(Pilha* pilha)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;//se pilha nao existir
	}
	free(pilha);//Libera memória
	pilha = NULL;//Tratamento de erros (impede roubo de dados em buffer)
	return OK;
}
