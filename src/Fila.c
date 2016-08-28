#include"Fila.h"

Fila* criaFila()
{
	Fila* fila = malloc(sizeof*(fila));
	if(fila == NULL)
	{
		return NULL;//quando dá erro na criação
	}
	fila->fim = 0;
	fila->tamanho = 0;
	fila->inicio = 0;
	return fila;
}


int destroiFila(Fila* fila)
{
	if(fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	free(fila);
	fila = NULL;
	return OK;
}


int filaVazia(Fila* fila)
{
	if(fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(fila->tamanho== 0)
	{
		return true;
	}
	return false;
}


int filaCheia(Fila* fila) 
{
	if(fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(fila->tamanho == TAMANHO_MAXIMO)
	{
		return true;
	}
	return false;
}


int addFila(ITEM item, Fila* fila)
{
	if( fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(filaCheia(fila))
	{
		return ESTRUTURA_CHEIA;
	}
	fila->itens[fila->fim] = item;
	if( fila->fim+1 >= TAMANHO_MAXIMO)
	{
		fila->fim = 0;
	}
	else
	{
		fila->fim++;
	}
	fila->tamanho++;
	return OK;
}

//SEM ERROS ATÉ AQUI

int rmFila(Fila* fila, ITEM* item)
{
	if(fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(filaVazia(fila))
	{
		return ESTRUTURA_VAZIA;
	}
	*item = fila->itens[fila->inicio];
	fila->inicio++;
	if(fila->inicio >= TAMANHO_MAXIMO)
	{
		fila->inicio = 0;
	}
	fila->tamanho=0;
	return OK;
}
