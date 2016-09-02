#include"Definicoes.h"
#ifndef LISTA
#define LISTA

#define TRUE 1
#define FALSE 0
#ifndef TAM_MAX
#define TAM_MAX 100 // quantidade máxima de elementos suportada
#endif


#define INDICE_INVALIDO -4
#define PARAMETRO_INVALIDO -5

// declaração da estrutura de uma lista.

struct Lista{
	int itens[TAM_MAX];
	int ultimo;
};
typedef struct Lista Lista;

Lista* criaLista();
int liberaLista(Lista* lista);
int listaVazia(Lista* lista);
int listaCheial(Lista* lista);
int addLista(Lista* lista, int item, int pos);
int rmLista(Lista* lista, int* item, int pos);
int getElemento(Lista* lista, int* item, int pos);
int getTamanho(Lista* lista, int* tam);

#endif
