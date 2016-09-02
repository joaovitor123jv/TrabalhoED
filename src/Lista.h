#include"Definicoes.h"

#ifndef LISTA
#define LISTA
#endif

#ifndef TAM_MAX
#define TAM_MAX 100 // quantidade máxima de elementos suportada
#endif


#ifndef INDICE_INVALIDO
#define INDICE_INVALIDO -4
#endif

#ifndef PARAMETRO_INVALIDO
#define PARAMETRO_INVALIDO -5
#endif

// declaração da estrutura de uma lista.

struct Lista{
	int itens[TAM_MAX];
	int ultimo;
};
typedef struct Lista Lista;

Lista* criaLista();
int liberaLista(Lista* lista);
int listaVazia(Lista* lista);
int listaCheia(Lista* lista);
int addLista(Lista* lista, int item, int pos);
int rmLista(Lista* lista, int* item, int pos);
int getElemento(Lista* lista, int* item, int pos);
int getTamanho(Lista* lista, int* tam);

