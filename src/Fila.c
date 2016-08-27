#include"Fila.h"

Fila* criaFila()
{
	Fila* fila = malloc(sizeof*(fila));
	if(fila == NULL)
	{
		return NULL;//quando dá erro na criação
	}
	fila->fim = 0;
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
	if(fila->fim!= fila->inicio)
	{
		return false;
	}
	else return true;
}

//SEM ERROS ATÉ AQUI

int filaCheia(Fila* fila)
{
	if(fila == NULL)
	{
		return ESTRUTURA_NAO_INICIALIZADA;
	}
	if(fila->fim > fila->inicio)
	{
		if(fila->fim - fila->inicio >= TAMANHO_MAXIMO )
		{
			return true;
		}
		else return false;
	}
	else if(TAMANHO_MAXIMO-(fila->inicio - fila->fim) == TAMANHO_MAXIMO -1)
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
	if( fila->fim+1 > TAMANHO_MAXIMO)
	{
		fila->fim = 0;
	}
	else
	{
		fila->fim++;
	}
	return OK;
}
