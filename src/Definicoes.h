#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ARGUMENTO_INVALIDO 4
#define true 1
#define false 0
#define OK 0

#define NAO_FOI_POSSIVEL_ABRIR_ARQUIVO 10
#define FILA 5
#define PILHA 6
#define FILA_DE_PRIORIDADES 7
#define IMPOSSIVEL 8
#define INCERTO 9

#ifdef __WIN32
#define CLEAR system("cls");
#define LIMPABUFFER fflush(stdin);
#elif __linux
#define CLEAR system("clear");
#define LIMPABUFFER __fpurge(stdin);
#endif

