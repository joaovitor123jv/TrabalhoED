#include "Definicoes.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	ITEM itens[TAMANHO_MAXIMO];
	int topo;
}Pilha;

//typedef (struct Pilha) Pilha;

Pilha* criaPilha();//Cria uma nova Pilha
int destroiPilha(Pilha* pilha);//Libera memória
int pilhaVazia(Pilha* pilha); //Checa se pilha está vazia
int pilhaCheia(Pilha* pilha);//Checa se pilha está cheia
int empilha(ITEM item, Pilha* pilha);//Adiciona um item à pilha
int desempilha(Pilha* pilha, ITEM *item);//Retira item da pilha e coloca em item

//Funções Opcionais
//int getUltimo(Pilha* pilha, ITEM item);
int mostraPilha(Pilha* pilha ); //Só funciona pra inteiros
