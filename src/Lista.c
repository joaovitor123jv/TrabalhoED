#include<stdio.h>
#include<stdlib.h>

#include"Lista.h"

Lista* criaLista() {
    Lista* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->ultimo = 0;
    return lista;
}

int liberaLista(Lista* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    free(lista);
    lista = NULL;
    return OK;
}

int listaCheia(Lista* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->ultimo == TAM_MAX)
        return true;
    return false;
}

int listaVazia(Lista* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->ultimo == 0)
        return true;
    return false;
}

int verificaIndice(Lista* lista, int pos, int incluiUltimo) {
    if (pos < 0)
        return false;
    if ((incluiUltimo) && (pos > lista->ultimo))
        return false;
    if ((!incluiUltimo) && (pos >= lista->ultimo))
        return false;
    return true;
}

int addLista(Lista* lista, int item, int pos) {
   int aux;
	int i;
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (listaCheia(lista))
        return ESTRUTURA_CHEIA;
    if (!verificaIndice(lista, pos, true))
        return INDICE_INVALIDO;

    // Desloca elementos para a direita.
    for(i = lista->ultimo; i > pos; i--)  {
        lista->itens[i] = lista->itens[i - 1];
    }
    lista->itens[pos] = item;
    lista->ultimo++;
    getTamanho(lista,&aux);
    InsertionSort(lista->itens,aux);
    return OK;
}

int rmLista(Lista* lista, int* item, int pos) {
	int i;
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (listaVazia(lista))
        return ESTRUTURA_VAZIA;
    if (!verificaIndice(lista, pos, false))
        return INDICE_INVALIDO;

    if (item != NULL)
        *item = lista->itens[pos];

    // Desloca elementos para a esquerda.
    for( i = pos; i < (lista->ultimo - 1); i++)  {
        lista->itens[i] = lista->itens[i + 1];
    }
    lista->ultimo--;
    return OK;
}

int getElemento(Lista* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (listaVazia(lista))
        return ESTRUTURA_VAZIA;
    if (!verificaIndice(lista, pos, false))
        return INDICE_INVALIDO;
    if (item == NULL)
        return PARAMETRO_INVALIDO;
    *item = lista->itens[pos];
    return OK;
}

int getTamanho(Lista* lista, int* tam) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;
    *tam = lista->ultimo;
    return OK;
}
int InsertionSort(int original[], int length)
{
	int i, j, atual;

	for (i = 1; i < length; i++)
	{
		atual = original[i];
		j = i - 1;

		while ((j >= 0) && (atual > original[j]))
		{
			original[j + 1] = original[j];
            j = j - 1;
		}

		original[j + 1] = atual;
	}

	return 0;
}
