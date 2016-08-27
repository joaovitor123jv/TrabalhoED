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


int pilhaVazia(Pilha* pilha)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(pilha->topo == 0)//pilha vazia
	{
		return true;
	}
	return false;//caso pilha nao esteja vazia
}

int pilhaCheia(Pilha* pilha)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(pilha->topo == TAMANHO_MAXIMO)//pilha cheia
	{
		return true;
	}
	return false;//caso pilha nao esteja cheia
}


int empilha(ITEM item, Pilha* pilha)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(pilhaCheia(pilha))
	{
		return ESTRUTURA_CHEIA;
	}
	pilha->itens[pilha->topo] = item;
	pilha->topo++;
	return OK;
}


int desempilha(Pilha* pilha, ITEM *item)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(pilhaVazia(pilha))
	{
		return ESTRUTURA_VAZIA;
	}
	*item = pilha->itens[pilha->topo-1];//Se item == NULL, joga item no lixo, senao joga topo no item
	pilha->topo--;
	return OK;
}


int getUltimo(Pilha* pilha, ITEM* item)
{
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(pilhaVazia(pilha))
	{
		return ESTRUTURA_VAZIA;
	}
	*item = pilha->itens[pilha->topo-1];
	return OK;
}


int mostraPilha(Pilha* pilha)
{
	Pilha* pAux = criaPilha();
	ITEM item;
	if(pilha == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	printf("\n [ ");
	while(!pilhaVazia(pilha))
	{
		desempilha(pilha, &item);
		printf("%d, ", item);
		empilha(item, pAux);
	}
	printf("] \n");

	while(!pilhaVazia(pAux))
	{
		desempilha(pAux, &item);
		empilha(item, pilha);
	}
	destroiPilha(pAux);
}
