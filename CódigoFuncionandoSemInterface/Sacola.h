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

void insere_fila ( int valor, Sacola *sacola )
{
	sacola->elemento_fila[ sacola->final_fila++ ] = valor;
} 

int remove_fila ( Sacola* sacola ) 
{
	if ( sacola->comeco_fila == sacola->final_fila ) 
	{
		return -10000000;
	}
	return sacola->elemento_fila[ sacola->comeco_fila++ ];
}

void insere_pilha ( int valor, Sacola *sacola ){
	sacola->elemento_pilha[ ++sacola->indice_pilha ] = valor;
}

int remove_pilha ( Sacola *sacola ){
	if ( sacola->indice_pilha <= 0 ) {
		return  -10000000;
	}
	return sacola->elemento_pilha[ sacola->indice_pilha-- ];
}

void insere_lista_prioridade ( int valor, Sacola *sacola ){
	int indexador_auxiliar;
	indexador_auxiliar = ++sacola->indice_lista_prioridade;
	while ( indexador_auxiliar > 1 ) 
	{
		if ( sacola->elemento_lista_prioridade[ indexador_auxiliar/2 ] < valor ) 
		{
			sacola->elemento_lista_prioridade[ indexador_auxiliar ] = sacola->elemento_lista_prioridade[ indexador_auxiliar/2 ];
			indexador_auxiliar=indexador_auxiliar/2;
		} 
		else
		{
			break;
		}
	}
	sacola->elemento_lista_prioridade[ indexador_auxiliar ] = valor;
}

int remove_lista_prioridade ( Sacola *sacola )
{
	int temporario, atual, proximo;
	if ( sacola->indice_lista_prioridade <= 0 ) 
	{
		return  -10000000;
	}

	temporario = sacola->elemento_lista_prioridade[ 1 ];
	atual = 1;
	proximo = 2;
	sacola->indice_lista_prioridade--;
	while ( proximo <= sacola->indice_lista_prioridade )
	{
		if ( proximo < sacola->indice_lista_prioridade && sacola->elemento_lista_prioridade[ proximo+1 ] > sacola->elemento_lista_prioridade[ proximo ] ) 
		{
			proximo++;
		}
		if( sacola->elemento_lista_prioridade[ proximo ] > sacola->elemento_lista_prioridade[ sacola->indice_lista_prioridade+1 ] ) 
		{
			sacola->elemento_lista_prioridade[ atual ] = sacola->elemento_lista_prioridade[ proximo ];
			atual = proximo;
			proximo = atual*2;
		}
		else
		{
			break;
		}
	}
	sacola->elemento_lista_prioridade[ atual ] = sacola->elemento_lista_prioridade[ sacola->indice_lista_prioridade+1 ];
	return temporario;
}

