#include "Definicoes.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	ITEM itens[TAMANHO_MAXIMO];
	int fim;
	int inicio;
}Fila;


Fila* criaFila();
int destroiFila(Fila* fila);
int filaVazia(Fila* fila);
int filaCheia(Fila* fila);
