#pragma once
#include<stdio.h>
#include<stdlib.h>

struct Pilha
{
	ITEM itens[TAMANHO_MAXIMO];
	int topo;
};

typedef struct Pilha Pilha;

Pilha* criaPilha();
int destroiPilha(Pilha* pilha);

