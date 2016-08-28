#include "Definicoes.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	ITEM itens[TAMANHO_MAXIMO];
	int fim;
	int inicio;
	int tamanho;//Correção, debugger de fila circular
}Fila;


Fila* criaFila();
int destroiFila(Fila* fila);
int filaVazia(Fila* fila);
int filaCheia(Fila* fila);
int addFila(ITEM item, Fila* fila);
int rmFila(Fila* fila, ITEM* item);
