CC=gcc
FONTE=src/Inicio.c
EXE=executavel
PILHA=src/Pilha.c
OBJ=Inicio.o Pilha.o
WARNINGS=-Wunused-variable
INICIO=src/Interface/Inicio.java
CC_JAVA=javac

all: interface
	$(CC) -c $(FONTE) $(PILHA)
	$(CC) -o $(EXE) $(WARNINGS) $(OBJ)
	rm $(OBJ)

interface:
	$(CC_JAVA) $(INICIO)
	mv src/Interface/Inicio.class

run:
	java Inicio
