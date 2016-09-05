#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Sacola {

	int elemento_fila[1000];
	int comeco_fila, final_fila;

	int elemento_pilha[1000];
	int indice_pilha;

	int elemento_lista_prioridade[1000];
	int indice_lista_prioridade;

} Sacola;

void insere_fila(int, Sacola*);
int remove_fila(Sacola*);//retorna o item
void insere_pilha(int, Sacola*);
int remove_pilha(Sacola*);
void insere_lista_prioridade(int, Sacola*);
int remove_lista_prioridade(Sacola*);
