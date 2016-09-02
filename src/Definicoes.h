#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_CHEIA -2
#define ESTRUTURA_VAZIA -3
#define ARGUMENTO_INVALIDO -4
#define true 1
#define false 0
#define OK 0

#define NAO_FOI_POSSIVEL_ABRIR_ARQUIVO -10
#define FILA 5
#define PILHA 6
#define LISTA 7
#define IMPOSSIVEL 8
#define INCERTO 9

#ifdef __WIN32
#define CLEAR system("cls");
#define LIMPABUFFER fflush(stdin);
#elif __linux
#define CLEAR system("clear");
#define LIMPABUFFER __fpurge(stdin);
#endif

#define TAMANHO_MAXIMO 10 //tamanho maximo das estruturas
#define ITEM int // define o tipo de variável das estruturas
